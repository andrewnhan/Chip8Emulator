CXX = g++
CXXFLAGS = -Wall -Werror -O2

Chip8Emulator: main.o Chip8.o
	$(CXX) -o Chip8Emulator main.o Chip8.o  $(CXXFLAGS)

clean: 
	rm *.o Chip8Emulator