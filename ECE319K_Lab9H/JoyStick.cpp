/* JoyStick.c
 * MKII BoosterPack
 * Jonathan Valvano
 * November 21, 2022
 * Derived from gpio_toggle_output_LP_MSPM0G3507_nortos_ticlang
 *              adc12_single_conversion_vref_internal_LP_MSPM0G3507_nortos_ticlang
 *              adc12_single_conversion_LP_MSPM0G3507_nortos_ticlang
 */

#include <ti/devices/msp/msp.h>
#include "../inc/JoyStick.h"
#include "../inc/Clock.h"
#include "../inc/ADC.h"
#include "config.h"
// Analog MKII  Joystick
// J1.5 joystick Select button (digital) PA26
// J1.2 joystick horizontal (X) (analog) PA25_ADC0.2
// J3.26 joystick vertical (Y) (analog)  PA18_ADC1.3
// remove J1 J2 J3 on LaunchPad to use PA26

// Initialize MKII JoyStick and JoyStick button
void JoyStick_Init(void){
  ADC_InitDual(ADC0, JOYSTICK_CHANNEL_X, JOYSTICK_CHANNEL_Y, ADCVREF_VDDA); // dual channel x and y
  //ADC0_Init(0,ADCVREF_VDDA); // x position joystick
  //ADC_Init(ADC1,3,ADCVREF_VDDA); // y position joystick
  // assume these are called from LaunchPad_Init
  //  GPIOA->GPRCM.RSTCTL = (uint32_t)0xB1000003;  // Reset GPIOA
  //  GPIOA->GPRCM.PWREN = (uint32_t)0x26000001;   // Enable power to GPIOA
  Clock_Delay(24); // time for gpio to power up
}

// Read JoyStick position
// Inputs: *x pointer to empty 32 bit unsigned variable
//         *y pointer to empty 32 bit unsigned variable
// Output: none
void JoyStick_In(uint32_t *x, uint32_t *y){
    //*x = ADC0_In();
    //*y = 900;
    ADC_InDual(ADC0, x, y);
}

