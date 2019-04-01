#include "position.hpp"
#include "board_container.hpp"
#include <cassert>

namespace {

constexpr static char MinColumn = 'a';
constexpr static char MaxColumn = 'a' + BOARD_WIDTH;
constexpr static std::size_t MinRow = 1;
constexpr static std::size_t MaxRow = BOARD_WIDTH;

} // anonymous namespace

Position::Position(char column, std::size_t row)
    : column{column + 1UL - 'a'}, row{row} {
    assert((column >= MinColumn) && (column <= MaxColumn));
    assert((row >= MinRow) && (row <= MaxRow));
}

std::pair<std::size_t, std::size_t> Position::getIndexes() const {
    return {column - 1, row - 1};
}

bool Position::inBoard(char column, std::size_t row) {
    return ((column >= MinColumn) && (column <= MaxColumn))
      && ((row >= MinRow) && (row <= MaxRow));
}
