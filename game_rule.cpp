#include "game_rule.hpp"
#include "position.hpp"
#include <array>
#include <cstddef>
#include <iterator>
#include <vector>
#include <algorithm>

namespace {

constexpr static std::size_t CheckRange = 5;

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

    auto findAdjacent = [](auto checkFunction, const Position& position) {
        auto ptrCells = checkFunction(position);
        if(find_adjacent_count(ptrCells.cbegin(), ptrCells.cend(), CheckRange,
            [](const auto& first, const auto& second) {
                return (*first && *second) ? *(*first) == *(*second): false;
            }) != ptrCells.cend()) {
            return true;
        }
        return false;
    };

    auto checkVertical = [this,&findAdjacent](const Position& position) {

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

        return findAdjacent(buildVertical, position);
    };

    auto checkHorizontal = [this, &findAdjacent](const Position& position) {
        auto buildHorizontal = [this](const Position& position) {
            auto [col, row] = position.getIndexes();
            auto startIndex = minIndex(row);
            auto endIndex = maxIndex(row);

            std::vector<const BoardCellsContainerType::value_type::value_type *> ptrCells;
            for(auto i = startIndex; i < endIndex; ++i) {
                ptrCells.emplace_back(&((*(this->cells))[i][col]));
            }
            return ptrCells;
        };

        return findAdjacent(buildHorizontal, position);
    };


    auto checkRightDiagonal = [this, &findAdjacent](const Position& position) {
        auto buildRightDiagonal = [this](const Position& position) {
            auto [col, row] = position.getIndexes();
            auto startDeltaIndex = std::min(col - minIndex(col), row - minIndex(row));
            auto endDeltaIndex = std::min(maxIndex(col) - col, maxIndex(row) - row);
            std::vector<const BoardCellsContainerType::value_type::value_type *> ptrCells;
            for(auto iCol = col - startDeltaIndex, iRow = row - startDeltaIndex;
                iCol < col + endDeltaIndex; ++iCol, ++iRow) {
                ptrCells.emplace_back(&((*(this->cells))[iRow][iCol]));
            }
            return ptrCells;
        };

        return findAdjacent(buildRightDiagonal, position);
    };

    auto checkLeftDiagonal = [this, &findAdjacent](const Position& position) {
        auto buildLeftDiagonal = [this](const Position& position) {
            auto [col, row] = position.getIndexes();
            auto startDeltaIndex = std::min(maxIndex(col) - col - 1, row - minIndex(row));
            auto endDeltaIndex = std::min(col - minIndex(col) , maxIndex(row) - row - 1);
            std::vector<const BoardCellsContainerType::value_type::value_type *> ptrCells;
            for(auto iCol = col + startDeltaIndex, iRow = row - startDeltaIndex;
                iRow < row + endDeltaIndex + 1; --iCol, ++iRow) {
                ptrCells.emplace_back(&((*(this->cells))[iRow][iCol]));
            }
            return ptrCells;
        };

        return findAdjacent(buildLeftDiagonal, position);
    };

    return checkVertical(position) || checkHorizontal(position)
      || checkRightDiagonal(position) || checkLeftDiagonal(position);
}
