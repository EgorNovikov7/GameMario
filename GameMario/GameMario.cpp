#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Для std::sort и std::find_if
#include <memory>    // Для std::unique_ptr
using namespace std;

// Базовый класс, описывающий игрока.
class Player {
protected:
    int lives;
    int height;
    int weight;

public:
    Player(int lives, int height, int weight)
        : lives(lives), height(height), weight(weight) {}

    virtual void displayInfo() {
        cout << "Player: " << lives << " lives, " << height << " cm height, "
            << weight << " kg weight." << endl;
    }

    virtual ~Player() {}

    int getLives() const { return lives; } // Метод для получения жизней
};

// Производный класс, описывающий супер игрока.
class SuperPlayer : public Player {
private:
    int powerLevel;

public:
    SuperPlayer(int lives, int height, int weight, int powerLevel)
        : Player(lives, height, weight), powerLevel(powerLevel) {}

    void displayInfo() override {
        Player::displayInfo(); // вызов метода базового класса
        cout << "SuperPlayer: Power Level = " << powerLevel << endl;
    }
};

// Производный класс, описывающий врага.
class Enemy {
protected:
    int lives;
    int height;
    int weight;

public:
    Enemy(int lives, int height, int weight)
        : lives(lives), height(height), weight(weight) {}

    virtual void displayInfo() {
        cout << "Enemy: " << lives << " lives, " << height << " cm height, "
            << weight << " kg weight." << endl;
    }

    virtual ~Enemy() {}

    int getLives() const { return lives; } // Метод для получения жизней
};

// Производный класс, описывающий сильного врага.
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

// Функция для сортировки игроков по количеству жизней
bool comparePlayers(const unique_ptr<Player>& a, const unique_ptr<Player>& b) {
    return a->getLives() > b->getLives(); // Сортировка по убыванию жизней
}

// Функция для поиска игрока по количеству жизней
Player* findPlayerByLives(const vector<unique_ptr<Player>>& players, int lives) {
    auto it = find_if(players.begin(), players.end(), [lives](const unique_ptr<Player>& player) {
        return player->getLives() == lives;
        });

    return (it != players.end()) ? it->get() : nullptr; // Возвращаем указатель на найденного игрока или nullptr
}

void demonstrateVirtualFunction() {
    unique_ptr<Player> player = make_unique<SuperPlayer>(3, 180, 75, 5);
    unique_ptr<Enemy> enemy = make_unique<BossEnemy>(2, 170, 70, 15);

    player->displayInfo();
    enemy->displayInfo();
}

int main() {
    setlocale(LC_ALL, "Rus");

    // Создаем вектор для хранения игроков
    vector<unique_ptr<Player>> players;

    // Добавляем игроков в вектор
    players.push_back(make_unique<SuperPlayer>(3, 180, 75, 5));
    players.push_back(make_unique<SuperPlayer>(5, 175, 70, 10));

    // Сортируем игроков по количеству жизней
    sort(players.begin(), players.end(), comparePlayers);

    cout << "Игроки после сортировки:" << endl;
    for (const auto& player : players) {
        player->displayInfo();
    }

    // Поиск игрока с определенным количеством жизней
    int searchLives = 5;
    Player* foundPlayer = findPlayerByLives(players, searchLives);

    if (foundPlayer) {
        cout << "Игрок с " << searchLives << " жизнями найден:" << endl;
        foundPlayer->displayInfo();
    }
    else {
        cout << "Игрок с " << searchLives << " жизнями не найден." << endl;
    }

    return 0;
}