#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "game.h"

// Класс, представляющий игру


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