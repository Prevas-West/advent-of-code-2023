#pragma once

#include <string>

#include "grid_object.hxx"

class GridNumber : public GridObject {
public:
    std::string number;

    GridNumber(const Point &position, const std::string &num)
        : GridObject(position)
        , number(num)
    {}
};
