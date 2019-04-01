#pragma once

#include <cstddef>
#include <utility>

class Position {
public:
    Position(char column, std::size_t row);
    std::pair<std::size_t, std::size_t> getIndexes() const;
    static bool inBoard(char column, std::size_t row);
private:
    const std::size_t column;
    const std::size_t row;
};
