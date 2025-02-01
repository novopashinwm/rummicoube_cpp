#pragma once
#include <string>
#include <vector>
#include "title.h"

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
            std::cout << ' ';
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
};