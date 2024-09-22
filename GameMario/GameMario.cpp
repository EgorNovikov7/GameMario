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

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("\n");
}

 