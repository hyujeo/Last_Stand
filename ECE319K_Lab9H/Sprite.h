#ifndef LAST_STAND_SPRITE_H
#define LAST_STAND_SPRITE_H

class Sprite {
public:
    unsigned short x; // xPos = x >> 8
    unsigned short y; // yPos = y >> 8
    short vx;         // xVel = vx >> 3
    short vy;         // yVel = vy >> 3
    // xVel = 30/32 pixels/s
    //      = 1/32 pixels/interrupt
    //
    // vx = 2^-8 pixels/interrupt
    //    = x/interrupt
    // 2^3vx = 1/32 pixels/interrupt
    // 2^11vx = 8 pixels/interrupt
    unsigned short img;
    unsigned short counter;
    Sprite* next;

    Sprite(int xPos, int yPos, int xVel, int yVel, int _img) {
        x = xPos << 8;
        y = yPos << 8;
        vx = xVel << 8;
        vy = yVel << 8;
        img = _img;
        counter = 0;
        next = 0;
    }
    
};

class Background {
public:
    unsigned short x;
    unsigned short y;
    unsigned short img;
    Background() {
        x = 0;
        y = 0;
    }
    Background(int xPos, int yPos) {
        x = xPos << 8;
        y = yPos << 8;
    }
};

#endif //LAST_STAND_SPRITE_H
