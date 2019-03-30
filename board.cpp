#include "board.hpp"
#include "display_board.hpp"

Board::Board()
    : cells{} {
}

bool Board::dropStone(Stone&& stone, const Position& position) {
    auto [col, row] = position.getIndexes();
    return cells[row][col] ? false
      : (cells[row][col].emplace(std::move(stone)), true);
}

void Board::renderOn(const DisplayBoard& display) const {
    display.show(cells);
}

