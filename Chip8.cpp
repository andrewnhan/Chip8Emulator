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
