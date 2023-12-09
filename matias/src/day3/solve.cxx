#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <set>

#include "grid.hxx"
#include "grid_symbol.hxx"
#include "number_builder.hxx"

static void part1(const std::string &input_filename) {
    std::ifstream f(input_filename);
    std::string line;

    Grid grid{};
    Point current{};
    NumberBuilder numb{};

    unsigned long sum = 0;

    // Build the grid

    while (std::getline(f, line)) {
        for (current.x = 0; current.x < line.length(); ++current.x) {
            char c = line[current.x];
            if (c >= '0' && c <= '9') {
                if (!numb.isBuilding()) {
                    numb.position(current);
                }
                numb.addDigit(c);
            } else {
                if (numb.isBuilding()) {
                    auto gn = numb.gridNumber();
                    std::cerr << numb.str() << " at (" << gn->position.x << ", " << gn->position.y << ")" << std::endl;
                    grid.add(std::move(gn));
                    numb.reset();
                }
                if (c != '.') {
                    grid.add(std::make_unique<GridSymbol>(current, c));
                    std::cerr << c << " at (" << current.x << ", " << current.y << ")" << std::endl;
                }
            }
        }
        current.y += 1;
    }

    // Find the part numbers and sum them up

    for (const auto &n : grid.numbers()) {
        const Point &p = n.first;
        const std::string &number = n.second->number;
        bool done = false;

        for (unsigned i = 0; i < number.length() && !done; ++i) {
            const std::array<Point, 8> adjacentPoints{
                Point{ i + p.x - 1, p.y },     // west
                Point{ i + p.x + 1, p.y },     // east
                Point{ i + p.x, p.y - 1 },     // north
                Point{ i + p.x, p.y + 1 },     // south
                Point{ i + p.x - 1, p.y - 1 }, // north-west
                Point{ i + p.x + 1, p.y - 1 }, // north-east
                Point{ i + p.x - 1, p.y + 1 }, // south-west
                Point{ i + p.x + 1, p.y + 1 }, // south-east
            };

            std::cerr << "Adjacent points: " << std::endl;
            for (const auto &ap : adjacentPoints) {
                if (grid.hasSymbolAt(ap)) {
                    std::cerr << number << " at (" << p.x << ", " << p.y << "), ap = ("
                              << ap.x << ", " << ap.y << ")" << std::endl;
                    sum += std::stoul(number);
                    done = true;
                }
            }
        }
    }

    std::cout << sum << std::flush;
}


int main() {
    part1("input");
    std::cout << std::endl;
}
