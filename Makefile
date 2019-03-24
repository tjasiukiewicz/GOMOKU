.PHONY := clean
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
CXX := g++
LDFLAGS := 

OBJECTS := main.o board.o stone.o position.o player.o game.o

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

board.o: board.cpp board.hpp stone.hpp stone_color.hpp position.hpp
game.o: game.cpp game.hpp player.hpp stone_color.hpp board.hpp stone.hpp \
 position.hpp
main.o: main.cpp game.hpp player.hpp stone_color.hpp board.hpp stone.hpp \
 position.hpp
player.o: player.cpp player.hpp stone_color.hpp
position.o: position.cpp position.hpp board.hpp stone.hpp stone_color.hpp
stone.o: stone.cpp stone.hpp stone_color.hpp
