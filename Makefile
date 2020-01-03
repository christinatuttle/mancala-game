#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = board.o main.o game.o
TARGET = mancala
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
board.o: board.cpp board.hpp player.hpp
game.o: game.cpp game.hpp board.hpp
main.o: game.o
mancala: main.o