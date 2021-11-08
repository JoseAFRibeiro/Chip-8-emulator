#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include <stdint-gcc.h>

typedef struct Chip8_CPU
{
    uint16_t stack[16];
    uint16_t stkPtr;
    uint16_t programCounter;
    uint16_t instruction;
    uint16_t I;
    uint8_t V[0xF];
    uint8_t buzzer, timer;
    uint8_t delay, sound;
    


}chip;


#endif // CPU_H_INCLUDED
