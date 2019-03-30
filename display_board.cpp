#include "display_board.hpp"
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

void showRow(const Board::CellsContainerType& cells, std::size_t rowNum) {
    std::cout << std::setw(2) << std::right << (rowNum + 1) << ' ';
    auto getCellRepr = [](const auto& cell) {
        return cell ? cell->getRepresentation(): '+';
    };
    std::transform(cells[rowNum].cbegin(), std::prev(cells[rowNum].cend()),
        std::ostream_iterator<char>(std::cout, "-"), getCellRepr);

    std::cout << getCellRepr(*(cells[rowNum].crbegin())) << ' ';
    std::cout << std::setw(2) << std::left << (rowNum + 1) << '\n';
}

void showSeparator() {
    std::cout << "   ";
    std::fill_n(std::ostream_iterator<char>(std::cout, " "),
        BOARD_WIDTH - 1, '|');
    std::cout << "|\n";
}


} // anonymous namespace

DisplayBoard::DisplayBoard() {
}

void DisplayBoard::show(const Board::CellsContainerType& cells) const {
    showColumnNames();
    auto rowNum = BOARD_WIDTH;
    while(--rowNum) {
        showRow(cells, rowNum);
        showSeparator();
    }
    showRow(cells, 0);
    showColumnNames();
}
