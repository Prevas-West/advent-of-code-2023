#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <stdexcept>

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

    void leastCubeCount(std::string color, unsigned count) {
        if (color == "red") {
            if (reds < count) {
                reds = count;
            }
        } else if (color == "green") {
            if (greens < count) {
                greens = count;
            }
        } else if (color == "blue") {
            if (blues < count) {
                blues = count;
            }
        } else {
            using namespace std::string_literals;
            throw std::invalid_argument("Unknown color '"s + color + "'");
        }
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

static void part2(const std::string &input_filename) {
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
        Bag bag{};

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
            bag.leastCubeCount(std::move(cubeColor), cubeCount);
        } while (ss && (commaOrSemicolon == ',' || commaOrSemicolon == ';'));
        sum += bag.reds * bag.greens * bag.blues;
        std::cerr << std::endl << "  red=" << bag.reds << " green=" << bag.greens << " blue=" << bag.blues << std::endl;
    }

    std::cout << sum << std::flush;
}

int main() {
    part1("input");
    std::cout << ", ";
    part2("input");
    std::cout << std::endl;
}
