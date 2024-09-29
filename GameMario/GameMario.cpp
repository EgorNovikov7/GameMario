#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Описание главного персонажа
struct Mario {
    float x; // Координаты по x
    float y; // Координаты по y
    int width; // Рост
    int weight; // Вес
    int lives; // Количестов жизней
    int state; // Начальное состояни
    int isJump;// Не прыгает
};

// Функции для работы с персонажем
struct Mario initMario(float x, float y, int width, int weight, int lives) {
    struct Mario mario;
    mario.x = x; 
    mario.y = y;   
    mario.width = width;   
    mario.weight = weight; 
    mario.lives = lives;  
    mario.state = 0;  
    mario.isJump = 0;  
    return mario;  
}

void printMario(struct Mario mario) {  
    printf("Информация об игроке:\n" );
    printf("Расположение по x: %f\n", mario.x);
    printf("Расположение по y: %f\n", mario.y);
    printf("Высота: %d\n", mario.width);
    printf("Ширина: %d\n", mario.weight);
    printf("Количество жизней %d\n", mario.lives);
    printf("\n");
}


// Описание платфор с которыми взаимодействует персонаж
struct Platform {
    float x;
    float y;
    int width;
    int height;
    int type;
};

// Функции для работы с платформами
struct Platform initPlatform(float x, float y, int width, int height) {
    struct Platform platform;
    platform.x = x;
    platform.y = y;
    platform.width = width;
    platform.height = height;
    return platform;
}

void printPlatform(struct Platform platform) { // Передаем по значению
    printf("Информация об платформе:\n");
    printf("Расположение по x: %f\n", platform.x);
    printf("Расположение по y: %f\n", platform.y);
    printf("Высота: %d\n", platform.width);
    printf("ширина: %d\n", platform.height);
    printf("\n");
}


// Описание врагов 
struct Enemy {
    float x;
    float y;
    int width;
    int weight;
    int state;
};


// Валюта 
struct Coin {
    float x;
    float y;
    int collected;
};


// Количество бонусов за пройденный уровень
struct Star {
    float x;
    float y;
    int collected;
};


// Координаты ключа где находится ключ
struct Key {
    float x;
    float y;
};



// Описание двери для ключа
struct Door {
    float x;
    float y;
    int width;
    int height;
    int locked;
};

// Карта 
struct Map {
    int x, y;
    float width;
    float height; 
    float scrollSpeed;
};

 


// Функция main
int main() {
    setlocale(LC_ALL, "Rus");

    // Статическая переменная Platform
    struct Platform staticPlatform = initPlatform(100.0f, 200.0f, 300, 20);
    printPlatform(staticPlatform);

    // Динамическая переменная Mario
    struct Mario dynamicMario = initMario(10.0f, 10.0f, 50, 70, 3);
    printMario(dynamicMario);

    return 0;
}
 