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
        if(std::cin && Position::isRowCorrect(row) && Position::isColumnCorrect(column)) {
            break;
        }
        std::cerr << "Invalid move! Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return Position{column, row};
}

} // anonymous namespace

Game::Game()
    : currentPlayer{std::make_unique<Player>("George", StoneColor::White)},
      nextPlayer{std::make_unique<Player>("Agnes", StoneColor::Black)},
      board{std::make_unique<Board>()},
      displayBoard{DisplayBoard()} {}

void Game::run() {
    //board->show();
    board->renderOn(displayBoard);
    for(;;) {
        std::cout << "Player: " << currentPlayer->getName() << " ";
        if(auto position = getPosition(); ! board->dropStone(Stone{currentPlayer->getColor()}, position)) {
            std::cerr << "Incorrect move! Cell not empty. Try again.\n";
            continue;
        }
        board->renderOn(displayBoard);
        //board->show();
        currentPlayer.swap(nextPlayer);
    }
}
