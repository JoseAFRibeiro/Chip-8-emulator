#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include <stdint-gcc.h>

typedef struct Chip8_CPU
{
    uint16_t stack[16];
    uint16_t stkPtr;
    uint16_t programCounter;
    uint8_t V[0xF];
    uint8_t buzzer, timer;
    unsigned char delay, sound;
    uint16_t instruction;


}chip;


#endif // CPU_H_INCLUDED
