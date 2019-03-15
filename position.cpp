#include "position.hpp"

Position::Position(std::size_t column, std::size_t row)
    : column{column}, row{row} {
}

std::pair<std::size_t, std::size_t> Position::getIndexes() const {
    return {column, row};
}
