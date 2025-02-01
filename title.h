#pragma once
#include <iostream>
#include <map>
#include <string>

enum COLOR {
    Red,
    Blue,
    Yellow,
    Black
};


class Tile {
public:

    int number;
    COLOR color;

    Tile(int num, COLOR col) : number(num), color(col) {}

    void display() const {
        std::cout << colors_.at(color) << " "  << number;
    }
private:
    std::map<COLOR, std::string> colors_ = {{Red, "Red"}, {Blue,"Blue"}, {Yellow,"Yellow"},{Black,"Black"}};
};
