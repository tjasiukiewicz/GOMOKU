#include "game.hpp"
#include "player_maker.hpp"
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
    : currentPlayer{},
      nextPlayer{},
      board{std::make_unique<Board>()},
      displayBoard{DisplayBoard(std::cout)} {
        auto prPlayers = PlayerMaker::makePlayers();
        currentPlayer = std::move(prPlayers.first);
        nextPlayer = std::move(prPlayers.second);
}

void Game::run() {
    //board->show();
    board->renderOn(displayBoard);
    for(;;) {
        std::cout << "Player: " << currentPlayer->getName() << " ";
        auto stone = currentPlayer->getStone();
        if(auto position = getPosition(); ! board->dropStone(std::move(stone), position)) {
            std::cerr << "Incorrect move! Cell not empty. Try again.\n";
            continue;
        }
        board->renderOn(displayBoard);
        //board->show();
        currentPlayer.swap(nextPlayer);
    }
}
