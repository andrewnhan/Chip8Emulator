#include "Chip8.h"

Chip8::Chip8() {
  programCounter = START_ADDRESS;
  opCode = 0;
  indexRegister = Register(0);

  for (int i = 0; i < 16; i++) {
    gprs.push_back(Register(0));
    keys.push_back(0);
  }
  for (int i = 0; i < 4096; i++) {
    memory.push_back(0);
  }
  for (int i = 0; i < 2048; i++) {
    graphicsBuffer.push_back(i);
  }

  zeroOps.insert(std::make_pair(0x00, &Chip8::Op0nnn));
  zeroOps.insert(std::make_pair(0xee, &Chip8::Op00e0));
  zeroOps.insert(std::make_pair(0xe0, &Chip8::Op00ee));

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


}

// Ops
void Chip8::Op0nnn(uint16_t instruction) {
	programCounter = instruction & (0x0FFFu);
}

void Chip8::Op00e0(uint16_t instruction) {
	// clear the display
	// empty
}

void Chip8::Op00ee(uint16_t instruction) {
	programCounter = functionStack.top();
	functionStack.pop();
}

void Chip8::Op1nnn(uint16_t instruction) {
	programCounter = instruction & (0x0FFFu);
}

void Chip8::Op2nnn(uint16_t instruction) {
	if(functionStack.size() > 16) {
		// Throw an exception here in the future.
		return;
	}
	functionStack.push(programCounter);
	programCounter = instruction & (0x0FFFu);
}

void Chip8::Op3xkk(uint16_t instruction) {
	uint8_t registerNumber = instruction & (0x0F00u);
	uint8_t comparisonValue = instruction & (0x00FFu);
	if(gprs.at(registerNumber).value == comparisonValue) {
		programCounter += 2;
	}
}

void Chip8::Op4xkk(uint16_t instruction) {
	uint8_t registerNumber = instruction & (0x0F00u);
	uint8_t comparisonValue = instruction & (0x00FFu);
	if(gprs.at(registerNumber).value != comparisonValue) {
		programCounter += 2;
	}
}