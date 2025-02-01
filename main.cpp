#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Класс, представляющий фишку
class Tile {
public:
    int number;
    std::string color;

    Tile(int num, std::string col) : number(num), color(col) {}

    void display() const {
        std::cout << color << " " << number;
    }
};

// Класс, представляющий игрока
class Player {
public:
    std::string name;
    std::vector<Tile> hand;

    Player(std::string n) : name(n) {}

    void addTile(Tile tile) {
        hand.push_back(tile);
    }

    void displayHand() const {
        std::cout << name << "'s hand:\n";
        for (const auto& tile : hand) {
            tile.display();
            std::cout << std::endl;
        }
    }
};

// Класс, представляющий игру
class RummikubGame {
private:
    std::vector<Tile> tiles;
    std::vector<Player> players;

    void initializeTiles() {
        std::string colors[] = {"Red", "Blue", "Yellow", "Black"};
        for (int i = 1; i <= 13; ++i) {
            for (const auto& color : colors) {
                tiles.push_back(Tile(i, color));
                tiles.push_back(Tile(i, color)); // Две фишки каждого числа и цвета
            }
        }
    }

    void shuffleTiles() {
        std::srand(std::time(0));
        std::random_shuffle(tiles.begin(), tiles.end());
    }

public:
    RummikubGame() {
        initializeTiles();
        shuffleTiles();
    }

    void addPlayer(const Player& player) {
        players.push_back(player);
    }

    void dealTiles(int numberOfTiles) {
        for (auto& player : players) {
            for (int i = 0; i < numberOfTiles; ++i) {
                player.addTile(tiles.back());
                tiles.pop_back();
            }
        }
    }

    void startGame() {
        std::cout << "Starting Rummikub Game!\n";
        dealTiles(14); // Раздаем по 14 фишек каждому игроку

        for (const auto& player : players) {
            player.displayHand();
        }
    }
};

// Основная программа
int main() {
    RummikubGame game;

    // Добавляем игроков
    game.addPlayer(Player("Alice"));
    game.addPlayer(Player("Bob"));

    // Начинаем игру
    game.startGame();

    return 0;
}