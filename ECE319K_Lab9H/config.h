#ifndef LAST_STAND_CONFIG_H
#define LAST_STAND_CONFIG_H

// increase friction to decrease max speed
#define FRICTION 11

// player coordinates in 128x128, with << 8 to fit Sprite standards
// adjust player location on screen
#define PLAYER_X 64 << 8
#define PLAYER_Y 64 << 8

// default = 0, increase to 
#define HITBOX 0

// list of image numbers, as indices in Image.h::images
#define ALIEN1_ID           4
#define ALIEN_LASER_ID      9
#define ALIEN_EXPLOSION1_ID 12

// number of backgrounds, number of total objects = sprites + backgrounds
#define NUM_BACKGROUND 100
#define NUM_OBJECTS    250

#endif //LAST_STAND_CONFIG_H