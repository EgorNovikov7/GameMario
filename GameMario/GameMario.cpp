#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 

struct Mario {
    float x;
    float y;
    int width;
    int weight;
    int lives;
    int state;
    int isJump;
};

struct Platform {
    float x;
    float y;
    int with;
    int height;
    int type;

};

struct Enemy {
    float x;
    float y;
    int width;
    int weight;
    int state;
};

struct Coin{
    float x;
    float y;
    int collected;
};

struct Star
{
    float x;
    float y;
    int collected;
};

struct Key
{
    float x;
    float y;

};

struct Door {
    float x;
    float y;
    int width;
    int height;
    int locked;
};

struct Map{
    int x, y;
    float width;
    float weight;
    float scrollSpeed;
};

void initMario(struct Mario* mario, float x, float y, int width, int weight, int lives, int state, int isJump) {
    mario->x = x;
    mario->y = y;
    mario->width = width;
    mario->weight = weight;
    mario->lives = lives;
    mario->state = state;
    mario->isJump = isJump;
}

void updateMario(struct Mario* mario, float dx, float dy) {
    mario->x += dx;
    mario->y += dy;
}

void printMario(struct Mario* mario) {
    printf("Mario position: (%.2f, %.2f), width: %d, weight: %d, lives: %d, state: %d, isJump: %d\n",
        mario->x, mario->y, mario->width, mario->weight, mario->lives, mario->state, mario->isJump);
}

void initPlatform(struct Platform* platform, float x, float y, int with, int height, int type) {
    platform->x = x;
    platform->y = y;
    platform->with = with;
    platform->height = height;
    platform->type = type;
}

void printPlatform(struct Platform* platform) {
    printf("Platform position: (%.2f, %.2f), width: %d, height: %d, type: %d\n",
        platform->x, platform->y, platform->with, platform->height, platform->type);
}

 

int main()
{
    setlocale(LC_ALL, "Rus");
    struct Mario mario;
    initMario(&mario, 0.0f, 0.0f, 10, 20, 3, 1, 0);
    printMario(&mario);
    struct Platform platform;
    initPlatform(&platform, 10.0f, 5.0f, 50, 10, 1);
    printPlatform(&platform);
    printf("\n");
}

 