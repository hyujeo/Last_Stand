//
// Created by Hyunho Jeong on 4/16/24.
//

#ifndef LAST_STAND_SPRITE_H
#define LAST_STAND_SPRITE_H


class Sprite {
private:
    unsigned short x; // xPos = x >> 8
    unsigned short y; // yPos = y >> 8
    short vx;         // xVel = vx >> 8 TODO find correct conversion
    short vy;         // yVel = vy >> 8

public:
    int img_num;
    Sprite(int xPos, int yPos, int xVel, int yVel, int _img_num);

    int x();
    int y();

    bool update(); // update position with velocity. true if sprite fell off the map
    bool collides(Sprite other);
};


#endif //LAST_STAND_SPRITE_H
