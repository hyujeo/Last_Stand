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
// ****note to ECE319K students****
// the data sheet says the ADC does not work when clock is 80 MHz
// however, the ADC seems to work on my boards at 80 MHz
// I suggest you try 80MHz, but if it doesn't work, switch to 40MHz
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
BackgroundList blackRectangles; // sprites that got removed. for printing black rectangles.

Input_Switch_Handler Switches;

int score = 0;
int shield = 0;

uint32_t ADC0_x;
uint32_t ADC0_y;
int joystick_x;
int joystick_y;
int32_t slidepot;
uint32_t button_inputs;

bool refresh = false;
bool refresh_menu, refresh_score = false;

uint8_t prev_up, prev_down, prev_right, prev_left = 0;
int language = 0; // 0 is english, 1 is spanish
int score_screen_selection = 0;
int current_screen = 0; // 0: start, 1: play; 2: score
int previous_screen = -1;

// games  engine runs at 30Hz
void TIMG12_IRQHandler(void){
    if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)


    // 1) increment random number to randomize game
    Random32();

    // 2) sample ADC, read input switches
    slidepot = Sensor.In();
    JoyStick_In(&ADC0_x, &ADC0_y);
    joystick_x = 2048 - ADC0_x;
    joystick_y = ADC0_y - 2048;

    uint8_t all_switches = Switches.All_Switch_In();
    uint8_t up    = Switches.UP_Switch_In();
    uint8_t down  = Switches.DOWN_Switch_In();
    uint8_t right = Switches.RIGHT_Switch_In();
    uint8_t left  = Switches.LEFT_Switch_In();
    
    // 3) handle inputs
    switch (current_screen){
    // Menu screen
    case 0:
        // any button on menu screen => game start
        if (all_switches && !prev_up && !prev_down && !prev_left && !prev_right){
            current_screen = 1;
        }
        if (joystick_y > 1000 && language == 1){
            Sound_Menu_Selection();
            refresh_menu = true;
            language = 0;
        }
        if (joystick_y < -1000 && language == 0){
            Sound_Menu_Selection();
            language = 1;
            refresh_menu = true;
        }
        break;

    // Play screen
    case 1:
        Update_Player_Speed(joystick_x, joystick_y, slidepot);
        // down button is shoot
        if (down && !prev_down){
            Sound_Shoot();
            prev_down = true;
            playerLasers.push(PLAYER_X >> 8, PLAYER_Y >> 8, joystick_x, joystick_y, PLAYER_LASER_ID);
        }

        // TODO REMOVE UP BUTTON TO NAVIGATE TO SCORE
        if (up && !prev_up){
            current_screen = 2;
        }
        break;

    // Score screen
    case 2:
        // press up in score screen => confirm selection
        // go back to menu (selection=1) or replay (selection=0)
        if (all_switches && !prev_up && !prev_down && !prev_left && !prev_right){
            Sound_Ufo_Highpitch_Menu();
            if (score_screen_selection == 0){
                current_screen = 1;
            } else {
                current_screen = 0;
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

    // 4) move and update sprites


    // 5) set semaphore and update 'prev' values
    prev_up    = up;
    prev_down  = down;
    prev_left  = left;
    prev_right = right;
    // NO LCD OUTPUT IN INTERRUPT SERVICE ROUTINES
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
    refresh = true;
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
const char GameOver_Spanish[] = "Terminaste";
const char Score_English[]="Score";
const char Score_Spanish[]="Puntos";
const char Restart_English[]="Restart";
const char Restart_Spanish[]="Otra";
const char Menu_English[]="Menu"; // same in spanish lol
const char *Phrases[2][7]={
  {Title_English, Directions_English, Sel_Language_English, Language_English, GameOver_English, Score_English, Restart_English}, // row 1 English
  {Title_Spanish, Directions_Spanish, Sel_Language_Spanish, Language_Spanish, GameOver_Spanish, Score_Spanish, Restart_Spanish}, // row 2 Spanish
};

void Game_Init() {
    SpriteList::Init(MAX_SPRITES);
    player.push(PLAYER_X >> 8, PLAYER_Y >> 8, 0, 0, 0); // initialize player
    backgrounds.init(MAX_BACKGROUND);
    blackRectangles.init(MAX_OBJECTS);
    for (int i = 0; i < MAX_BACKGROUND; i++){
        int img;
        if (Random(10)) img = STAR_SMALL_ID;
        else img = STAR_BIG_ID;
        backgrounds.push(Random(256), Random(256), img);
    }
}

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
    ST7735_SetCursor(0,0);
    printf("%05d\n", joystick_y);
    return; // nothing for now
}

void Play_Screen_Init() {
    ST7735_FillScreen(ST7735_BLACK);
    player.draw();
}

void Play_Screen_Update() {
    blackRectangles.draw('B'); // 'B' to draw simploy black rectangles
    backgrounds.draw('I'); // 'I' to draw the actual image
    aliens.draw();
    alienLasers.draw();
    playerLasers.draw();
}

void Score_Screen_Init() {
    ST7735_FillScreen(ST7735_BLACK);
    ST7735_DrawString(5, 2, (Phrases[language][4]), ST7735_RED, ST7735_BLACK, 1); // game over header
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
    return; // nothing for now
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
    // initialize all data structures
    Menu_Screen_Update();
    Game_Init();
    __enable_irq();
    while(1){
        // check for end game or level switch
        if(refresh){
            //ST7735_FillScreen(ST7735_BLACK);
            refresh = false;
            //ST7735_FillScreen(ST7735_BLACK);
            switch (current_screen){
            //ST7735_FillScreen(ST7735_BLACK);
            // Menu screen
            case 0:
                if (previous_screen != current_screen || refresh_menu){
                    previous_screen = current_screen;
                    refresh_menu = false;
                    Menu_Screen_Init();
                }
                Menu_Screen_Update();
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
                if (previous_screen != current_screen || refresh_score){
                        previous_screen = current_screen;
                        refresh_score = false;
                        Score_Screen_Init();
                    }
                Score_Screen_Update();
                break;
            }

            //ST7735_SetCursor(0,0);
            //ST7735_FillScreen(ST7735_BLACK);
            //ST7735_FillRect(0, 0, 180, 20, ST7735_BLACK);
            //printf("x: %d\n", ADC0_xpos);
            //printf("y: %d\n", joystick_y);
            //printf("Distance: %d.%03dcm\n", (slidepot_distance/1000)%10,slidepot_distance%1000);

        }
    }
}

