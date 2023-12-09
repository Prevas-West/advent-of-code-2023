#pragma once

#include "point.hxx"

class GridObject {
public:
    GridObject(const Point &pos)
        : position(pos)
    {}
    Point position;
};
