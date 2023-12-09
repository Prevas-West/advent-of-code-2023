#pragma once

#include "grid_number.hxx"
#include "grid_symbol.hxx"

#include <memory>
#include <utility>
#include <map>

class Grid {
public:
    using numbers_t = std::map<Point, std::unique_ptr<GridNumber>>;
    using symbols_t = std::map<Point, std::unique_ptr<GridSymbol>>;

    void add(std::unique_ptr<GridNumber> n) {
        _numbers[n->position] = std::move(n);
    }

    void add(std::unique_ptr<GridSymbol> s) {
        _symbols[s->position] = std::move(s);
    }

    const numbers_t& numbers() const {
        return _numbers;
    }

    bool hasSymbolAt(const Point &p) {
        return _symbols.contains(p);
    }
private:
    numbers_t _numbers;
    symbols_t _symbols;
};
