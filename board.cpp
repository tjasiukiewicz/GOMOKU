#include "board.hpp"
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>

namespace {

void showColumnNames() {
    std::cout << "   ";
    char c = 'a';
    std::generate_n(std::ostream_iterator<char>(std::cout, " "),
        BOARD_WIDTH, [&c] { return c++; });
    std::cout << '\n';
}

void showRow(std::size_t rowNum) {
    std::cout << std::setw(2) << std::right << (rowNum + 1) << ' ';
    for(auto i = 0UL; i < (BOARD_WIDTH - 1); ++i) {
        std::cout << "+-";
    }
    std::cout << "+ ";
    std::cout << std::setw(2) << std::left << (rowNum + 1) << '\n';
}

void showSeparator() {
    std::cout << "   ";
    std::fill_n(std::ostream_iterator<char>(std::cout, " "),
        BOARD_WIDTH - 1, '|');
    std::cout << "|\n";
}


} // anonymous namespace

Board::Board()
    : cells{} {
}

void Board::dropStone(const Stone& stone, const Position& position) {
    (void) stone;
    (void) position;
}

void Board::show() const {
    showColumnNames();
    auto rowNum = BOARD_WIDTH;
    while(--rowNum) {
        showRow(rowNum);
        showSeparator();
    }
    showRow(0);
    showColumnNames();
}

