#include "Chip8.h"

Chip8::Chip8() {
  programCounter = START_ADDRESS;
  opCode = 0;
  indexRegister = 0;
  stackPointer = 0;

  for (int i = 0; i < 16; i++) {
    gprs.push(Register(0));
    stack.push(0);
    keys.push(0);
  }
  for (int i = 0; i < 4096; i++) {
    memory.push(0);
  }
  for (int i = 0; i < 2048; i++) {
    graphicsBuffer.push(i);
  }

  delayTimer = 0;
  soundTimer = 0;
}
