#include <SpriteList.h>
#include "../inc/ST7735.h"
#include "Sound.h"

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

SpriteList spritePool;

extern BackgroundList blackRectangles;

int backVX = 0;
int backVY = 0;

void Update_Player_Speed(int joy_x, int joy_y, int factor) {
    backVX += (factor * joy_x / 128) - (backVX * FRICTION);
    backVY += (factor * joy_y / 128) - (backVY * FRICTION);
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
    spritePool.head = 0;
    for (int i = 0; i < size; i++){
        Sprite* s = new Sprite(0,0,0,0,0);
        s->next = spritePool.head;
        spritePool.head = s;
    }
}
void SpriteList::push(int xPos, int yPos, int xVel, int yVel, int img) {
    if (!spritePool.head) return;
    count++;
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
int SpriteList::collides(Sprite* s) { // to check for player collision, do: enemies.collides(player.head)
    Sprite* enemy = head;
    Sprite temp = {0,0,0,0,0};
    Sprite* prev = &temp;
    prev->next = enemy;
    while(enemy){
        int dx = s->x - enemy->x;
        int dy = s->y - enemy->y;
        int r = (spriteImages[s->img].width + spriteImages[enemy->img].width) << 7;
        if (dx*dx + dy*dy < r*(r + HITBOX)){ // collided
            switch (enemy->img){
            case ALIEN_LASER_ID: case PLAYER_LASER_ID:
                removeFromList(enemy, prev);
                enemy = prev;
                return 1;
            case ALIEN_1_ID:
                enemy->img = ALIEN_1_EXPLOSION_1_ID;
                Sound_Explosion();
                enemy->counter = 0;
                enemy->vx = 0;
                enemy->vy = 0;
                return 1;
            }
        }
        prev = enemy;
        enemy = enemy->next;
    }
    return 0;
}
int SpriteList::detectCollisions(SpriteList& enemies) {
    Sprite*s = head;
    Sprite temp = {0,0,0,0,0};
    Sprite* prev = &temp;
    prev->next = s;
    while(s){
        if (enemies.collides(s)){
            switch (s->img){
            case ALIEN_LASER_ID: case PLAYER_LASER_ID:
                removeFromList(s, prev);
                return 1;
            case ALIEN_1_ID:
                s->img = ALIEN_1_EXPLOSION_1_ID;
                Sound_Explosion();
                s->vx = 0;
                s->vy = 0;
                s->counter = 0;
                return 1;
            }
        }
        prev = s;
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
    if (s == head) head = s->next;
    count--;
    prev->next = s->next;
    s->next = spritePool.head;
    spritePool.head = s;
}
bool in_screen(Sprite* s){
    int w = spriteImages[s->img].width;
    int h = spriteImages[s->img].height;
    int x = s->x >> 8;
    int y = s->y >> 8;
    return (x+w>64 && x-w<192 && y+h>48 && y-h<208);
}
extern SpriteList alienLasers;
void SpriteList::update() {
    Sprite* s = head;
    Sprite temp = {0,0,0,0,0};
    Sprite* prev = &temp;
    prev->next = s;
    while(s){
        blackRectangles.push(s->x, s->y, s->img);
        s->x += s->vx + backVX;
        s->y += s->vy + backVY;
        s->counter++;
        switch (s->img){
        // Aliens: move towards player, shoot
        case ALIEN_1_ID:
            s->vx = (PLAYER_X - s->x) / 64;
            s->vy = (PLAYER_Y - s->y) / 64;
            if (s->counter > ALIEN_LASER_COOLDOWN && in_screen(s)){
                s->counter = 0;
                int xvel = s->vx;
                int yvel = s->vy;
                if (xvel == 0) xvel = 1;
                // make velocity bigger than alien_laser_speed
                while (xvel*xvel + yvel*yvel < ALIEN_LASER_SPEED*ALIEN_LASER_SPEED){
                    xvel *= 2;
                    yvel *= 2;
                } // velocity at most 2*alien_laser_speed 
                while (xvel*xvel + yvel*yvel > 4*ALIEN_LASER_SPEED*ALIEN_LASER_SPEED){
                    xvel /= 2;
                    yvel /= 2;
                } // subtract from velocity until it equals alien_laser_speed
                int xsub = xvel / 16; // subtract at most 64 times
                int ysub = yvel / 16;
                while (xvel*xvel + yvel*yvel > ALIEN_LASER_SPEED*ALIEN_LASER_SPEED){
                    xvel -= xsub;
                    yvel -= ysub;
                }
                alienLasers.push(s->x >> 8, s->y >> 8, xvel, yvel, ALIEN_LASER_ID);
            }
            break;
        // Lasers: remove when going out of bounds, instead of wrapping around
        case PLAYER_LASER_ID: case ALIEN_LASER_ID:
            // player screen's boundary is 64<x<192, 48<y<208
            if (!in_screen(s)){
                removeFromList(s, prev);
                s = prev;
            } 
            break;
        case ALIEN_1_EXPLOSION_1_ID ... ALIEN_1_EXPLOSION_3_ID:
            if (s->counter == 7){
                s->counter = 0;
                s->img++;
            }
            break;
        case ALIEN_1_EXPLOSION_4_ID:
            if (s->counter == 7){
                removeFromList(s, prev);
                s = prev;
            }
            break;
        default: break;
        } 
        // all sprites must change speed based on player speed
        prev = s;
        s = s->next;
    }
}
void SpriteList::clear(){
    Sprite* s = head;
    Sprite temp = {0,0,0,0,0};
    Sprite* prev = &temp;
    prev->next = s;
    while(s){
        removeFromList(s, prev);
        s = prev;
        s = s->next;
    }
    head = 0;
}




void BackgroundList::init(int _size) {
    size = _size;
    length = 0;
    array = new Background[size];
}

void BackgroundList::push(int x, int y, int img) {
    if (length >= size) return;
    array[length].x = x;
    array[length].y = y;
    array[length].img = img;
    length++;
}

void BackgroundList::update() {
    for (int i = 0; i < MAX_BACKGROUND; i++){
        blackRectangles.push(array[i].x, array[i].y, array[i].img);
        array[i].x += backVX / BACKGROUND_RELATIVE_SPEED;
        array[i].y += backVY / BACKGROUND_RELATIVE_SPEED;
    }
}

void BackgroundList::draw(char mode) {
    for (int i = 0; i < length; i++){
        Background b = array[i];
        int xPix = (b.x >> 8) - 64;
        int yPix = (b.y >> 8) - 48;
        int width = spriteImages[b.img].width;
        int height = spriteImages[b.img].height;
        if (mode == 'B'){
            ST7735_FillRect(xPix - (width >> 1), yPix - (height >> 1), width, height + 1, ST7735_BLACK);
        } else if (mode == 'I'){
            ST7735_DrawBitmap(xPix - (width >> 1), yPix + (height >> 1), spriteImages[b.img].array, width, height);
        }
    }
}

