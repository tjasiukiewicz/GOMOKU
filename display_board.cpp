#include "display_board.hpp"
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <optional>

namespace {

void showColumnNamesOn(std::ostream& os) {
    os << "   ";
    char c = 'a';
    std::generate_n(std::ostream_iterator<char>(os, " "),
        BOARD_WIDTH, [&c] { return c++; });
    os << '\n';
}

void showRowOn(std::ostream& os, const BoardCellsContainerType& cells, std::size_t rowNum) {
    os << std::setw(2) << std::right << (rowNum + 1) << ' ';
    auto getCellRepr = [](const auto& cell) {
        return cell ? cell->getRepresentation(): '+';
    };
    std::transform(cells[rowNum].cbegin(), std::prev(cells[rowNum].cend()),
        std::ostream_iterator<char>(os, "-"), getCellRepr);

    os << getCellRepr(*(cells[rowNum].crbegin())) << ' ';
    os << std::setw(2) << std::left << (rowNum + 1) << '\n';
}

void showSeparatorOn(std::ostream& os) {
    os << "   ";
    std::fill_n(std::ostream_iterator<char>(os, " "),
        BOARD_WIDTH - 1, '|');
    os << "|\n";
}


} // anonymous namespace

DisplayBoard::DisplayBoard(std::ostream& os)
    : os{os} {
}

void DisplayBoard::show(const BoardCellsContainerType& cells) const {
    showColumnNamesOn(os);
    auto rowNum = BOARD_WIDTH;
    while(--rowNum) {
        showRowOn(os, cells, rowNum);
        showSeparatorOn(os);
    }
    showRowOn(os, cells, 0);
    showColumnNamesOn(os);
}
