.PHONY := clean
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
CXX := g++
LDFLAGS :=

OBJECTS := main.o board.o stone.o position.o player.o game.o \
	display_board.o player_maker.o game_rule.o display_game.o

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

board.o: board.cpp board.hpp board_container.hpp stone.hpp \
 stone_color.hpp display_board.hpp game_rule.hpp position.hpp
display_board.o: display_board.cpp display_board.hpp board_container.hpp \
 stone.hpp stone_color.hpp
display_game.o: display_game.cpp display_game.hpp display_board.hpp \
 board_container.hpp stone.hpp stone_color.hpp player.hpp position.hpp
game.o: game.cpp game.hpp board.hpp board_container.hpp stone.hpp \
 stone_color.hpp display_game.hpp display_board.hpp game_rule.hpp \
 player.hpp player_maker.hpp position.hpp
game_rule.o: game_rule.cpp game_rule.hpp board_container.hpp stone.hpp \
 stone_color.hpp position.hpp
main.o: main.cpp game.hpp game_rule.hpp board_container.hpp stone.hpp \
 stone_color.hpp display_board.hpp display_game.hpp
player.o: player.cpp player.hpp stone_color.hpp stone.hpp
player_maker.o: player_maker.cpp player_maker.hpp stone_color.hpp \
 player.hpp
position.o: position.cpp position.hpp board_container.hpp stone.hpp \
 stone_color.hpp
stone.o: stone.cpp stone.hpp stone_color.hpp
