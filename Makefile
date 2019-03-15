.PHONY := clean
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
CXX := clang++
LDFLAGS := 

OBJECTS := main.o board.o stone.o position.o

main: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

clean:
	@rm -f main $(OBJECTS) > /dev/null 2>&1

board.o: board.cpp board.hpp
main.o: main.cpp board.hpp
position.o: position.cpp position.hpp
stone.o: stone.cpp stone.hpp stone_color.hpp
