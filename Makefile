CXX = g++
CXXFLAGS = -Wall -Werror -O0

Chip8Emulator: main.o
      Chip8.o
			$(CXX) -o Chip8Emulator
           main.o Chip8.o  $(CXXFLAGS)
