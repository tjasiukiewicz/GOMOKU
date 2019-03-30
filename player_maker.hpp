#pragma once

#include <utility>
#include <memory>

class Player;

class PlayerMaker {
public:
    using PairPlayersType = std::pair<std::unique_ptr<Player>, std::unique_ptr<Player>>;
    PlayerMaker() = delete;
    static PairPlayersType makePlayers();
};
