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

int score = 0;
int shield = 0;

uint32_t ADC0_xpos;
uint32_t ADC0_ypos;
int32_t slidepot_distance;
uint32_t button_inputs;
bool refresh = false;
int gameState = 1;
int prevState = -1;
int last = 0;

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
    JoyStick_In(&ADC0_xpos, &ADC0_ypos);
    button_inputs = Switch_In();
    // 3) move sprites
    // 4) start sounds
    // determine which sound to play based on certain scenarious
    if((last == 0)&&((button_inputs&0x01) == 1)){
        last = 1;
        Sound_Shoot(); // if shoot button was pressed
    }
    // only button that makes sound effect is shoot sound
    // rest of these sounds will be respectively called when needed
    // these conditionals are just for bare testing :)
    if((last == 0)&&((button_inputs&0x04) == 4)){
        Sound_Explosion(); // if something blew up *change conditional*
        last = 1;
    }
    if((last!=0)&&(button_inputs==0)){ // high to low
        last = 0;
    }
    // 5) set semaphore
    refresh = true;
    // NO LCD OUTPUT IN INTERRUPT SERVICE ROUTINES
    GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
  }
}

typedef enum {English, Spanish, Portuguese, French} Language_t;
Language_t myLanguage=English;
typedef enum {HELLO, GOODBYE, LANGUAGE} phrase_t;
const char Hello_English[] ="Hello";
const char Hello_Spanish[] ="\xADHola!";
const char Hello_Portuguese[] = "Ol\xA0";
const char Hello_French[] ="All\x83";
const char Goodbye_English[]="Goodbye";
const char Goodbye_Spanish[]="Adi\xA2s";
const char Goodbye_Portuguese[] = "Tchau";
const char Goodbye_French[] = "Au revoir";
const char Language_English[]="English";
const char Language_Spanish[]="Espa\xA4ol";
const char Language_Portuguese[]="Portugu\x88s";
const char Language_French[]="Fran\x87" "ais";
const char *Phrases[3][4]={
    {Hello_English,Hello_Spanish,Hello_Portuguese,Hello_French},
    {Goodbye_English,Goodbye_Spanish,Goodbye_Portuguese,Goodbye_French},
    {Language_English,Language_Spanish,Language_Portuguese,Language_French}
};

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

    // from here on is for testing purposes
    player.draw();
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
}

