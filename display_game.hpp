#pragma once

#include <istream>
#include <ostream>

class Player;
class Position;

class DisplayGame {
public:
    DisplayGame(std::istream& is, std::ostream& os, std::ostream& es);

    Position getPosition() const;
    void showPlayer(const Player& player) const;
    void cellNotEmpty() const;
    void showWinner(const Player& player) const;
private:
    std::istream& is;
    std::ostream& os;
    std::ostream& es;
};
