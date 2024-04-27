#ifndef LAST_STAND_SPRITELIST_H
#define LAST_STAND_SPRITELIST_H

#include "Sprite.h"
#include "config.h"
#include "Image.h"

/*
bool Player::update()
{
    playerVX += playerAX - ((playerVX * playerVX) >> friction);
    playerVY += playerAY - ((playerVY * playerVY) >> friction);
}
*/

void Update_Player_Speed(int joy_x, int joy_y, int factor);

class BackgroundList {
    // update position according to player speed
public:
    int size = 0;
    int length = 0;
    Background* array;
    void init(int size);
    void push(int xPos, int yPos, int img);
    void update();
    void draw(char mode);
};

class SpriteList {
public:
    Sprite* head = 0;
    int count = 0;

    // allocate to the spritePool
    static void Init(int size);

    // take sprites from spritePool
    void push(int xPos, int yPos, int xVel, int yVel, int img);

    // return 1 if collides, 0 otherwise
    int collides(Sprite* enemy);

    // return 1 if collision exists between two lists, 0 otherwise
    // elements of both may be altered/removed:
    //    remove laser
    //    change alien to exploded image
    // called by alien
    int detectCollisions(SpriteList& enemies);

    // update sprite positions according to sprite speed
    // push previous position to blackRectangles
    // change sprite speed according to sprite movement logic and player speed
    // incrememt counter if exploded image
    // remove sprite if counter > explosion duration
    void update();

    // draw all sprites
    void draw();

    // return all sprites to spritePool
    void clear();

private:

    // remove s from list
    void removeFromList(Sprite* s, Sprite* prev);
};

#endif // LAST_STAND_SPRITELIST_H
