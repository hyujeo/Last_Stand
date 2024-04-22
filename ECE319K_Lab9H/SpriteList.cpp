#include <SpriteList.h>
#include "../inc/ST7735.h"

extern BackgroundList blackRectangles;
short playerVX = 0;
short playerVY = 0;
int playerAX = 0;
int playerAY = 0;
int accelerationFactor = 0;

Image spriteImages[] = {
    {playerOff, 19, 14}, // 0
    {playerOn, 19, 14},
    {0,0,0},
    {0,0,0},
    {alien1, 15, 15}, // 4
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {playerLaser, 10, 10}, // 8
    {alienLaser, 10, 10},
    {0,0,0},
    {0,0,0},/*
    {alienExplosion1, , } // 12
    {alienExplosion2, , }
    {alienExplosion3, , }
    {alienExplosion4, , }*/
};

int SpriteList::collides(Sprite* s) { // to check for player collision, do: enemies.collides(&player)
    Sprite* enemy = head;
    Sprite* prev = 0;
    while(enemy){
        if (enemy->x){} // TODO
        int dx = s->x - enemy->x;
        int dy = s->y - enemy->y;
        int r = spriteImages[s->img].width + spriteImages[enemy->img].width;
        if (dx*dx + dy*dy < r*(r + HITBOX)){ // collided
            if (enemy->img == ALIEN_LASER_ID) { // remove laser
                this->removeFromList(enemy, prev);
                enemy = prev;
            }
            else if (enemy->img == ALIEN1_ID) { // change alien to exploded state
                enemy->img = ALIEN_EXPLOSION1_ID;
            }
            return 1;
        }
        enemy = enemy->next;
    }
    return 0;
}
int SpriteList::detectCollisions(SpriteList& enemies) {
    int collisions = 0;
    Sprite*s = head;
    Sprite* prev = 0;
    while(s){
        
        collisions += enemies.collides(s);
    }
    return collisions;
}
void SpriteList::draw() {
    Sprite* s = head;
    while(s){
    short width = spriteImages[s->img].width;
    short height = spriteImages[s->img].height;
    short xPix = s->x >> 8;
    short yPix = (s->y >> 8) + 16;
    ST7735_DrawBitmap(xPix - (width >> 1), yPix + (height >> 1), spriteImages[s->img].array, width, height);
    s = s->next;
  }
}
void SpriteList::push(int xPos, int yPos, int xVel, int yVel, int img) {
    Sprite* sprite = new Sprite(xPos, yPos, xVel, yVel, img);
    sprite->next = head;
    head = sprite;
}
void SpriteList::removeFromList(Sprite* s, Sprite* prev) {
    if (prev){
        prev->next = s->next;
    } else {
        head = s->next;
    }
    delete s;
}
void SpriteList::update() {
    Sprite* s = head;
    while(head){
        
    }
}

void BackgroundList::draw(char mode) {
    for (int i = 0; i < size; i++){
        Background b = array[i];
        short xPix = b.x >> 8;
        short yPix = (b.y >> 8) + 16;
        short width = spriteImages[b.img].width;
        short height = spriteImages[b.img].height;
        if (mode == 'B'){
            ST7735_FillRect(xPix - (width >> 1), yPix + (height >> 1), width, height, ST7735_BLACK);
        } else if (mode == 'I'){
            ST7735_DrawBitmap(xPix - (width >> 1), yPix + (height >> 1), spriteImages[b.img].array, width, height);
        }
    }
}
void BackgroundList::init(int _size) {
    size = _size;
    array = new Background[size];
}

