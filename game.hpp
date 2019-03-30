#pragma once

#include <memory>
#include "player.hpp"
#include "board.hpp"
#include "game_rule.hpp"
#include "display_board.hpp"
#include "display_game.hpp"

class Game {
public:
    Game(GameRule& gameRule, DisplayGame& displayGame, DisplayBoard& displayBoard);
    void run();
private:
    std::unique_ptr<Player> currentPlayer;
    std::unique_ptr<Player> nextPlayer;
    std::unique_ptr<Board> board;
    GameRule& gameRule;
    DisplayGame& displayGame;
    DisplayBoard& displayBoard;
};
