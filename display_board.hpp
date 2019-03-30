#pragma once

#include <iostream>
#include "board.hpp"

class DisplayBoard {
public:
    explicit DisplayBoard(std::ostream& os);
    void show(const Board::CellsContainerType& cells) const;
private:
    std::ostream& os;
};

