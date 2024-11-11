#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
 
using namespace std;



 

// Класс, описывающий игрока
class Player {
private:
    int lives;
    int height;
    int weight;

public:
    Player() : lives(0), height(0), weight(0) {}
    Player(int lives, int height, int weight) : lives(lives), height(height), weight(weight) {}

    // Конструктор копии
    Player(const Player& other) : lives(other.lives), height(other.height), weight(other.weight) {}

    // Оператор присваивания
    Player& operator=(const Player& other) {
        if (this != &other) {
            lives = other.lives;
            height = other.height;
            weight = other.weight;
        }
        return *this;
    }

    void printPlayer() const {
        cout << "Количество жизней: " << lives << ", Рост: " << height << ", Вес: " << weight << endl;
    }

    void loseLife() {
        if (lives > 0) {
            lives--;
        }
    }

    int getLives() const {
        return lives;
    }

    // Возврат значения через указатель
    void getLivesViaPointer(int* p) const {
        if (p) {
            *p = lives;
        }
    }

    // Возврат значения через ссылку
    int& referenceLives() {
        return lives;
    }
};

// Дружественная функция
void displayPlayer(Player& player) {
    player.printPlayer();
}


// Простая перегрузка оператора
class Simple {
public:
    int value;
    Simple(int v) : value(v) {}

    Simple operator+(const Simple& other) {
        return Simple(this->value + other.value);
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

 
// Класс, описывающий платформы
class Platforms {
private:
    bool stat;
    int left;
    int right;

public:
    Platforms(bool status, int l, int r) : stat(status), left(l), right(r) {}

    void displayPlatform() {
        cout << "Platform Status: " << (stat ? "Active" : "Inactive")
            << ", Left Bound: " << left << ", Right Bound: " << right << endl;
    }
};

// Класс, описывающий меню игры
class Menu {
private:
    string start;
    string exit;
    string records;

public:
    Menu(string s, string e, string r) : start(s), exit(e), records(r) {}

    void showMenu() {
        cout << "Menu:\n"
            << "1. " << start << "\n"
            << "2. " << records << "\n"
            << "3. " << exit << endl;
    }
};

// Класс, описывающий монеты
class Coins {
private:
    int quantity;
    string color;

public:
    Coins(int qty, string c) : quantity(qty), color(c) {}

    void displayCoins() {
        cout << "Coins: " << quantity << ", Color: " << color << endl;
    }
};

// Класс, описывающий блоки
class Blocks {
private:
    string color;
    bool destructible;

public:
    Blocks(string c, bool d) : color(c), destructible(d) {}

    void displayBlock() {
        cout << "Block Color: " << color << ", Destructible: " << (destructible ? "Yes" : "No") << endl;
    }
};

// Класс, описывающий рекорды игры
class Records {
private:
    int record;
    int scoreLevel;

public:
    Records(int r, int s) : record(r), scoreLevel(s) {}

    void displayRecords() {
        cout << "Record: " << record << ", Score Level: " << scoreLevel << endl;
    }
};

// Класс, описывающий музыку в игре
class Music {
private:
    int died;
    string radio;

public:
    Music(int d, string r) : died(d), radio(r) {}

    void playMusic() {
        cout << "Music Playing: " << radio << " | Died: " << died << " times." << endl;
    }
};

// Основной класс Game
class Game {
private:
    Platforms platform;
    Menu menu;
    Coins coin;
    Blocks block;
    Records record;
    Music music;

public:
    Game(Platforms p, Menu m, Coins c, Blocks b, Records r, Music mu)
        : platform(p), menu(m), coin(c), block(b), record(r), music(mu) {}

    void startGame() {
        cout << "Starting the Game:\n";
        menu.showMenu();
        platform.displayPlatform();
        coin.displayCoins();
        block.displayBlock();
        record.displayRecords();
        music.playMusic();
    }
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
    


    cout << endl;

    Platforms platform(true, 0, 100);
    Menu menu("Start Game", "Exit", "Records");
    Coins coins(10, "Gold");
    Blocks block("Red", true);
    Records record(1000, 5);
    Music music(3, "Game Theme");

    Game game(platform, menu, coins, block, record, music);
    game.startGame();


    cout << endl;
    

    return 0;
}
 