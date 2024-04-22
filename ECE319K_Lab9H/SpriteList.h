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

class SpriteList {
public:
    Sprite* head = 0;

    // create new sprite at head
    void push(int xPos, int yPos, int xVel, int yVel, int img);

    // if any element collided with player, return 1. else 0
    // when collision happens:
    //    remove laser
    //    change alien to exploded image
    int playerCollision(Sprite player);

    // return 1 if collides, 0 otherwise
    int collides(Sprite* enemy);

    // count the number of collisions that happened between the two lists
    // when collision happens:
    //    remove laser
    //    change alien to exploded image
    int detectCollisions(SpriteList& enemies);

    // update sprite positions according to sprite speed
    // push previous position to blackRectangles
    // change sprite speed according to sprite movement logic and player speed
    // incrememt counter if exploded image
    // remove sprite if counter > explosion duration
    void update();

    void draw();

private:

    // remove s from list
    void removeFromList(Sprite* s, Sprite* prev);
};

class BackgroundList {
    // update position according to player speed
public:
    int size = 0;
    Background* array;
    void init(int size);
    void update();
    void draw(char mode);
};

#endif // LAST_STAND_SPRITELIST_H