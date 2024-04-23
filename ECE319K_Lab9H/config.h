#ifndef LAST_STAND_CONFIG_H
#define LAST_STAND_CONFIG_H

#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"

#define BOARD_ID 0 // 0 for Hyunho's, 1 for Jonathan's

#if BOARD_ID == 0
    #define JOYSTICK_CHANNEL_X 3
    #define JOYSTICK_CHANNEL_Y 2
    
    // refer to table 2.2.1 in Textbook in Chapter 2
    #define LEFT_BTN PB13INDEX // PB13
    #define UP_BTN PB12INDEX // PB12
    #define RIGHT_BTN PB19INDEX // PB19
    #define DOWN_BTN PB17INDEX // PB17
    #define JOYSTICK_BTN PA17INDEX // PA17

    #define LEFT_INDEX 13
    #define UP_INDEX 12
    #define RIGHT_INDEX 19
    #define DOWN_INDEX 17
    #define JOYSTICK_INDEX 17
#else
    #define JOYSTICK_CHANNEL_X 1
    #define JOYSTICK_CHANNEL_Y 0

    // refer to table 2.2.1 in Textbook in Chapter 2
    #define LEFT_BTN PB16INDEX // PB16
    #define UP_BTN PB17INDEX // PB17
    #define RIGHT_BTN PB12INDEX // PB12
    #define DOWN_BTN PB13INDEX // PB13
    #define JOYSTICK_BTN PA24INDEX // PA24

    #define LEFT_INDEX 16
    #define UP_INDEX 17
    #define RIGHT_INDEX 12
    #define DOWN_INDEX 13
    #define JOYSTICK_INDEX 24
#endif

// increase friction to decrease max speed
#define FRICTION 11

// player coordinates in 128x128, with << 8 to fit Sprite standards
// adjust player location on screen
#define PLAYER_X 64 << 8
#define PLAYER_Y 64 << 8

// default = 0, increase to 
#define HITBOX 0

// list of image numbers, as indices in Image.h::images
#define ALIEN1_ID           4
#define ALIEN_LASER_ID      9
#define ALIEN_EXPLOSION1_ID 12

// number of backgrounds, number of total objects = sprites + backgrounds
#define NUM_BACKGROUND 100
#define NUM_OBJECTS    250

#endif //LAST_STAND_CONFIG_H