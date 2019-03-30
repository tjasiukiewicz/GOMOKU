#pragma once

#include "board.hpp"

class Position;

class GameRule {
public:
    bool winOnPosition(const Position& position) const;
};
