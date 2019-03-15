#include "stone.hpp"

Stone::Stone(StoneColor color)
    : color{color} {
}

StoneColor Stone::getColor() const {
    return color;
}
