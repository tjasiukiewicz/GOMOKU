#pragma once

#include <cstddef>
#include <utility>

class Position {
public:
    Position(std::size_t column, std::size_t row);
    std::pair<std::size_t, std::size_t> getIndexes() const;
private:
    const std::size_t column;
    const std::size_t row;
};
