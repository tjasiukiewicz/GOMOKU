#pragma once

#include <memory>
#include "player.hpp"
#include "board.hpp"

class Game {
public:
    Game();
    void run();
private:
    std::unique_ptr<Player> currentPlayer;
    std::unique_ptr<Player> nextPlayer;
    std::unique_ptr<Board> board;
};
