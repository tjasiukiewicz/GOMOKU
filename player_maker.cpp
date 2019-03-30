#include "player_maker.hpp"
#include "stone_color.hpp"
#include "player.hpp"

PlayerMaker::PairPlayersType PlayerMaker::makePlayers() {
    // TODO: make players
    return {std::make_unique<Player>("George", StoneColor::White),
        std::make_unique<Player>("Agnes", StoneColor::Black)};
}
