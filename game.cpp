#include "game.hpp"
#include <iostream>
#include <limits>

namespace {

Position getPosition() {
    char column;
    std::size_t row;
    for(;;) {
        std::cout << "Your move: ";
        std::cin >> column >> row;
        if(std::cin) {
            break;
        }
        std::cerr << "Invalid move! Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Position{column - 'a' + 1, row};
}

} // anonymous namespace

Game::Game()
    : currentPlayer{std::make_unique<Player>("George", StoneColor::White)},
      nextPlayer{std::make_unique<Player>("Agnes", StoneColor::Black)},
      board{std::make_unique<Board>()} {}

void Game::run() {
    board->show();
    for(;;) {
        std::cout << "Player: " << currentPlayer->getName() << " ";
        auto position = getPosition();
        board->dropStone(Stone{currentPlayer->getColor()}, position);
        board->show();
        currentPlayer.swap(nextPlayer);
    }
}
