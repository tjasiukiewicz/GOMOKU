#pragma once

#include <string>
#include "stone_color.hpp"

class Player {
public:
    Player(const std::string& name, StoneColor color);
    // noncopyable
    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    const std::string& getName() const;
    StoneColor getColor() const;
private:
    const std::string name;
    const StoneColor color;
};
