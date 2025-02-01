#pragma once
#include "title.h"
#include "player.h"

class RummikubGame {
public:

    const int JOKER = 0;

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

private:
    std::vector<Tile> tiles;
    std::vector<Player> players;

    void initializeTiles() {
        COLOR colors[] = {Red, Blue, Yellow, Black};
        for (int i = 1; i <= 13; ++i) {
            for (const auto& color : colors) {
                tiles.push_back(Tile(i, color));
                tiles.push_back(Tile(i, color)); // Две фишки каждого числа и цвета
            }
        }
        tiles.push_back(Tile(JOKER, Red));
        tiles.push_back(Tile(JOKER, Black));
    }

    void shuffleTiles() {
        std::srand(std::time(0));
        std::random_shuffle(tiles.begin(), tiles.end());
    }
};
