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

uint32_t ADC0_xpos;
uint32_t ADC0_ypos;
int32_t slidepot_distance;
uint32_t button_inputs;

bool refresh = false;
int forced = 0;
int last_shoot, last_nav, go_game = 0;
int language = 0; // 0 is english, 1 is spanish
int end_selection = 0;
int current_screen = 0; // 0 - welcome screen ; 1 - main game; 2 - Game Over

// games  engine runs at 30Hz
void TIMG12_IRQHandler(void){
    if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
        GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
// game engine goes here
    // 1) sample slide pot
        slidepot_distance = Sensor.In();
        slidepot_distance = Sensor.Convert(slidepot_distance); // reads slidepot
    if(slidepot_distance < 0){
        slidepot_distance = 0;
    }else if (slidepot_distance > 2000){
        slidepot_distance = 2000;
    }
    // 2) read input switches
    uint8_t all_switches = Switches.All_Switch_In();
    JoyStick_In(&ADC0_xpos, &ADC0_ypos);
    uint8_t shoot_btn_input = Switches.DOWN_Switch_In();
    uint8_t nav_right_input = Switches.RIGHT_Switch_In();
    // 3) move sprites
    // 4) start sounds
    // determine which sound to play based on certain scenarious

    if((all_switches) && (current_screen == 0)){
        go_game = 1;
    }
    if((last_shoot == 0) && (shoot_btn_input == 1) && (current_screen == 1)){
        last_shoot = 1;
        Sound_Shoot(); // if shoot button was pressed
    }
    if((last_shoot!=0)&&(shoot_btn_input==0)){ // high to low
        last_shoot = 0;
    }
    if((last_nav == 0) && (end_selection == 1) && (current_screen == 2) && (nav_right_input == 1)){
        last_nav = 1;
        current_screen = 0;
        forced = 1;
        Sound_Ufo_Highpitch_Menu();
    }
    if((last_nav!=0)&&(nav_right_input==0)){ // high to low
        last_nav = 0;
    }
    // 5) set semaphore
    refresh = true;
    // NO LCD OUTPUT IN INTERRUPT SERVICE ROUTINES
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
  }
}
  
// button inputs updated once every 30Hz
//void TIMG0_IRQHandler(void){
//    if((TIMG0->CPU_INT.IIDX) == 1){ // Acknowledge
//        Switches.All_Switch_In();
//    }
//}


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

void Welcome_Screen(){
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

void Game_Over(){
    ST7735_FillScreen(ST7735_BLACK);
    ST7735_DrawString(5, 2, (Phrases[language][4]), ST7735_RED, ST7735_BLACK, 1); // game over header
    ST7735_SetCursor(6,7);
    printf("%s: %d", (Phrases[language][5]), score);

    if(end_selection == 0){
        ST7735_FillRect(28, 98, 46, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_BLACK, ST7735_WHITE, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_WHITE, ST7735_BLACK, 1); // menu
    }else{
        ST7735_FillRect(28, 118, 32, 12, ST7735_WHITE);
        ST7735_DrawString(5, 10, (Phrases[language][6]), ST7735_WHITE, ST7735_BLACK, 1); // restart
        ST7735_DrawString(5, 12, Menu_English, ST7735_BLACK, ST7735_WHITE, 1); // menu
    }

}

void Game_Init() {
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

void drawStartFormat() {

}

void drawStartScreen() {

}

void drawPlayFormat() {

}

void drawPlayScreen() {
    blackRectangles.draw('B'); // 'B' to draw simploy black rectangles
    backgrounds.draw('I'); // 'I' to draw the actual image
    aliens.draw();
    alienLasers.draw();
    playerLasers.draw();
}

void drawScoreFormat() {

}

void drawScoreScreen() {

}

// ALL ST7735 OUTPUT MUST OCCUR IN MAIN
int main(void){ // final main
    __disable_irq();
    PLL_Init(); // set bus speed
    LaunchPad_Init();
    ST7735_InitPrintf();
    //note: if you colors are weird, see different options for
    // ST7735_InitR(INITR_REDTAB); inside ST7735_InitPrintf()
/*
    ST7735_FillScreen(ST7735_BLACK);
    Sensor.Init(); // PB18 = ADC1 channel 5, slidepot
    Switch_Init(); // initialize switches
    LED_Init();    // initialize LED
    Sound_Init();  // initialize sound
    JoyStick_Init(); // initialize joy stick
    // initialize interrupts on TimerG12 at 30 Hz
    TimerG12_IntArm(80000000/30,2);
    // initialize all data structures
    Game_Init();
    __enable_irq();
    while(1){
        if (!refresh) continue;
        refresh = false;
        switch (gameState){
        // login screen
        case 0:
            if (prevState != gameState){
                drawStartFormat();
            }
            drawStartScreen();
        
        // play screen
        case 1:
            if (prevState != gameState){ // changed to play screen -> reset screen and draw top/bottom border
                prevState = gameState;
                ST7735_FillScreen(ST7735_BLACK);
                drawPlayFormat();
            }
            drawPlayScreen();
        
        // score screen
        case 2:
            if (prevState != gameState){ // changed to score screen -> reset screen and draw the score screen base format
                prevState = gameState;
                ST7735_FillScreen(ST7735_BLACK);
                drawScoreFormat();
            }
        }
    }
*/
  ST7735_FillScreen(ST7735_BLACK);
  Sensor.Init(); // PB18 = ADC1 channel 5, slidepot
  Switches.Init(); // initialize switches
  LED_Init();    // initialize LED
  Sound_Init();  // initialize sound
  JoyStick_Init(); // initialize joy stick
    // initialize interrupts on TimerG12 at 30 Hz
  TimerG12_IntArm(80000000/30,2);
  // initialize interrupts on TimerG0 at 30 Hz
  //TimerG0_IntArm(13333,100,2); //
  // initialize all data structures
  //Game_Init();
  //Game_Over();
  Welcome_Screen();
  __enable_irq();
  while(1){
    // wait for semaphore
       // clear semaphore
       // update ST7735R
    // check for end game or level switch
      if(refresh != 0){
          if(current_screen == 0){
              if((ADC0_ypos > 2500) && (language == 1)){
                  language = 0;
                  Welcome_Screen();
                  Sound_Ufo_Highpitch_Menu();
              }else if((ADC0_ypos < 2000) && (ADC0_ypos > 0) && (language == 0)){
                  language = 1;
                  Welcome_Screen();
                  Sound_Ufo_Highpitch_Menu();
              }else if(forced == 1){
                  Welcome_Screen();
                  forced = 0;
              }
              if(go_game){
                  Game_Init();
                  go_game = 0;
                  current_screen = 1;
              }
          }else if(current_screen == 1){ // game screen

          }else if(current_screen == 2){ // game over screen
              if((ADC0_ypos > 2500) && (end_selection == 1)){
                  end_selection = 0;
                  Game_Over();
                  Sound_Ufo_Highpitch_Menu();
              }else if((ADC0_ypos < 2000) && (ADC0_ypos > 0) && (end_selection == 0)){
                  end_selection = 1;
                  Game_Over();
                  Sound_Ufo_Highpitch_Menu();
              }
          }

          //ST7735_SetCursor(0,0);
          //ST7735_FillScreen(ST7735_BLACK);
          //ST7735_FillRect(0, 0, 180, 20, ST7735_BLACK);
          //printf("x: %d\n", ADC0_xpos);
          //printf("y: %d\n", ADC0_ypos);
          //printf("Distance: %d.%03dcm\n", (slidepot_distance/1000)%10,slidepot_distance%1000);

         refresh = 0;
      }
  }
}

