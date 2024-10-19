#include <iostream>
#include <locale.h>
#include <string>

 
using namespace std;



 

// Класс, описывающий игрока
class Player {
private:
    int lives;
    int height;
    int weight;

public:
    Player() : lives(0), height(0), weight(0) {}

    Player(int lives, int height, int weight) {
        this->lives = lives;
        this->height = height;
        this->weight = weight;
    }

    void printPlayer() {
        cout << "Количество жизней: " << lives
            << " Рост: " << height
            << " Вес: " << weight << endl;
    }

    // Метод для изменения жизней
    void loseLife() {
        if (lives > 0) {
            lives--;
        }
    }

    // Метод для получения количества жизней
    int getLives() const {
        return lives;
    }
};

class Game {
private:
    Player player; // Ассоциация с классом Player

public:
    Game(const Player& player) : player(player) {}

    void startGame() {
        cout << "Игра началась!" << endl;
        player.printPlayer();
    }

    void playerLosesLife() {
        player.loseLife();
        cout << "Игрок потерял жизнь!" << endl;
        cout << "Осталось жизней: " << player.getLives() << endl;
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


    //
    // Создаем игрока с 3 жизнями, ростом 180 и весом 75
    Player player(3, 180, 75);

    // Создаем игру с этим игроком
    Game game(player);

    // Запускаем игру
    game.startGame();

    // Игрок теряет жизнь
    game.playerLosesLife();
    game.playerLosesLife();
    cout << endl;




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
 