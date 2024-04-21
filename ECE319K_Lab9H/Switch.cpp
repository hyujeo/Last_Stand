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
#define LEFT_INDEX 16
#define UP_INDEX 17
#define RIGHT_INDEX 12
#define DOWN_INDEX 13
#define JOYSTICK_INDEX 24

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
    return ((GPIOA->DIN31_0)&(1<<JOYSTICK_INDEX))>>(JOYSTICK_INDEX);
}

// return current state of left switch
uint32_t LEFT_Switch_In(void){
    // write this
    return ((GPIOB->DIN31_0)&(1<<LEFT_INDEX))>>(LEFT_INDEX);
}

// return current state of up switch
uint32_t UP_Switch_In(void){
    // write this
    return ((GPIOB->DIN31_0)&(1<<UP_INDEX))>>(UP_INDEX);
}

// return current state of right switch
uint32_t RIGHT_Switch_In(void){
    // write this
    return ((GPIOB->DIN31_0)&(1<<RIGHT_INDEX))>>(RIGHT_INDEX);
}

// return current state of down switch
uint32_t DOWN_Switch_In(void){
    // write this
    return ((GPIOB->DIN31_0)&(1<<DOWN_INDEX))>>(DOWN_INDEX);
}

// return all switch current values
// Joystick bit 4, left bit 3, up bit 2, right bit 1, down bit 0
uint32_t Switch_In(void){
    return (JOYSTICK_Switch_In()<<4 | LEFT_Switch_In()<<3 | UP_Switch_In()<<2 | RIGHT_Switch_In()<<1 | DOWN_Switch_In());
}
