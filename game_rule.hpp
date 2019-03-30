#pragma once

#include "board_container.hpp"

class Position;

class GameRule {
public:
    GameRule();

    // noncopyable
    GameRule(const GameRule&) = delete;
    GameRule& operator = (const GameRule&) = delete;

    void addCells(const BoardCellsContainerType& cells);
    bool winOnPosition(const Position& position) const;
private:
    const BoardCellsContainerType * cells;
};
