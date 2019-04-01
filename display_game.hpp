#pragma once

#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <optional>
#include "display_board.hpp"

class Player;
class Position;

class DisplayGame {
public:
    DisplayGame(std::istream& is, std::ostream& os, std::ostream& es);

    Position getPosition() const;
    void showPlayer(const Player& player) const;
    void showCellNotEmpty() const;
    void showWinner(const Player& player) const;
private:
    std::istream& is;
    std::ostream& os;
    std::ostream& es;
};
