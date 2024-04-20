/*
 * Switch.h
 *
 *  Created on: Nov 5, 2023
 *      Author: jonat
 */

#ifndef SWITCH_H_
#define SWITCH_H_

// initialize your switches
void Switch_Init(void);

// return all values
uint32_t Switch_In(void);

// return current joystick button value
uint32_t JOYSTICK_Switch_In(void);

// return current state of left switch
uint32_t LEFT_Switch_In(void);

// return current state of up switch
uint32_t UP_Switch_In(void);

// return current state of right switch
uint32_t RIGHT_Switch_In(void);

// return current state of down switch
uint32_t DOWN_Switch_In(void);

#endif /* SWITCH_H_ */
