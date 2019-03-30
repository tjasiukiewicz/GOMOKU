#include "game.hpp"
#include "player_maker.hpp"
#include "game_rule.hpp"
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
      gameRule{std::make_unique<GameRule>()},
      displayBoard{DisplayBoard(std::cout)} {
        auto prPlayers = PlayerMaker::makePlayers();
        currentPlayer = std::move(prPlayers.first);
        nextPlayer = std::move(prPlayers.second);
}

void Game::run() {
    board->renderOn(displayBoard);
    for(;;) {
        std::cout << "Player: " << currentPlayer->getName() << " ";
        auto stone = currentPlayer->getStone();
        auto position = getPosition();
        if(! board->dropStone(std::move(stone), position)) {
            std::cerr << "Incorrect move! Cell not empty. Try again.\n";
            continue;
        }
        if(gameRule->winOnPosition(position)) {
            break;
        }
        board->renderOn(displayBoard);
        currentPlayer.swap(nextPlayer);
    }
    std::cout << "Winner is " << currentPlayer->getName() << '\n';
}
