#include <cstdint>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <fstream>

const int START_ADDRESS = 0x200;


class Chip8 {
private:
	typedef void (Chip8::*Chip8Op)(uint16_t); 

	class Register {
	public:
		Register(uint8_t val = 0) : value(val){};
		uint8_t value;
	};

	void Op0nnn(uint16_t instruction);
	void Op00e0(uint16_t instruction);
	void Op00ee(uint16_t instruction);
	void Op1nnn(uint16_t instruction);
	void Op2nnn(uint16_t instruction);
	void Op3xkk(uint16_t instruction);
	void Op4xkk(uint16_t instruction);
	
	
	
	std::map<uint8_t, Chip8Op> zeroOps;

  	// General purpose register, 16
	std::vector<Register>
      gprs;
  	// Memory
  	std::vector<uint8_t> memory;
  	// Index register
  	Register indexRegister;
  	// PC
  	uint16_t programCounter;
  	uint16_t opCode;
  	// Stack information, 16 stack levels
  	std::stack<uint16_t> functionStack;
  	// Timer
  	uint8_t delayTimer;
  	uint8_t soundTimer;
  	// keys
  	std::vector<uint8_t> keys;
  	// graphics
  	std::vector<uint32_t> graphicsBuffer;

public:
	Chip8();
	bool loadRom(const char* fileNames);
	void cycle();
};
