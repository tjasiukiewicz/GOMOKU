#include "position.hpp"
#include "board.hpp"
#include <cassert>

Position::Position(std::size_t column, std::size_t row)
    : column{column}, row{row} {
    assert(column > 0 && column <= BOARD_WIDTH);
    assert(row > 0 && row <= BOARD_WIDTH);
}

std::pair<std::size_t, std::size_t> Position::getIndexes() const {
    return {column - 1, row - 1};
}
