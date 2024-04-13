/* SlidePot.cpp
 * Jonathan Simon, Hyunho Jeong
 * Professor: Chiou
 * EIDS: HJ8379, JES7539
 * Modified: 04/02/24
 * 12-bit ADC input on ADC1 channel 5, PB18
 */
#include <ti/devices/msp/msp.h>
#include "../inc/Clock.h"
#include "../inc/SlidePot.h"
#define ADCVREF_VDDA 0x000
#define ADCVREF_INT  0x200


void SlidePot::Init(void){
// write code to initialize ADC1 channel 5, PB18
// Your measurement will be connected to PB18
// 12-bit mode, 0 to 3.3V, right justified
// software trigger, no averaging

    // write this
    ADC1->ULLMEM.GPRCM.RSTCTL = 0xB1000003; // reset
    ADC1->ULLMEM.GPRCM.PWREN = 0x26000001; // activate
    Clock_Delay(24);
    ADC1->ULLMEM.GPRCM.CLKCFG = 0xA9000000; // ULPCLK
    ADC1->ULLMEM.CLKFREQ = 7; // 40-48 MHZ
    ADC1->ULLMEM.CTL0 = 0x03010000; //DIVIDE BY 8
    ADC1->ULLMEM.CTL1 = 0x00000000; // MODE
    ADC1->ULLMEM.CTL2 = 0x00000000; // MEMRES
    ADC1->ULLMEM.MEMCTL[0] = 5; // channel 5 is PB 18
    ADC1->ULLMEM.SCOMP0 = 0; // 8 sample clocks
    ADC1->ULLMEM.CPU_INT.IMASK = 0; // no interrupt
}

uint32_t SlidePot::In(void){
    // write code to sample ADC1 channel 5, PB18 once
    // return digital result (0 to 4095)
    ADC1->ULLMEM.CTL0 |= 0x00000001; // enable conversion
    ADC1->ULLMEM.CTL1 |= 0X00000100; // start ADC
    uint32_t volatile delay=ADC1->ULLMEM.STATUS; // give time for ADC to start (dead reckoning)
    while((ADC1->ULLMEM.STATUS&0x01) == 0x01){} // wait for completion

    return ADC1->ULLMEM.MEMRES[0]; // return 12-bit result
}


// constructor, invoked on creation of class
// m and b are linear calibration coefficents
SlidePot::SlidePot(uint32_t m, uint32_t b){
    // write this, runs on creation
    slope = m;
    offset = b;
}

void SlidePot::Save(uint32_t n){
    // write this
    data = n;
    flag = 1;
}
uint32_t SlidePot::Convert(uint32_t n){
    // write this
    // convert ADC raw sample n to fixed-point distance, 0.001cm
    distance = (n * slope + offset) / 4095;
    return distance;
}
// do not use this function
// it is added just to show you how SLOW floating point in on a Cortex M0+
float SlidePot::FloatConvert(uint32_t input){
    return 0.00048828125*input -0.0001812345;
}

void SlidePot::Sync(void){
    // write this
    // wait for semaphore, then clear semaphore
    while (!flag){
        // wait
    }
    flag = 0;
}


uint32_t SlidePot::Distance(void){  // return distance value (0 to 2000), 0.001cm
    // write this
    return distance;
}
