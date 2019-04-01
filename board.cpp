#include "board.hpp"
#include "display_board.hpp"
#include "game_rule.hpp"
#include "position.hpp"
#include "stone.hpp"
#include <array>
#include <optional>
#include <utility>

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

void Board::acceptGameRule(GameRule& gameRule) const {
    gameRule.addCells(cells);
}

