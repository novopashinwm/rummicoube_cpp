#pragma once
#include <iostream>
#include <map>
#include <string>

enum COLOR {
    Red,
    Blue,
    Yellow,
    Black,
    Reset
};

class Tile {
public:

    int number;
    COLOR color;

    Tile(int num, COLOR col) : number(num), color(col) {}

    void display() const {
        std::cout << colors_.at(color)<< " "  << GetNumber(number) << colors_.at(COLOR::Reset);
    }

private:

    std::string GetNumber(const int& num) const {
        std::string number = std::to_string(num);
        return num < 10 ? "0" + number : number;
    }

    std::map<COLOR, std::string> colors_ = {
        {Red, "\033[31m"},
        {Blue,"\033[34m"},
        {Yellow,"\033[33m"},
        {Black,"\033[37m"},
        {Reset, "\033[0m"}
    };

};
