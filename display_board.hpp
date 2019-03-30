#pragma once

#include "board.hpp"

class DisplayBoard {
public:
    DisplayBoard();
    void show(const Board::CellsContainerType& cells) const;
private:

};
