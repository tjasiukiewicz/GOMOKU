#pragma once

#include "board_container.hpp"

class DisplayBoard;
class Position;
class GameRule;

class Board {
public:
    Board();

    // noncopyable
    Board(const Board&) = delete;
    Board& operator = (const Board&) = delete;

    [[nodiscard]] bool dropStone(Stone&& stone, const Position& position);
    void acceptGameRule(GameRule& gameRule) const;
    void renderOn(const DisplayBoard& display) const;
private:
    BoardCellsContainerType cells;
};


