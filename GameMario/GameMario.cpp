#include <iostream>
#include <locale.h>
#include <string>

 
using namespace std;


// Класс, описывающий игрока
class Player {
private:

    int lives;     // Количество жизней игрока
    int height;   // Рост игрока
    int weight;  // Ширина игрока


public:

    Player() {                                  // Пустой конструктор
        lives = height = weight = 0;

    }

    Player(int lives, int height, int weight) {       // Конструктор с параметрами

        this->lives = lives;
        this->height = height;
        this->weight = weight;
    }


    // Метод для вывода информации об игроке
    void printPlayer() {
        cout << "Количество жизней: " << lives << " Рост: " << height << " Ширина: " << weight << endl;
    }

};


// Класс, описывающий врага
class Enemy {
private:
    int lives;
    int height;
    int weight;

public:
    Enemy() {
        lives = height = weight = 0;
    }

    Enemy(int lives, int height, int weight) {
        this->height = height;
        this->weight = weight;
        this->lives = lives;
    }

    void printEnemy() {
        cout << "Количество жизней: " << lives << " Рост: " << height << " Ширина: " << weight << endl;
    }


};

// Класс, описывающий уровень игры
class Level {
private:
    int number;
    int enemy;
    int coins;
public:

};

// Класс, описывающий карту игры
class Map {
private:

public:

};

// Класс, описывающий платформы
class Platforms {
private:
    bool stat;
    int left;
    int right;
public:

};

// Класс, описывающий меню игры
class Menu {
private:
    string start;
    string exit;
    string records;
    string level;
public:

};

// Класс, описывающий монеты
class Coins {
private:
    int kolichestvo;
    string color;
public:

};

// Класс, описывающий блоки
class Blocks {
private:
    string color;
    bool destructible;
    bool undestructible;
public:

};




// Класс, описывающий рекорды игры
class Records {
private:
    int records;
    int score_level;
public:

};

// Класс, описывающий музыку в игре
class Music {
private:
    int died;
    string radio;
public:

};
 


// Функция main
int main() {
    setlocale(LC_ALL, "Rus");
    // Динамический массив объектов класса Player
    int size = 3;
    Player* masPlayer = new Player[size];
    for (int i = 0; i < size; i++) {
        masPlayer[i] = Player(3 - i, 20, 30);  // Создаем объект Player и присваиваем его
        masPlayer[i].printPlayer();  // Выводим информацию о Player
    }
    delete[] masPlayer; // Удаляем массив Player


    cout << endl;


    // Массив динамических объектов класса Enemy
    Enemy** masEnemy = new Enemy * [size];

    // Инициализируем каждый элемент массива
    for (int i = 0; i < size; i++) {
        masEnemy[i] = new Enemy(2 - i, 20, 30);   // Создаем объект Enemy и присваиваем его элементу массива
        masEnemy[i]->printEnemy();   // Выводим информацию о Enemy
    }


    // Удаляем объекты Enemy
    for (int i = 0; i < size; i++) {
        delete masEnemy[i];
    }

    delete[] masEnemy; // Удаляем массив Enemy
    

    return 0;
}
 