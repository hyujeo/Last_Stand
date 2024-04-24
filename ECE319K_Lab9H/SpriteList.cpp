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
    if (s == head) head = s->next;
    prev->next = s->next;
    s->next = spritePool.head;
    spritePool.head = s;
}

void SpriteList::update() {
    Sprite* s = head;
    Sprite temp = {0,0,0,0,0};
    Sprite* prev = &temp;
    prev->next = s;
    int xpos, ypos;
    while(s){
        blackRectangles.push(s->x, s->y, s->img);
        s->x += s->vx + backVX;
        s->y += s->vy + backVY;
        switch (s->img){
        // Lasers: remove when going out of bounds, instead of wrapping around
        case PLAYER_LASER_ID: case ALIEN_LASER_ID:
            // player screen's boundary is 64<x<192, 48<y<208
            xpos = s->x >> 8;
            ypos = s->y >> 8;
            if (xpos < 64-15 || xpos > 192+15 || ypos < 48-15 || ypos > 208+15){
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

