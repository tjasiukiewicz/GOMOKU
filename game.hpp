#pragma once

#include <memory>

class Player;
class Board;
class GameRule;
class DisplayGame;
class DisplayBoard;

class Game {
public:
    Game(GameRule& gameRule, DisplayGame& displayGame, DisplayBoard& displayBoard);
    void run();
    ~Game();
private:
    std::unique_ptr<Player> currentPlayer;
    std::unique_ptr<Player> nextPlayer;
    std::unique_ptr<Board> board;
    GameRule& gameRule;
    DisplayGame& displayGame;
    DisplayBoard& displayBoard;
};
