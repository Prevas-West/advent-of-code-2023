#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>

struct Bag {
    unsigned reds;
    unsigned greens;
    unsigned blues;

    unsigned cubeCount(std::string color) {
        if (color == "red") {
            return reds;
        } else if (color == "green") {
            return greens;
        } else if (color == "blue") {
            return blues;
        }
        return 0;
    }
};

static void part1(const std::string &input_filename) {
    Bag bag{ 12, 13, 14 };

    std::ifstream f(input_filename);
    std::string line;

    std::string game;
    unsigned gameNo;
    std::string cubeColor;
    unsigned cubeCount;
    char colon;
    char commaOrSemicolon;

    unsigned long sum = 0;

    while (std::getline(f, line)) {
        line += "|"; // commaOrSemicolon
        std::stringstream ss(line);
        ss >> game >> gameNo >> colon;
        std::cerr << game << " " << gameNo << colon << std::flush;
        bool applies = true;
        do {
            ss >> cubeCount >> cubeColor;
            commaOrSemicolon = cubeColor.back();
            cubeColor.pop_back();
            std::cerr << " " << cubeCount << " " << cubeColor << commaOrSemicolon << std::flush;
            if (bag.cubeCount(std::move(cubeColor)) < cubeCount) {
                applies = false;
                break;
            }
        } while (ss && (commaOrSemicolon == ',' || commaOrSemicolon == ';'));
        if (applies) {
            sum += gameNo;
        }
        std::cerr << std::endl;
    }

    std::cout << sum << std::flush;
}

int main() {
    part1("input");
    std::cout << std::endl;
}
