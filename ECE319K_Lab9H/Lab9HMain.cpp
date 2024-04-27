// Lab9HMain.cpp
// Runs on MSPM0G3507
// Lab 9 ECE319H
// Jonathan Simon, Hyunho Jeong
// Professor: Chiou
// EIDS: HJ8379, JES7539
// Last Modified: 04/13/2024
#include <stdio.h>
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "../inc/ST7735.h"
#include "../inc/Clock.h"
#include "../inc/LaunchPad.h"
#include "../inc/Timer.h"
#include "../inc/SlidePot.h"
#include "../inc/DAC5.h"
#include "../inc/JoyStick.h"
#include "SmallFont.h"
#include "LED.h"
#include "Switch.h"
#include "Sound.h"
#include "SpriteList.h"
#include "Image.h"
#include "config.h"
extern "C" void __disable_irq(void);
extern "C" void __enable_irq(void);
extern "C" void TIMG12_IRQHandler(void);

void PLL_Init(void){ // set phase lock loop (PLL)
    // Clock_Init40MHz(); // run this line for 40MHz
    Clock_Init80MHz(0);   // run this line for 80MHz
}

uint32_t M=1;
uint32_t Random32(void){
    M = 1664525*M+1013904223;
    return M;
}
uint32_t Random(uint32_t n){
    return (Random32()>>16)%n;
}

SlidePot Sensor(1995,-1); // copy calibration from Lab 7

SpriteList player;
SpriteList aliens;
SpriteList playerLasers;
SpriteList alienLasers;
BackgroundList backgrounds;
BackgroundList blackRectangles; // SpriteList.cpp uses this as extern

Input_Switch_Handler Switches;

int score = 0;
int shield = BASE_SHIELD_COUNT;

uint32_t ADC0_x;
uint32_t ADC0_y;
int joystick_x;
int joystick_y;
int32_t slidepot;
uint32_t button_inputs;
uint8_t prev_up, prev_down, prev_right, prev_left = 0;

bool refresh = false;
bool refresh_menu, refresh_score = false;

#define MENU_SCREEN_ID  0
#define PLAY_SCREEN_ID  1
#define SCORE_SCREEN_ID 2
int language = 0; // 0 is english, 1 is spanish
int score_screen_selection = 0;
int current_screen = MENU_SCREEN_ID; // 0: start, 1: play; 2: score
int previous_screen = -1;

unsigned int spawn_timer = 0;
int shoot_timer = 0;
int spawn_time = BASE_SPAWN_TIME;

void Game_Init() {
    SpriteList::Init(MAX_SPRITES);
    player.push(PLAYER_X >> 8, PLAYER_Y >> 8, 0, 0, 0); // initialize player
    backgrounds.init(MAX_BACKGROUND);
    blackRectangles.init(MAX_OBJECTS);
    for (int i = 0; i < MAX_BACKGROUND; i++){
        int img;
        if (Random(10)) img = STAR_SMALL_ID;
        else img = STAR_BIG_ID;
        backgrounds.push(Random(256) << 8, Random(256) << 8, img);
    }
}

void Game_Reset() {
    aliens.clear();
    alienLasers.clear();
    playerLasers.clear();
    shield = BASE_SHIELD_COUNT;
    score = 0;
    spawn_time = BASE_SPAWN_TIME;
}

void Process_Collisions(){
    // player collision
    if (aliens.collides(player.head) || alienLasers.collides(player.head)){
        Sound_Explosion();
        player.head->img = PLAYER_EXPLOSION_1_ID;
        player.head->counter = 0;
        shield--;
        }
    // alien vs playerlaser collision
    if (aliens.detectCollisions(playerLasers)){
        score++; 
    }
}

// 30HZ Game Engine
void TIMG12_IRQHandler(void){
    if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)


    // 1) set semaphore, system operations
    refresh = true;
    Random32();
    spawn_timer++;
    shoot_timer++;

    // 2) sample ADC, read input switches
    slidepot = Sensor.In();
    JoyStick_In(&ADC0_x, &ADC0_y);

    slidepot = (slidepot + 300) >> 10;  // 0 to 4
    joystick_x = ADC0_x - 2048;
    joystick_y = ADC0_y - 2048;

    uint8_t all_switches = Switches.All_Switch_In();
    uint8_t up    = Switches.UP_Switch_In();
    uint8_t down  = Switches.DOWN_Switch_In();
    uint8_t right = Switches.RIGHT_Switch_In();
    uint8_t left  = Switches.LEFT_Switch_In();

    // 3) screen specific actions
    switch (current_screen){
    // Menu screen
    case MENU_SCREEN_ID:
        // any button on menu screen => game start
        if (all_switches && !prev_up && !prev_down && !prev_left && !prev_right){
            Sound_Ufo_Highpitch_Menu();
            current_screen = 1;
            shield = BASE_SHIELD_COUNT;
            score = 0;
        }
        if (joystick_y > 1000 && language == 1){
            Sound_Menu_Selection();
            refresh_menu = true;
            language = 0;
        }
        if (joystick_y < -1000 && language == 0 && joystick_y > -2048){
            Sound_Menu_Selection();
            language = 1;
            refresh_menu = true;
        }
        break;

    // Play screen
    case PLAY_SCREEN_ID:
        // if player is in exploding state, update image and exit engine immediately to freeze screen
        if (player.head->img > 1){
            player.head->counter++;
            if (player.head->counter > 7){
                blackRectangles.push(PLAYER_X, PLAYER_Y, PLAYER_ON_ID);
                player.head->img++;
                if (player.head->img == PLAYER_EXPLOSION_4_ID + 1){
                    if (shield){
                        player.head->img = PLAYER_OFF_ID;
                    } else {
                        player.head->img = PLAYER_EXPLOSION_4_ID;
                        current_screen = 2;
                    }
                }
            }
            return;
        }
        // player on/off based on joystick
        if (joystick_x > 1000 || joystick_y > 1000 || joystick_x < -1000 || joystick_y < -1000){
            player.head->img = PLAYER_ON_ID;
        } else {
            player.head->img = PLAYER_OFF_ID;
        }

        Update_Player_Speed(joystick_x, joystick_y, slidepot);

        // down button is shoot
        if (down && !prev_down){
            prev_down = true;
            // shoot if loaded
            if (shoot_timer > PLAYER_LASER_COOLDOWN){
                shoot_timer = 0;
                Sound_Shoot();
                prev_down = true;
                int xvel = -joystick_x;
                int yvel = -joystick_y;
                if (xvel == 0) xvel = 1;
                // make velocity bigger than player_laser_speed
                while (xvel*xvel + yvel*yvel < PLAYER_LASER_SPEED*PLAYER_LASER_SPEED){
                    xvel *= 2;
                    yvel *= 2;
                } // velocity at most 2*player_laser_speed 
                while (xvel*xvel + yvel*yvel > 4*PLAYER_LASER_SPEED*PLAYER_LASER_SPEED){
                    xvel /= 2;
                    yvel /= 2;
                } // subtract from velocity until it equals player_laser_speed
                int xsub = xvel / 16; // subtract at most 16 times
                int ysub = yvel / 16;
                while (xvel*xvel + yvel*yvel > PLAYER_LASER_SPEED*PLAYER_LASER_SPEED){
                    xvel -= xsub;
                    yvel -= ysub;
                }
                playerLasers.push(PLAYER_X>>8, PLAYER_Y>>8, xvel, yvel, PLAYER_LASER_ID);
            }
            // if not loaded yet make no ammo sound
            else {
                Sound_No_Ammo();
            }
        }
        // spawn aliens
        if (spawn_timer > spawn_time){
            if (spawn_time > MIN_SPAWN_TIME) spawn_time--;
            int rand_x = Random(128); // 256 - 128
            int rand_y = Random(96);  // 256 - 160
            if (rand_x > 64) rand_x += 128; // split between far left and far right
            if (rand_y > 48) rand_y += 160; // split between far up and far down
            aliens.push(rand_x, rand_y, 0, 0, ALIEN_1_ID);
            spawn_timer = 0;
        }
        // update sprites and process collisions
        backgrounds.update();
        playerLasers.update();
        alienLasers.update();
        aliens.update();
        Process_Collisions();
        break;

    // Score screen
    case SCORE_SCREEN_ID:
        // press up in score screen => confirm selection
        // go back to menu (selection=1) or replay (selection=0)
        if (all_switches && !prev_up && !prev_down && !prev_left && !prev_right){
            Sound_Ufo_Highpitch_Menu();
            Game_Reset();
            if (score_screen_selection == 1){
                current_screen = 0;
            } else {
                current_screen = 1;
            }
        }
        // joystick_y to select from score screen
        if (joystick_y > 1000 && score_screen_selection == 1){
            Sound_Menu_Selection();
            score_screen_selection = 0;
            refresh_score = true;
        }
        if (joystick_y < -1000 && score_screen_selection == 0){
            Sound_Menu_Selection();
            score_screen_selection = 1;
            refresh_score = true;
        }
        break;
    default: break; // never reached
    }

    // 4) set semaphore and update 'prev' values
    prev_up    = up;
    prev_down  = down;
    prev_left  = left;
    prev_right = right;
    // NO LCD OUTPUT IN INTERRUPT SERVICE ROUTINES
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
    }
}

typedef enum {English, Spanish, Portuguese, French} Language_t;
Language_t myLanguage=English;
typedef enum {HELLO, GOODBYE, LANGUAGE} phrase_t;
const char Title_English[] ="Last Stand";
const char Title_Spanish[] ="La Ultima Batalla";
const char Directions_English[] ="-Press Any To Begin-";
const char Directions_Spanish[] = "-Toque Para Empezar-";
const char Sel_Language_English[]="Language:";
const char Sel_Language_Spanish[]="Lenguaje:";
const char Language_English[]="English";
const char Language_Spanish[]="Espa\xA4ol";

const char GameOver_English[] = "Game Over";
const char GameOver_Spanish[] = "Perdiste La Vida";
const char Score_English[]="Score";
const char Score_Spanish[]="Puntos";
const char Restart_English[]="Restart";
const char Restart_Spanish[]="Otra";
const char Time_English[]="Time";
const char Time_Spanish[]="Tiempo";
const char Menu_English[]="Menu"; // same in spanish lol
const char *Phrases[2][8]={
  {Title_English, Directions_English, Sel_Language_English, Language_English, GameOver_English, Score_English, Restart_English, Time_English}, // row 1 English
  {Title_Spanish, Directions_Spanish, Sel_Language_Spanish, Language_Spanish, GameOver_Spanish, Score_Spanish, Restart_Spanish, Time_Spanish}, // row 2 Spanish
};

void Menu_Screen_Init() {
    ST7735_FillScreen(ST7735_BLACK);
    ST7735_DrawString(1, 2, (Phrases[language][0]), ST7735_RED, ST7735_BLACK, 1); // title
    ST7735_DrawString(1, 6, (Phrases[language][2]), ST7735_GREEN, ST7735_BLACK, 1); // language header
    ST7735_DrawString(1, 12, (Phrases[language][1]), ST7735_WHITE, ST7735_BLACK, 1); // directions

    if(language == 0){
        ST7735_FillRect(14, 78, 50, 12, ST7735_YELLOW);
        ST7735_DrawString(3, 8, (Phrases[0][3]), ST7735_BLACK, ST7735_YELLOW, 1); // language
        ST7735_DrawString(3, 10, (Phrases[1][3]), ST7735_WHITE, ST7735_BLACK, 1); // language
    }else{
        ST7735_FillRect(14, 98, 50, 12, ST7735_YELLOW);
        ST7735_DrawString(3, 8, (Phrases[0][3]), ST7735_WHITE, ST7735_BLACK, 1); // language
        ST7735_DrawString(3, 10, (Phrases[1][3]), ST7735_BLACK, ST7735_YELLOW, 1); // language
    }
}
void Menu_Screen_Update() {
    ST7735_FillRect(6, 20, 102, 8, ST7735_BLACK); // title
    ST7735_FillRect(14, 78, 50, 32, ST7735_BLACK); // english spanish
    Menu_Screen_Init();
}


void Play_Screen_Init() {
    ST7735_FillScreen(ST7735_BLACK);
}
void playdebugger(){
    return;
    extern SpriteList spritePool;
    ST7735_SetCursor(0, 2);
    int poolcount = 0;
    int acount = 0;
    int alcount = 0;
    int plcount = 0;
    Sprite* s = aliens.head;
    while(s){acount++;s=s->next;}
    s = alienLasers.head;
    while(s){alcount++;s=s->next;}
    s = playerLasers.head;
    while(s){plcount++;s=s->next;}
    s = spritePool.head;
    while(s){poolcount++;s=s->next;}
    printf("%05d %05d", poolcount, acount);
}
void Play_Screen_Update() {
    static int prev_shield = BASE_SHIELD_COUNT;
    if (shield > prev_shield) prev_shield = shield;
    if (prev_shield > shield){
        ST7735_FillRect(108-20*(prev_shield-1), 141, 19, 14, ST7735_BLACK);
        prev_shield = shield;
    }
    blackRectangles.draw('B'); // 'B' to draw simploy black rectangles
    blackRectangles.length = 0;
    backgrounds.draw('I'); // 'I' to draw the actual image
    player.draw();
    aliens.draw();
    alienLasers.draw();
    playerLasers.draw();
    ST7735_SetCursor(6,1);
    printf("%s: %d", (Phrases[language][5]), score);

    playdebugger();
    // lives displayed at bottom
    // The location that powerups would be once they get picked up
//    ST7735_DrawBitmap(5, 155, powerup, 15, 15);
//    ST7735_DrawBitmap(25, 155, powerup, 15, 15);
//    ST7735_DrawBitmap(45, 155, powerup, 15, 15);
    for (int i = 0; i < shield; i++){
        ST7735_DrawBitmap(108 - i*20, 155, player_off, 19, 14);
    }

}


void Score_Screen_Init() {
    ST7735_FillRect(34, 10, 60, 8, ST7735_BLACK); // remove old score header
    ST7735_DrawString(4, 2, (Phrases[language][4]), ST7735_RED, ST7735_BLACK, 1); // game over header
    ST7735_SetCursor(6,7);
    printf("%s: %d", (Phrases[language][5]), score);

    if(score_screen_selection == 0){
        ST7735_FillRect(28, 98, 46, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_BLACK, ST7735_WHITE, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_WHITE, ST7735_BLACK, 1); // menu
    }else{
        ST7735_FillRect(28, 118, 32, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_WHITE, ST7735_BLACK, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_BLACK, ST7735_WHITE, 1); // menu
    }
}
void Score_Screen_Update() {
    ST7735_FillRect(28, 98, 46, 32, ST7735_BLACK);
    if(score_screen_selection == 0){
        ST7735_FillRect(28, 98, 46, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_BLACK, ST7735_WHITE, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_WHITE, ST7735_BLACK, 1); // menu
    }else{
        ST7735_FillRect(28, 118, 32, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_WHITE, ST7735_BLACK, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_BLACK, ST7735_WHITE, 1); // menu
    }
}

// ALL ST7735 OUTPUT MUST OCCUR IN MAIN
int main(void){ // final main
    __disable_irq();
    PLL_Init(); // set bus speed
    LaunchPad_Init();
    ST7735_InitPrintf();
    ST7735_FillScreen(ST7735_BLACK);
    Sensor.Init(); // PB18 = ADC1 channel 5, slidepot
    Switches.Init(); // initialize switches
    LED_Init();    // initialize LED
    Sound_Init();  // initialize sound
    JoyStick_Init(); // initialize joy stick
    // initialize interrupts on TimerG12 at 30 Hz
    TimerG12_IntArm(80000000/30,2);
    //TimerG8_IntArm(5000, 8000, 0); // every second it triggers
    // initialize all data structures
    Menu_Screen_Update();
    Game_Init();
    __enable_irq();
    while(1){
        // check for end game or level switch
        if(refresh){
            refresh = false;
            switch (current_screen){
            // Menu screen
            case 0:
                if (previous_screen != current_screen){
                    previous_screen = current_screen;
                    Menu_Screen_Init();
                }else if(refresh_menu){
                    Menu_Screen_Update();
                    refresh_menu = false;
                }
                break;

            // Play screen
            case 1:
                if (previous_screen != current_screen){
                    previous_screen = current_screen;
                    Play_Screen_Init();
                }
                Play_Screen_Update();
                break;

            // Score screen
            case 2:
                if (previous_screen != current_screen){
                    previous_screen = current_screen;
                    Score_Screen_Init();
                }else if(refresh_score){
                    Score_Screen_Update();
                    refresh_score = false;
                }
                break;
            }

            //ST7735_SetCursor(0,0);
            //ST7735_FillScreen(ST7735_BLACK);
            //ST7735_FillRect(0, 0, 180, 20, ST7735_BLACK);
            //printf("Time: %d", seconds_elapsed);
            //printf("y: %d\n", joystick_y);
            //printf("Distance: %d.%03dcm\n", (slidepot_distance/1000)%10,slidepot_distance%1000);

        }
    }
}

