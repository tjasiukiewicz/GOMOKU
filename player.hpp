#pragma once

#include <string>
#include "stone_color.hpp"

class Stone;

class Player {
public:
    Player(const std::string& name, StoneColor color);
    // noncopyable
    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    const std::string& getName() const;
    StoneColor getColor() const;
    Stone getStone() const;
private:
    const std::string name;
    const StoneColor color;
};
