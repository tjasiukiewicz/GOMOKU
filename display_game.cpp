#include "display_game.hpp"
#include "player.hpp"
#include "position.hpp"
#include <limits>
#include <string>

DisplayGame::DisplayGame(std::istream& is, std::ostream& os, std::ostream& es)
    : is{is}, os{os}, es{es} {}

Position DisplayGame::getPosition() const {
    char column;
    std::size_t row;
    for(;;) {
        os << "Your move: ";
        is >> column >> row;
        if(is && Position::isRowCorrect(row) && Position::isColumnCorrect(column)) {
            break;
        }
        es << "Invalid move! Try again.\n";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Position{column, row};
}

void DisplayGame::showPlayer(const Player& player) const {
    os << "Player: " << player.getName() << ": ";
}

void DisplayGame::cellNotEmpty() const {
    es << "Incorrect move! Cell not empty. Try again.\n";
}

void DisplayGame::showWinner(const Player& player) const {
    os << "Player: " << player.getName() << " Wins!!!\n";
}

