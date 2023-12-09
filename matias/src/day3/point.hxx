#pragma once

struct Point {
    unsigned x;
    unsigned y;
    auto operator<=> (const Point&) const = default;
};
