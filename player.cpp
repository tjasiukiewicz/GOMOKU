#include "player.hpp"
#include "stone.hpp"

Player::Player(const std::string& name, StoneColor color)
    : name{name}, color{color} {}

const std::string& Player::getName() const {
    return name;
}

StoneColor Player::getColor() const {
    return color;
}

Stone Player::getStone() const {
    return Stone{color};
}

