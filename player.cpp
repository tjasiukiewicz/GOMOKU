#include "player.hpp"

Player::Player(const std::string& name, StoneColor color)
    : name{name}, color{color} {}

const std::string& Player::getName() const {
    return name;
}

StoneColor Player::getColor() const {
    return color;
}

