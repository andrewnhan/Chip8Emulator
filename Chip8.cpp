#include "Chip8.h"

Chip8::Chip8() {
  programCounter = START_ADDRESS;
  opCode = 0;
  indexRegister = Register(0);
  stackPointer = 0;

  for (int i = 0; i < 16; i++) {
    gprs.push_back(Register(0));
    stack.push_back(0);
    keys.push_back(0);
  }
  for (int i = 0; i < 4096; i++) {
    memory.push_back(0);
  }
  for (int i = 0; i < 2048; i++) {
    graphicsBuffer.push_back(i);
  }

  delayTimer = 0;
  soundTimer = 0;
}

bool Chip8::loadRom(const char* fileName) {
	std::ifstream selectedRom(fileName, std::ios::binary);
	if(selectedRom.is_open()) {
		selectedRom.seekg(0, std::ios::end);
		std::streampos size = selectedRom.tellg();
		char* buffer = new char[size];

		selectedRom.seekg (0, std::ios::beg);
		selectedRom.read(buffer, size);

		for(int i = 0; i < size; i++) {
			memory.at(START_ADDRESS+i) = buffer[i];
			// std::cout << START_ADDRESS+i << std::endl;
		}
		return true;
	}
	return false;
}

void Chip8::cycle() {
	uint16_t upper = memory.at(programCounter);
	uint16_t lower = memory.at(programCounter+1);

	uint16_t instruction = (upper << 8u) | lower;

	programCounter += 2;

	std::cout << std::hex << static_cast<int>(instruction) << std::endl;


}