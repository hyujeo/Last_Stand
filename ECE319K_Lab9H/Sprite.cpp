//
// Created by Hyunho Jeong on 4/16/24.
//

#include "Sprite.h"

Sprite::Sprite(unsigned int xPos, unsigned int yPos, int xVel, int yVel, int _img_num) {
    x = xPos << 8;
    y = yPos << 8;
    vx = xVel << 8; // TODO find correct conversion
    vy = yVel << 8;
    img_num = _img_num;
}

int Sprite::x() {
    return x >> 8;
}

int Sprite::y(){
    return y >> 8;
}

bool Sprite::update() {

}

bool Sprite::collides(Sprite other) {

}
