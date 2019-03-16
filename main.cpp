#include "board.hpp"
#include "position.hpp"
#include "stone.hpp"
#include "stone_color.hpp"

int main() {
    Board board;
    Stone stoneWhite{StoneColor::White};
    Stone stoneBlack{StoneColor::Black};
    Position position1(15, 15);
    Position position2(1, 1);
    board.dropStone(stoneWhite, position1);
    board.dropStone(stoneBlack, position2);
    board.show();
}
