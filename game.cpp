#include "game.hpp"
#include "board.hpp"
#include "display_game.hpp"
#include "game_rule.hpp"
#include "player.hpp"
#include "player_maker.hpp"
#include "position.hpp"
#include "stone.hpp"
#include <utility>

Game::Game(GameRule& gameRule, DisplayGame& displayGame, DisplayBoard& displayBoard)
    : currentPlayer{},
      nextPlayer{},
      board{std::make_unique<Board>()},
      gameRule{gameRule},
      displayGame{displayGame},
      displayBoard{displayBoard} {
        auto prPlayers = PlayerMaker::makePlayers();
        currentPlayer = std::move(prPlayers.first);
        nextPlayer = std::move(prPlayers.second);
}

Game::~Game() = default;

void Game::run() {
    board->renderOn(displayBoard);
    for(;;) {
        displayGame.showPlayer(*currentPlayer);
        auto stone = currentPlayer->getStone();
        auto position = displayGame.getPosition();
        if(! board->dropStone(std::move(stone), position)) {
            displayGame.showCellNotEmpty();
            continue;
        }
        board->acceptGameRule(gameRule);
        if(gameRule.winOnPosition(position)) {
            break;
        }
        board->renderOn(displayBoard);
        currentPlayer.swap(nextPlayer);
    }
    board->renderOn(displayBoard);
    displayGame.showWinner(*currentPlayer);
}
