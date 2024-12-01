#include <iostream>
#include <string>

using namespace std;

// 1) Базовый класс, описывающий игрока.
class Player {
protected: // Применяем модификатор protected
    int lives;
    int height;
    int weight;

public:
    Player(int lives, int height, int weight)
        : lives(lives), height(height), weight(weight) {}

    virtual void displayInfo() {
        cout << "Player: " << lives << " lives, " << height << " cm height, " << weight << " kg weight." << endl;
    }

    // 4) Виртуальный деструктор
    virtual ~Player() {}
};

// 1) Производный класс, описывающий супер игрока.
class SuperPlayer : public Player {
private:
    int powerLevel;

public:
    SuperPlayer(int lives, int height, int weight, int powerLevel)
        : Player(lives, height, weight), powerLevel(powerLevel) {}

    // 3) Перегрузка метода displayInfo
    void displayInfo() override {
        Player::displayInfo(); // вызов метода базового класса
        cout << "SuperPlayer: Power Level = " << powerLevel << endl;
    }
};

// 1) Производный класс, описывающий врага.
class Enemy {
private:
    int lives;
    int height;
    int weight;

public:
    Enemy(int lives, int height, int weight)
        : lives(lives), height(height), weight(weight) {}

    virtual void displayInfo() {
        cout << "Enemy: " << lives << " lives, " << height << " cm height, " << weight << " kg weight." << endl;
    }
};

// 1) Производный класс, описывающий сильного врага.
class BossEnemy : public Enemy {
private:
    int damage;

public:
    BossEnemy(int lives, int height, int weight, int damage)
        : Enemy(lives, height, weight), damage(damage) {}

    void displayInfo() override {
        Enemy::displayInfo(); // вызов метода базового класса
        cout << "BossEnemy: Damage = " << damage << endl;
    }
};

// 2) Класс, описывающий платформы
class Platforms {
private:
    bool stat;
    int left;
    int right;

public:
    Platforms(bool stat, int left, int right)
        : stat(stat), left(left), right(right) {}

    bool getStatus() const {
        return stat;
    }
};

// 5) Перегрузка оператора присваивания для производного класса
class Game {
private:
    Platforms platform;

public:
    Game(bool stat, int left, int right)
        : platform(stat, left, right) {}

    Game& operator=(const Game& other) {
        if (this != &other) {
            this->platform = other.platform; // Здесь мы просто переписываем платформу
        }
        return *this;
    }
};

// 6) Демонстрация виртуальной функции
void demonstrateVirtualFunction() {
    Player* player = new SuperPlayer(3, 180, 75, 5);
    Enemy* enemy = new BossEnemy(2, 170, 70, 15);

    // Полиморфный вызов
    player->displayInfo();
    enemy->displayInfo();

    delete player;
    delete enemy;
}

// 7) Абстрактный класс
class GameObject {
public:
    virtual void update() = 0; // Абстрактный метод

    virtual ~GameObject() {}
};

class Coin : public GameObject {
private:
    int quantity;

public:
    Coin(int quantity) : quantity(quantity) {}

    void update() override {
        cout << "Updating Coin: quantity = " << quantity << endl;
    }
};




// Функция main
int main() {
    setlocale(LC_ALL, "Rus");


    // Демонстрация перегрузки и полиморфизма
    demonstrateVirtualFunction();

    // Использование абстрактного класса
    GameObject* coin = new Coin(10);
    coin->update();
    delete coin;

    return 0;

    return 0;
}
 