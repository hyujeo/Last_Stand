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

    #define USE_INTERNAL_RESISTOR 0x10000
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

    #define USE_INTERNAL_RESISTOR 0
#endif

// list of image numbers, as indices in Image.h::images
#define PLAYER_OFF_ID 0
#define PLAYER_ON_ID  1
#define STAR_SMALL_ID 2
#define STAR_BIG_ID   3
#define ALIEN_1_ID 4
// #define 5
// #define 6
// #define 7
#define PLAYER_LASER_ID 8
#define ALIEN_LASER_ID  9
// #define 10
// #define 11 
#define ALIEN_1_EXPLOSION_1_ID 12
#define ALIEN_1_EXPLOSION_2_ID 13
#define ALIEN_1_EXPLOSION_3_ID 14
#define ALIEN_1_EXPLOSION_4_ID 15
#define PLAYER_EXPLOSION_1_ID 16
#define PLAYER_EXPLOSION_2_ID 17
#define PLAYER_EXPLOSION_3_ID 18
#define PLAYER_EXPLOSION_4_ID 19

// increase friction to decrease max speed
#define FRICTION 11

// player coordinates in 256x256, with << 8 to fit Sprite standards
// adjust player location on screen
#define PLAYER_X 128 << 8
#define PLAYER_Y 128 << 8

// default = 0, increase to 
#define HITBOX 0

// number of backgrounds, number of total objects = sprites + backgrounds
#define MAX_BACKGROUND 100
#define MAX_SPRITES    150
#define MAX_OBJECTS    (MAX_BACKGROUND + MAX_SPRITES)

#endif //LAST_STAND_CONFIG_H