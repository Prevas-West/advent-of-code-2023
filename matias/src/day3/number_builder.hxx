#pragma once

#include <string>
#include <memory>

#include "point.hxx"
#include "grid_number.hxx"

class NumberBuilder {
public:
    void addDigit(char digit) {
        _number += digit;
    }

    void reset() {
        _number.clear();
    }

    void position(const Point &p) {
        _position = p;
    }

    bool isBuilding() const {
        return _number != "";
    }

    const std::string& str() const {
        return _number;
    }

    std::unique_ptr<GridNumber> gridNumber() const {
        return std::make_unique<GridNumber>(_position, _number);
    }
private:
    std::string _number;
    Point _position;
};
