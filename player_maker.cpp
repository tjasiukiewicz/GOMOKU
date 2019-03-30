#include "player_maker.hpp"
#include "stone_color.hpp"
#include "player.hpp"
#include <cctype>
#include <iostream>
#include <string>

namespace {

constexpr static char WhiteChar = 'w';
constexpr static char BlackChar = 'b';
constexpr static const char * WhiteName = "white";
constexpr static const char * BlackName = "black";

std::string askName(const std::string& playerMsg) {
    std::string name;
    std::cout << playerMsg << " Enter yout name: ";
    std::cin >> name;
    return name;
}

StoneColor askStoneColor() {
    char cColor;
    for(;;) {
        std::cout << "Choose stone color ["
            << WhiteChar << " - " << WhiteName
            << ", " << BlackChar << " - " << BlackName << "]: ";
        std::cin >> cColor;
        cColor = std::tolower(cColor);
        if(std::cin && ((cColor == WhiteChar) || (cColor == BlackChar))) {
            break;
        }
        std::cerr << "Invalid color! Try again.\n";
    }
    return cColor == WhiteChar ? StoneColor::White: StoneColor::Black;
}

} // anonymous namespace

PlayerMaker::PairPlayersType PlayerMaker::makePlayers() {
    auto player1Name = askName("Player1:");
    auto player1Color = askStoneColor();
    auto player2Name = askName("Player2:");
    auto player2Color = (player1Color == StoneColor::White ? StoneColor::Black: StoneColor::White);
    std::cout << player2Name << ", your stone is...: "
      << (player2Color == StoneColor::Black ? BlackName: WhiteName) << '\n';
    return {std::make_unique<Player>(player1Name, player2Color),
        std::make_unique<Player>(player2Name, player2Color)};
}
