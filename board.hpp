#pragma once

#include <array>
#include <optional>
#include "stone.hpp"
#include "position.hpp"

constexpr static std::size_t BOARD_WIDTH = 15;

class Board {
public:
    using CellsContainerType = std::array<std::array<std::optional<Stone>, BOARD_WIDTH>, BOARD_WIDTH>;

    Board();
    // noncopyable
    Board(const Board&) = delete;
    Board& operator = (const Board&) = delete;

    void dropStone(const Stone& stone, const Position& position);
    void show() const;
private:
    CellsContainerType cells;
};


