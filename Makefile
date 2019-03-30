.PHONY := clean
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
CXX := g++
LDFLAGS := 

OBJECTS := main.o board.o stone.o position.o player.o game.o display_board.o

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

board.o: board.cpp board.hpp stone.hpp stone_color.hpp position.hpp \
 display_board.hpp
display_board.o: display_board.cpp display_board.hpp board.hpp stone.hpp \
 stone_color.hpp position.hpp
game.o: game.cpp game.hpp player.hpp stone_color.hpp board.hpp stone.hpp \
 position.hpp display_board.hpp
main.o: main.cpp game.hpp player.hpp stone_color.hpp board.hpp stone.hpp \
 position.hpp display_board.hpp
player.o: player.cpp player.hpp stone_color.hpp
position.o: position.cpp position.hpp board.hpp stone.hpp stone_color.hpp
stone.o: stone.cpp stone.hpp stone_color.hpp
