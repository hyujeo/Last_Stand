/*
 * LED.cpp
 *
 *  Created on: Nov 5, 2023
 *      Author:
 */
#include <ti/devices/msp/msp.h>
#include "../inc/LaunchPad.h"
// LaunchPad.h defines all the indices into the PINCM table

// used for initialization
#define RED_LED PB24INDEX // PB24
#define YELLOW_LED PB23INDEX // PB23
#define GREEN_LED PB19INDEX // PB19
// used for the actual bits
#define RED_BIT (1<<24)
#define YELLOW_BIT (1<<23)
#define GREEN_BIT (1<<19)

// initialize your LEDs
void LED_Init(void){
    // write this
    IOMUX->SECCFG.PINCM[RED_LED] = 0x00000081; // regular output
    IOMUX->SECCFG.PINCM[YELLOW_LED] = 0x00000081; // regular output
    IOMUX->SECCFG.PINCM[GREEN_LED] = 0x00000081; // regular output

    GPIOB->DOE31_0 |= RED_BIT | YELLOW_BIT | GREEN_BIT; // enable outputs
    
}

// turns on RED LED
void RED_LED_On(void){
    // write this
    // use DOUTSET31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTSET31_0 = RED_BIT;
}

// turn off RED LED
void RED_LED_Off(void){
    // write this
    // use DOUTCLR31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTCLR31_0 = RED_BIT;
}

// toggles RED LED
void RED_LED_Toggle(void){
    // write this
    // use DOUTTGL31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTTGL31_0 = RED_BIT;
}

// turns on YELLOW LED
void YELLOW_LED_On(void){
    // write this
    // use DOUTSET31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTSET31_0 = YELLOW_BIT;
}

// turn off YELLOW LED
void YELLOW_LED_Off(void){
    // write this
    // use DOUTCLR31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTCLR31_0 = YELLOW_BIT;
}

// toggles YELLOW LED
void YELLOW_LED_Toggle(void){
    // write this
    // use DOUTTGL31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTTGL31_0 = YELLOW_BIT;
}

// turns on GREEN LED
void GREEN_LED_On(void){
    // write this
    // use DOUTSET31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTSET31_0 = GREEN_BIT;
}

// turn off GREEN LED
void GREEN_LED_Off(void){
    // write this
    // use DOUTCLR31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTCLR31_0 = GREEN_BIT;
}

// toggles GREEN LED
void GREEN_LED_Toggle(void){
    // write this
    // use DOUTTGL31_0 register so it does not interfere with other GPIO
    GPIOB->DOUTTGL31_0 = GREEN_BIT;
}
