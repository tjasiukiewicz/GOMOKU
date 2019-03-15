#pragma once

#include <array>
#include <optional>
#include "stone.hpp"
#include "position.hpp"

constexpr static std::size_t BOARD_WIDTH = 15;

class Board {
public:
    Board();
    void dropStone(const Stone& stone, const Position& position);
    void show() const;
private:
    std::array<std::array<std::optional<Stone>, BOARD_WIDTH>, BOARD_WIDTH> cells;
};


