#include <iostream>
#include "game.hpp"
#include "game_rule.hpp"
#include "display_board.hpp"
#include "display_game.hpp"


int main() {
    GameRule gameRule;
    DisplayGame displayGame{std::cin, std::cout, std::cerr};
    DisplayBoard displayBoard{std::cout};
    Game game{gameRule, displayGame, displayBoard};
    game.run();
}
