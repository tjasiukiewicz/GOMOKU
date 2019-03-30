#pragma once

#include <array>
#include <optional>
#include "stone.hpp"

constexpr static std::size_t BOARD_WIDTH = 15;

using BoardCellsContainerType = std::array<std::array<std::optional<Stone>, BOARD_WIDTH>, BOARD_WIDTH>;
