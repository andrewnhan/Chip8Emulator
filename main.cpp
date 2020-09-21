#include <iostream>

#include "Chip8.h"

Chip8 chip8;

int main(int argc, char **argv) { 
	if(!argc) {
		std::cout << "You need to add filename of the rom in the arguments" << std::endl;
		return 1;
	} else if(argc > 2) {
		std::cout << "You have too many arguments" << std::endl;
	}
	if(!chip8.loadRom(argv[1])) {
		return 1;
	}

	return 0;
 }
