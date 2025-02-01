#include <string>
#include "game.h"

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