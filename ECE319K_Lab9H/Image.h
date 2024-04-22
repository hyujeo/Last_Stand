#ifndef LAST_STAND_IMAGE_H
#define LAST_STAND_IMAGE_H

class Image {
public:
    const unsigned short* array;
    unsigned short width;
    unsigned short height;
};

const unsigned short playerOff[] = { // 19x14
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

const unsigned short playerOn[] = { // 19x14
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

const unsigned short alien1[] = {
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


const unsigned short alienLaser[] = { // 10x10
 0x0000, 0x0000, 0x20FD, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0018, 0x0018,
 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD,
 0x0018, 0x0018, 0x0013, 0x0013, 0x0018, 0x0018, 0x0000, 0x0018, 0x20FD, 0x0018, 0x0018, 0x0013, 0x0013, 0x0013, 0x0013, 0x0018,
 0x0018, 0x0018, 0x0018, 0x0018, 0x0018, 0x0013, 0x0013, 0x0013, 0x0013, 0x0018, 0x0018, 0x20FD, 0x0018, 0x0000, 0x0018, 0x0018,
 0x0013, 0x0013, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0018, 0x0018, 0x20FD, 0x0000, 0x20FD,
 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018, 0x0018, 0x0000, 0x0000, 0x20FD, 0x0000, 0x0000, 0x0000, 0x20FD, 0x0000, 0x20FD, 0x0018,
 0x0018, 0x20FD, 0x0000, 0x0000,
};

const unsigned short playerLaser[] = { // 10x10
 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0xCE40, 0xE700, 0xE700,
 0xCE40, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xE700, 0x7BC0, 0x0000, 0x0000, 0xCE40,
 0xFFE0, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFE0, 0xFFE0, 0xCE40, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFE0,
 0xE700, 0x7BC0, 0x7BC0, 0xE700, 0xFFE0, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFE0, 0xE700, 0x7BC0, 0x0000, 0xCE40, 0xFFE0, 0xFFE0,
 0xFFFF, 0xFFFF, 0xFFE0, 0xFFE0, 0xCE40, 0x0000, 0x0000, 0x7BC0, 0xE700, 0xFFE0, 0xFFE0, 0xFFE0, 0xFFE0, 0xE700, 0x7BC0, 0x0000,
 0x0000, 0x0000, 0x7BC0, 0xCE40, 0xE700, 0xE700, 0xCE40, 0x7BC0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7BC0, 0x7BC0,
 0x0000, 0x0000, 0x0000, 0x0000,
};

#endif // LAST_STAND_IMAGE_H
