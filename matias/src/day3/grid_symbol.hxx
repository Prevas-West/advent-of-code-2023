#pragma once

#include "grid_object.hxx"

class GridSymbol : public GridObject {
public:
    GridSymbol(const Point &position, char sym)
        : GridObject(position)
        , _symbol(sym)
    {}

    char symbol() const {
        return _symbol;
    }
private:
    char _symbol;
};
