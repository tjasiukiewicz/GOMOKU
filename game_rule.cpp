#include "game_rule.hpp"
#include "position.hpp"

namespace {

template<typename ForwardIter, typename Comparator>
ForwardIter find_adjacent_count(ForwardIter startIt,
    ForwardIter endIt, std::size_t count, Comparator comparator) {
    if(static_cast<std::size_t>(std::distance(startIt, endIt)) >= count) {
        auto current_count = 1;
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

bool GameRule::winOnPosition(const Position& position) const {
    (void) position;
    return false;
}
