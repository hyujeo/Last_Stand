// Sound.cpp
// Runs on MSPM0
// Sound assets in sounds/sounds.h
// Jonathan Valvano
// 11/15/2021 
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "Sound.h"
#include "sounds/sounds.h"
#include "../inc/DAC5.h"
#include "../inc/Timer.h"

// arrays for capability to add sound waves
const uint8_t* pointer_to_sound[3] = {shoot+4080, explosion+8731, ufo_highpitch_menu+1802}; // array of sound wave pointers pointing to last element+1
int32_t sound_positions[3] = {0, 0, 0}; // finished when at position 0

int8_t non_zero_values; // avoids having to iterate

//uint32_t sound_count;
//uint32_t current_sound_position;

void SysTick_IntArm(uint32_t period, uint32_t priority){
  // write this
    SysTick->CTRL = 0x00; // disable during initialization
    SysTick->LOAD = period-1; // set reload register
    SCB->SHP[1] = (SCB->SHP[1] & (~0xC0000000)) | priority<<30;
    SysTick->VAL = 0; // clear count, cause reload
    SysTick->CTRL = 0x07; // Enable SysTick IRQ and SysTick Timer
}
// initialize a 11kHz SysTick, however no sound should be started
// initialize any global variables
// Initialize the 5 bit DAC
void Sound_Init(void){
// write this
    DAC5_Init();

    //current_sound_position = 0;
    //sound_count = 0;
    //pointer_to_sound = 0;
    non_zero_values = 0;

    SysTick_IntArm(7272, 2); // 11kHz wave with priority 2
}
extern "C" void SysTick_Handler(void);
void SysTick_Handler(void){ // called at 11 kHz
    // output one value to DAC if a sound is active
   if(non_zero_values > 0){
       uint32_t output = 0;
       for(int i = 0; i < 3;i++){
           if(sound_positions[i] != 0){
               output+=(pointer_to_sound[i][-1*sound_positions[i]])/non_zero_values; // gather sum of active sound waves
               sound_positions[i]-=1;
               if(sound_positions[i]<=0){
                   non_zero_values--;
               }
           }
       }
       DAC5_Out(output);
       //current_sound_position++;
   }
   if(non_zero_values <= 0){
       SysTick->CTRL = 0x00; // stop if no sound values
   }
}

//******* Sound_Start ************
// This function does not output to the DAC. 
// Rather, it sets a pointer and counter, and then enables the SysTick interrupt.
// It starts the sound, and the SysTick ISR does the output
// feel free to change the parameters
// Sound should play once and stop
// Input: pt is a pointer to an array of DAC outputs
//        count is the length of the array
// Output: none
// special cases: as you wish to implement
void Sound_Start(uint32_t pos_index, int32_t resolution){
// write this
    //pointer_to_sound = pt;
    //sound_count = count;
    //current_sound_position = 0;
    if(sound_positions[pos_index] <= 0){
        non_zero_values++;
    }
    sound_positions[pos_index] = resolution;
    if((non_zero_values-1) <= 0){
        SysTick->CTRL = 0x00; // turn off during modifications
        SysTick->VAL = 0; // clear count, cause reload
        SysTick->CTRL = 0x07; // Enable SysTick IRQ and SysTick Timer
    }
}
// not used lol
void Sound_Stop(void){
    SysTick->CTRL = 0x00;
}
void Sound_Shoot(void){
// write this
    Sound_Start(0, 4080);
}
void Sound_Explosion(void){
// write this
    Sound_Start(1, 8731);
}
void Sound_Ufo_Highpitch_Menu(void){
    Sound_Start(2, 1802);
}

