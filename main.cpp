#include <iostream>
#include "game.hpp"
#include "game_rule.hpp"
#include "display_board.hpp"


int main() {
    GameRule gameRule;
    DisplayBoard display{std::cout};
    Game game{gameRule, display};
    game.run();
}
