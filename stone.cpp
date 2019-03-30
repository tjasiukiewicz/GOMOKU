#include "stone.hpp"

Stone::Stone(StoneColor color)
    : color{color} {
}

bool Stone::operator ==(const Stone& src) const {
    return color == src.color;
}

char Stone::getRepresentation() const {
    return color == StoneColor::White ? 'O': '@';
}
