#pragma once

#include "stone_color.hpp"

class Stone {
public:
    explicit Stone(StoneColor color);

    // noncopyable
    Stone(const Stone&) = delete;
    Stone& operator = (const Stone&) = delete;

    StoneColor getColor() const;
private:
    const StoneColor color;
};
