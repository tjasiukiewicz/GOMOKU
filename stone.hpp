#pragma once

#include "stone_color.hpp"

class Stone {
public:
    explicit Stone(StoneColor color);

    // noncopyable
    Stone(const Stone&) = delete;
    Stone& operator = (const Stone&) = delete;

    StoneColor getColor() const;
    char getRepresentation() const;
private:
    const StoneColor color;
};
