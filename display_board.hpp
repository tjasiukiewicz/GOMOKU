#pragma once

#include <iostream>
#include "board_container.hpp"


class DisplayBoard {
public:
    explicit DisplayBoard(std::ostream& os);
    void show(const BoardCellsContainerType& cells) const;
private:
    std::ostream& os;
};

