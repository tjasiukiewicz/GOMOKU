#include "game_rule.hpp"
#include "position.hpp"
#include <array>
#include <cstddef>
#include <iterator>
#include <vector>

namespace {

constexpr static std::size_t CheckRange = 3;

std::size_t minIndex(std::size_t index) {
    return index < (CheckRange - 1) ? 0: index - (CheckRange - 1);
}

std::size_t maxIndex(std::size_t index) {
    return index < (BOARD_WIDTH - CheckRange) ? index + CheckRange: BOARD_WIDTH;
}

template<typename ForwardIter, typename Comparator>
ForwardIter find_adjacent_count(ForwardIter startIt,
    ForwardIter endIt, std::size_t count, Comparator comparator) {
    if(count <= 1) {
        return startIt;
    } else if(static_cast<std::size_t>(std::distance(startIt, endIt)) >= count) {
        auto current_count = 1UL;
        auto next = std::next(startIt);
        for(;next != endIt; ++next) {
            if(comparator(*startIt, *next)) {
                if(++current_count == count) {
                    return startIt;
                }
            } else {
                startIt = next;
                current_count = 1;
            }
        }
    }
    return endIt;
}

} // anonymous namespace

GameRule::GameRule()
    : cells{nullptr} {
}

void GameRule::addCells(const BoardCellsContainerType& cells) {
    this->cells = &cells;
}

bool GameRule::winOnPosition(const Position& position) const {
    if(!cells) {
        return false;
    }

    auto buildVertical = [this](const Position& position) {
        auto [col, row] = position.getIndexes();
        auto startIndex = minIndex(col);
        auto endIndex = maxIndex(col);

        std::vector<const BoardCellsContainerType::value_type::value_type *> ptrCells;
        for(auto i = startIndex; i < endIndex; ++i) {
            ptrCells.emplace_back(&((*(this->cells))[row][i]));
        }
        return ptrCells;
    };

    auto ptrCells = buildVertical(position);
    if(find_adjacent_count(ptrCells.cbegin(), ptrCells.cend(), CheckRange,
        [](const auto& first, const auto& second) {
            return (*first && *second) ? *(*first) == *(*second): false;
        }) != ptrCells.cend()) {
            return true;
    }

    return false;
}
