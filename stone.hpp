#pragma once

#include "stone_color.hpp"

class Stone {
public:
    explicit Stone(StoneColor color);
    StoneColor getColor() const;
private:
    StoneColor color;
};
