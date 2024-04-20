/*
 * Switch.cpp
 *
 *  Created on: Nov 5, 2023
 *      Author:
 */
#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"

// refer to table 2.2.1 in Textbook in Chapter 2
#define LEFT_BTN PB16INDEX // PB16
#define UP_BTN PB17INDEX // PB17
#define RIGHT_BTN PB12INDEX // PB12
#define DOWN_BTN PB13INDEX // PB13
#define JOYSTICK_BTN PA24INDEX // PA24
// update if different inputs ^ v
#define LEFT_INDEX (1<<16)
#define UP_INDEX (1<<17)
#define RIGHT_INDEX (1<<12)
#define DOWN_INDEX (1<<13)
#define JOYSTICK_INDEX (1<<24)

// LaunchPad.h defines all the indices into the PINCM table
void Switch_Init(void){
    // write this
    IOMUX->SECCFG.PINCM[LEFT_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[UP_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[RIGHT_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[DOWN_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[JOYSTICK_BTN] = 0x00050081; // input with pull down resistor
}

// return current state of left switch
uint32_t JOYSTICK_Switch_In(void){
    // write this
    return (GPIOA->DIN31_0)&JOYSTICK_INDEX;
}

// return current state of left switch
uint32_t LEFT_Switch_In(void){
    // write this
    return (GPIOB->DIN31_0)&LEFT_INDEX;
}

// return current state of up switch
uint32_t UP_Switch_In(void){
    // write this
    return (GPIOB->DIN31_0)&UP_INDEX;
}

// return current state of right switch
uint32_t RIGHT_Switch_In(void){
    // write this
    return (GPIOB->DIN31_0)&RIGHT_INDEX;
}

// return current state of down switch
uint32_t DOWN_Switch_In(void){
    // write this
    return (GPIOB->DIN31_0)&DOWN_INDEX;
}

// return all switch current values
uint32_t Switch_In(void){
    return JOYSTICK_Switch_In() | LEFT_Switch_In() | UP_Switch_In() | DOWN_Switch_In() | RIGHT_Switch_In();
}
