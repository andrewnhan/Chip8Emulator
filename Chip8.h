#include <cstdint>
#include <vector>

const int START_ADDRESS = 0x200;

class Chip8 {
private:
  class Register {
  public:
    Register(uint8_t val = 0) : value(val){};
    uint8_t value;
  };

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
  std::vector<uint16_t> stack;
  uint8_t stackPointer;
  // Timer
  uint8_t delayTimer;
  uint8_t soundTimer;
  // keys
  std::vector<uint8_t> keys;
  // graphics
  std::vector<uint32_t> graphicsBuffer;

public:
  Chip8();
};
