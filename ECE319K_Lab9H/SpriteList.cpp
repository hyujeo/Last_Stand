#include <SpriteList.h>
#include "../inc/ST7735.h"

    // xPos = x >> 8
    // yPos = y >> 8
    // xVel = vx >> 3
    // yVel = vy >> 3
    // xVel = 30/32 pixels/s
    //      = 1/32 pixels/interrupt
    //
    // vx = 2^-8 pixels/interrupt
    //    = x/interrupt
    // 2^3vx = 1/32 pixels/interrupt
    // 2^11vx = 8 pixels/interrupt

static SpriteList spritePool;

extern BackgroundList blackRectangles;

short playerVX = 0;
short playerVY = 0;
int playerAX = 0;
int playerAY = 0;
int accelerationFactor = 0;

void Update_Player_Speed(int joy_x, int joy_y, int factor) {
    // TODO
}
Image spriteImages[] = {
    {player_off, 19, 14}, // 0
    {player_on, 19, 14},
    {star_small, 1, 1},
    {star_big, 5, 5},
    {alien_1, 15, 15}, // 4
    {0,0,0},
    {0,0,0},
    {0,0,0},
    {player_laser, 10, 10}, // 8
    {alien_laser, 10, 10},
    {0,0,0},
    {0,0,0},
    {alien_1_explosion_1, 15, 15}, // 12
    {alien_1_explosion_2, 15, 15},
    {alien_1_explosion_3, 15, 15},
    {alien_1_explosion_4, 15, 15},
    {player_explosion_1, 19, 14}, // 16
    {player_explosion_2, 19, 14},
    {player_explosion_3, 19, 14},
    {player_explosion_4, 19, 14},
};
void SpriteList::Init(int size){
    for (int i = 0; i < size; i++){
        Sprite* s = new Sprite(0,0,0,0,0);
        s->next = spritePool.head;
        spritePool.head = s;
    }
}
void SpriteList::push(int xPos, int yPos, int xVel, int yVel, int img) {
    if (!spritePool.head) return;

    Sprite* s = spritePool.head;
    s->x = xPos << 8;
    s->y = yPos << 8;
    s->vx = xVel << 3;
    s->vy = yVel << 3;
    s->img = img;

    spritePool.head = spritePool.head->next;
    s->next = head;
    head = s;
}
int SpriteList::collides(Sprite* s) { // to check for player collision, do: enemies.collides(&player)
    Sprite* enemy = head;
    Sprite* prev = 0;
    while(enemy){
        int dx = s->x - enemy->x;
        int dy = s->y - enemy->y;
        int r = spriteImages[s->img].width + spriteImages[enemy->img].width;
        if (dx*dx + dy*dy < r*(r + HITBOX)){ // collided
            switch (enemy->img){
            case ALIEN_LASER_ID:
                this->removeFromList(enemy, prev);
                enemy = prev;
                break;
            case ALIEN_1_ID:
                enemy->img = ALIEN_1_EXPLOSION_1_ID;
                break;
            }
            return 1;
        }
        enemy = enemy->next;
    }
    return 0;
}
int SpriteList::detectCollisions(SpriteList& enemies) {
    Sprite*s = head;
    Sprite* prev = 0;
    while(s){
        int c = enemies.collides(s);
        if (c){
            removeFromList(s, prev);
            return 1;
        }
        s = s->next;
    }
    return 0;
}
void SpriteList::draw() {
    Sprite* s = head;
    while(s){
    short width = spriteImages[s->img].width;
    short height = spriteImages[s->img].height;
    short xPix = (s->x >> 8) - 64;
    short yPix = (s->y >> 8) - 48;
    ST7735_DrawSprite(xPix - (width >> 1), yPix + (height >> 1), spriteImages[s->img].array, width, height);
    s = s->next;
  }
}
void SpriteList::removeFromList(Sprite* s, Sprite* prev) {
    if (prev){
        prev->next = s->next;
    } else {
        head = s->next;
    }
    s->next = spritePool.head;
    spritePool.head = s;
}

void SpriteList::update(BackgroundList* garbageCollector) {
    Sprite* s = head;
    while(s){
        switch (s->img){
        case ALIEN_1_ID:
            int current_x = (s->x>>8);
            int current_y = (s->y>>8);
            int difference_x = 128 - current_x;
            int difference_y = 128 - current_y;
            if(difference_x < 0){ // right side of screen
                s->x = (current_x-1)<<8;
            }else if(difference_x > 0){
                s->x = (current_x+1)<<8;
            }
            if(difference_y < 0){
                s->y = (current_y-1)<<8;
            }else if(difference_y > 0){
                s->y = (current_y+1)<<8;
            }
            //garbageCollector->push(current_x, current_y, ALIEN_1_ID);
            break;
        }
        s = s->next;
    }
}

void BackgroundList::init(int _size) {
    size = _size;
    length = 0;
    array = new Background[_size];
}

void BackgroundList::push(int xPos, int yPos, int img) {
    if (length >= size) return;
    array[length].x = xPos << 8;
    array[length].y = yPos << 8;
    array[length].img = img;
    length++;
}

void BackgroundList::draw(char mode) {
    for (int i = 0; i < length; i++){
        Background b = array[i];
        signed char xPix = (b.x >> 8) - 64;
        signed char yPix = (b.y >> 8) - 48;
        short width = spriteImages[b.img].width;
        short height = spriteImages[b.img].height;
        if (mode == 'B'){
            ST7735_FillRect(xPix - (width >> 1), yPix + (height >> 1), width, height, ST7735_BLACK);
        } else if (mode == 'I'){
            ST7735_DrawBitmap(xPix - (width >> 1), yPix + (height >> 1), spriteImages[b.img].array, width, height);
        }
    }
}

