#include "game.hpp"
#include "player_maker.hpp"
#include "game_rule.hpp"

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

void Game::run() {
    board->renderOn(displayBoard);
    for(;;) {
        displayGame.showPlayer(*currentPlayer);
        auto stone = currentPlayer->getStone();
        auto position = displayGame.getPosition();
        if(! board->dropStone(std::move(stone), position)) {
            displayGame.cellNotEmpty();
            continue;
        }
        if(gameRule.winOnPosition(position)) {
            break;
        }
        board->renderOn(displayBoard);
        currentPlayer.swap(nextPlayer);
    }
    displayGame.showWinner(*currentPlayer);
}
