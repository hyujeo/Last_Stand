#ifndef SWITCH_H_
#define SWITCH_H_

#include "config.h"

class Input_Switch_Handler{
private:
    uint8_t DOWN;
    uint8_t RIGHT;
    uint8_t UP;
    uint8_t LEFT;
    uint8_t JOYSTICK;
public:
    // initialize your switches
    void Init(void);

    // return all values
    uint8_t All_Switch_In(void);

    // return current joystick button value
    uint8_t JOYSTICK_Switch_In(void);

    // return current state of left switch
    uint8_t LEFT_Switch_In(void);

    // return current state of up switch
    uint8_t UP_Switch_In(void);

    // return current state of right switch
    uint8_t RIGHT_Switch_In(void);

    // return current state of down switch
    uint8_t DOWN_Switch_In(void);
};

#endif /* SWITCH_H_ */
