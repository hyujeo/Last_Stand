#ifndef LAST_STAND_IMAGE_H
#define LAST_STAND_IMAGE_H

class Image {
public:
    const unsigned short* array;
    unsigned short width;
    unsigned short height;
};

const unsigned short player_off[] = { // 19x14
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1082, 0x39C7, 0x4208, 0x7BEF, 0xC618, 0xC618,
 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0x7BEF, 0x4208, 0x39C7, 0x1082, 0x0000, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20,
 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20, 0x5ACB, 0x0000,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618,
 0xC618, 0xC618, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3, 0xEAA0, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3,
 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short player_on[] = { // 19x14
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEF20, 0xEF20, 0xEF20, 0xEF20, 0xEF20, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1082, 0x39C7, 0x4208, 0x7BEF, 0xC618, 0xC618,
 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0x7BEF, 0x4208, 0x39C7, 0x1082, 0x0000, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20,
 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20, 0x5ACB, 0x0000,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618,
 0xC618, 0xC618, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3, 0xEAA0, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3,
 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short alien_1[] = { // 15x15
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0xC618, 0x7BEF, 0xC618, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x7BEF, 0x4A69, 0x7BEF, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618,
 0x7BEF, 0x4A69, 0x20FD, 0x4A69, 0x7BEF, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0xC618, 0x7BEF, 0x4A69,
 0x20FD, 0x20FD, 0x20FD, 0x4A69, 0x7BEF, 0xC618, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x7BEF, 0x7BEF, 0x4A69, 0x20FD, 0x20FD,
 0x20FD, 0x20FD, 0x20FD, 0x4A69, 0x7BEF, 0x7BEF, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0xC618, 0x7BEF, 0x4A69, 0x20FD, 0x20FD,
 0x20FD, 0x4A69, 0x7BEF, 0xC618, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x7BEF, 0x4A69, 0x20FD, 0x4A69,
 0x7BEF, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x7BEF, 0x4A69, 0x7BEF, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0xC618, 0x7BEF, 0xC618, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000,
};


const unsigned short alien_laser[] = { // 10x10
 0x0000, 0x0000, 0x20FD, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0018, 0x0018,
 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD,
 0x0018, 0x0018, 0x0013, 0x0013, 0x0018, 0x0018, 0x0000, 0x0018, 0x20FD, 0x0018, 0x0018, 0x0013, 0x0013, 0x0013, 0x0013, 0x0018,
 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0013, 0x0013, 0x0013, 0x0013, 0x0018, 0x0018, 0x20FD, 0x0018, 0x0000, 0x0018, 0x0018,
 0x0013, 0x0013, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD,
 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018,
 0x0018, 0x20FD, 0x0000, 0x0000,
};

const unsigned short player_laser[] = { // 10x10
 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0xCE40, 0xE700, 0xE700,
 0xCE40, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xE700, 0x7BC0, 0x0000, 0x0000, 0xCE40,
 0xFFE0, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFE0, 0xFFE0, 0xCE40, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFE0,
 0xE700, 0x7BC0, 0x7BC0, 0xE700, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFE0, 0xE700, 0x7BC0, 0x0000, 0xCE40, 0xFFE0, 0xFFE0,
 0xFFFF, 0xFFFF, 0xFFE0, 0xFFE0, 0xCE40, 0x0000, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xE700, 0x7BC0, 0x0000,
 0x0000, 0x0000, 0x7BC0, 0xCE40, 0xE700, 0xE700, 0xCE40, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0x7BC0,
 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short alien_1_explosion_1[] = { // 15x15
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618,
 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x23FF,
 0x23FF, 0x079F, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF,
 0x079F, 0xFFFF, 0x079F, 0x079F, 0x23FF, 0x23FF, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x079F, 0x079F,
 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x23FF, 0x23FF, 0x079F, 0xFFFF, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x23FF, 0x23FF, 0x0000, 0x0000, 0xC618, 0x20FD, 0x23FF, 0x23FF, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF,
 0xFFFF, 0xFFFF, 0x079F, 0x079F, 0x23FF, 0x7BEF, 0xC618, 0x20FD, 0xC618, 0x0000, 0x20FD, 0x23FF, 0x23FF, 0x079F, 0x079F, 0xFFFF,
 0x079F, 0x079F, 0x079F, 0x23FF, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF,
 0x23FF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0x20FD, 0x20FD, 0x23FF, 0x20FD, 0x23FF,
 0x20FD, 0x23FF, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0xC618, 0x7BEF, 0xC618, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618,
 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x20FD, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000,
};

const unsigned short alien_1_explosion_2[] = { // 15x15
 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x20FD, 0x20FD, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD,
 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x079F, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x23FF,
 0x079F, 0x079F, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x079F, 0x23FF,
 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x23FF, 0x23FF, 0x20FD, 0x079F, 0x079F, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x079F, 0x079F, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x23FF, 0x079F, 0x079F, 0x20FD, 0x0000, 0x20FD, 0x20FD, 0x23FF, 0x079F, 0xFFFF, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x23FF, 0x079F, 0x20FD, 0x20FD, 0x20FD, 0x079F, 0x23FF, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x23FF, 0x079F, 0x23FF, 0x20FD, 0x20FD, 0x079F, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x079F, 0x23FF, 0x20FD, 0x20FD, 0x079F, 0x079F, 0x23FF, 0x23FF, 0xFFFF, 0x079F, 0x079F, 0x079F,
 0x079F, 0x079F, 0x079F, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x079F, 0x079F, 0x23FF, 0x23FF, 0x20FD, 0x079F, 0x079F, 0x079F,
 0x23FF, 0x23FF, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x079F, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF,
 0x20FD, 0x079F, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x079F, 0x23FF, 0x23FF, 0x20FD,
 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x20FD, 0x20FD, 0x079F, 0x20FD, 0x20FD, 0x23FF, 0x20FD, 0x20FD, 0x23FF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000,
 0x0000,
};

const unsigned short alien_1_explosion_3[] = { // 15x15
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
 0x20FD, 0xFFFF, 0xFFFF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0xFFFF, 0x20FD, 0x0000, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x20FD, 0x0000, 0xFFFF, 0x20FD, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x20FD, 0x0000, 0xFFFF, 0x20FD, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F, 0xFFFF, 0x20FD, 0xFFFF, 0x079F, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x079F, 0xFFFF, 0x20FD, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x20FD, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFFF, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF,
 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x20FD, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x20FD, 0x0000, 0x0000, 0x0000,
 0x0000,
};

const unsigned short alien_1_explosion_4[] = { // 15x15
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x7BEF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x7BEF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000,
};

const unsigned short ship_explosion_1[] = {  // 19x14
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEF20, 0xEF20, 0xEF20, 0xEF20, 0xEF20, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB, 0x5ACB,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1082, 0x39C7, 0x4208, 0x7BEF, 0xC618, 0xC618,
 0xC618, 0x23FF, 0xC618, 0xC618, 0xC618, 0xC618, 0xC618, 0x7BEF, 0x4208, 0x39C7, 0x1082, 0x0000, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20,
 0x5ACB, 0x5ACB, 0x5ACB, 0x23FF, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20, 0x5ACB, 0x0000,
 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF, 0x23FF, 0x079F, 0x23FF, 0x079F, 0x23FF, 0x23FF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x0000, 0x0000, 0x0000, 0xC618, 0xC618, 0xC618, 0xC618, 0x23FF, 0x079F, 0x079F, 0xFFFF, 0x23FF, 0x079F, 0x23FF, 0xC618,
 0xC618, 0xC618, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0x23FF, 0x079F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF,
 0x23FF, 0x23FF, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0x23FF, 0x23FF, 0x079F,
 0x079F, 0xFFFF, 0x23FF, 0x079F, 0x23FF, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0x23FF, 0x079F, 0x079F, 0x079F, 0x23FF, 0xEAA0, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0x23FF, 0x23FF, 0x23FF, 0xEAA0, 0xEED3, 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3, 0xEAA0, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0, 0xEAA0, 0xEAA0, 0xEAA0, 0xEED3, 0xEED3,
 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEAA0,
 0xEAA0, 0xEAA0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short ship_explosion_2[] = { // 19x14
 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEF20, 0x20FD, 0x20FD, 0x20FD, 0xEF20, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5ACB, 0x20FD, 0x20FD, 0x23FF, 0x20FD, 0x5ACB, 0x5ACB,
 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x23FF, 0x20FD, 0x23FF, 0x23FF,
 0x23FF, 0x20FD, 0x7BEF, 0x7BEF, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x1082, 0x39C7, 0x4208, 0x20FD, 0x20FD, 0x23FF,
 0x23FF, 0x079F, 0x23FF, 0x23FF, 0x23FF, 0x20FD, 0xC618, 0x7BEF, 0x4208, 0x39C7, 0x1082, 0x0000, 0x5ACB, 0xEF20, 0x5ACB, 0x20FD,
 0x5ACB, 0x23FF, 0x23FF, 0x079F, 0x079F, 0x079F, 0x079F, 0x23FF, 0x5ACB, 0x5ACB, 0x5ACB, 0xEF20, 0x5ACB, 0xEF20, 0x5ACB, 0x0000,
 0x7BEF, 0x7BEF, 0x20FD, 0x7BEF, 0x7BEF, 0x23FF, 0x079F, 0x079F, 0xFFFF, 0x079F, 0x23FF, 0x23FF, 0x7BEF, 0x7BEF, 0x7BEF, 0x7BEF,
 0x7BEF, 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD, 0xC618, 0x23FF, 0x079F, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x23FF, 0x23FF,
 0x23FF, 0x23FF, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x23FF, 0x23FF, 0x079F, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
 0xFFFF, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x23FF, 0x079F, 0x23FF, 0x079F,
 0xFFFF, 0xFFFF, 0xFFFF, 0x079F, 0x23FF, 0x20FD, 0x20FD, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF,
 0x23FF, 0x23FF, 0x23FF, 0x079F, 0xFFFF, 0x079F, 0x079F, 0x20FD, 0xEAA0, 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x20FD, 0x0000, 0xEAA0, 0x20FD, 0x23FF, 0x079F, 0x079F, 0x079F, 0x079F, 0x079F, 0x20FD, 0x20FD, 0xEAA0, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0xEAA0, 0x0000,
 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD, 0x23FF, 0x23FF, 0x20FD, 0xEED3,
 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x20FD,
 0x20FD, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short ship_explosion_3[] = { // 19x14
 0x20FD, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x23FF, 0x23FF, 0x23FF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0xFFFF, 0xFFFF, 0x23FF, 0x23FF, 0x20FD, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x1082, 0x23FF, 0x4208, 0xFFFF, 0x20FD, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BEF, 0xFFFF, 0x23FF, 0x1082, 0x0000, 0x5ACB, 0xEF20, 0x23FF, 0xFFFF,
 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x23FF, 0x23FF, 0x5ACB, 0x0000,
 0x7BEF, 0x23FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x7BEF,
 0x23FF, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xFFFF, 0xC618, 0x23FF, 0x0000, 0x0000, 0x0000, 0x23FF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x23FF, 0xFFFF, 0x23FF, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x20FD, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000,
 0x20FD, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x23FF, 0x23FF, 0x0000, 0x0000,
 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x23FF, 0x23FF, 0x23FF,
 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x23FF,
 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x23FF, 0x23FF, 0x23FF,
 0x23FF, 0x23FF, 0x23FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short ship_explosion_4[] = { // 19x14
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0xC618, 0xC618, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xC618, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

const unsigned short star_big[] = { // 5x5
 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
};

const unsigned short star_small[] = { // 1x1
    0xFFFF,
};






#endif // LAST_STAND_IMAGE_H
