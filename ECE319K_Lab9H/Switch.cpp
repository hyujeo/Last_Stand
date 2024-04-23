#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
#include "Switch.h"



// LaunchPad.h defines all the indices into the PINCM table
void Input_Switch_Handler::Init(void){
    // write this
    IOMUX->SECCFG.PINCM[LEFT_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[UP_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[RIGHT_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[DOWN_BTN] = 0x00040081; // input
    IOMUX->SECCFG.PINCM[JOYSTICK_BTN] = 0x00050081; // input with pull down resistor
}



// return current state of left switch
uint8_t Input_Switch_Handler::JOYSTICK_Switch_In(void){
    // write this
    return this->JOYSTICK;
}

// return current state of left switch
uint8_t Input_Switch_Handler::LEFT_Switch_In(void){
    // write this
    return this->LEFT;
}

// return current state of up switch
uint8_t Input_Switch_Handler::UP_Switch_In(void){
    // write this
    return this->UP;
}

// return current state of right switch
uint8_t Input_Switch_Handler::RIGHT_Switch_In(void){
    // write this
    return this->RIGHT;
}

// return current state of down switch
uint8_t Input_Switch_Handler::DOWN_Switch_In(void){
    // write this
    return this->DOWN;
}

// return all switch current values
// Joystick bit 4, left bit 3, up bit 2, right bit 1, down bit 0
uint8_t Input_Switch_Handler::All_Switch_In(void){
    this->JOYSTICK = (uint8_t)(((GPIOA->DIN31_0)&(1<<JOYSTICK_INDEX))>>(JOYSTICK_INDEX));
    this->LEFT = (uint8_t)(((GPIOB->DIN31_0)&(1<<LEFT_INDEX))>>(LEFT_INDEX));
    this->UP = (uint8_t)(((GPIOB->DIN31_0)&(1<<UP_INDEX))>>(UP_INDEX));
    this->RIGHT = (uint8_t)(((GPIOB->DIN31_0)&(1<<RIGHT_INDEX))>>(RIGHT_INDEX));
    this->DOWN = (uint8_t)(((GPIOB->DIN31_0)&(1<<DOWN_INDEX))>>(DOWN_INDEX));
    return (this->JOYSTICK<<4 | this->LEFT<<3 | this->UP<<2 | this->RIGHT<<1 | this->DOWN);
}
