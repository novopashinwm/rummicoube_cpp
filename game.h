#pragma once
#include <algorithm>
#include <ctime>
#include <functional>

#include "title.h"
#include "player.h"

struct FirstRun {
    int number;
    int playerIndex;
};

class RummikubGame {
public:

    const int JOKER = 0;
    const int TITLES_BY_PLAYER = 14;
    const int MAX_TITLES_NUMBER = 13;

    RummikubGame() {
        initializeTiles();
        shuffleTiles();
    }

    void addPlayer(const Player& player) {
        players.push_back(player);
    }

    //Функция выбирает, кто из игроков будет первым ходить, у кого выше номинал фишки, тот и будет
    //Если фишки одинаковые, то ходить будет первым тот, кто первый вытащил фишку
    int whoFirstRun() {

        std::vector<FirstRun> whoFirst;

        for (int i = 0; i < players.size(); i++) {
            whoFirst.push_back({tiles.back().number,i});
            shuffleTiles();
        }

        std::sort(whoFirst.begin(), whoFirst.end(),[](const FirstRun& a,  const FirstRun& b) {
           return  a.number > b.number;
        });

        return whoFirst[0].playerIndex;
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
        dealTiles(TITLES_BY_PLAYER); // Раздаем по 14 фишек каждому игроку

        for (const auto& player : players) {
            player.displayHand();
        }

        std::cout << std::endl;

        int firstRun = whoFirstRun();
        std::cout << players[firstRun].name << " run first" << std::endl;
    }

private:
    std::vector<Tile> tiles;
    std::vector<Player> players;

    void initializeTiles() {
        COLOR colors[] = {Red, Blue, Yellow, Black};
        for (int i = 1; i <= MAX_TITLES_NUMBER; ++i) {
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
