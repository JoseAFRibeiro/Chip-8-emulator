#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED



typedef struct Chip8_CPU
{
    uint16_t stkPtr[16];
    uint16_t programCounter
    uint8_t V[0xF];
    uint8_t buzzer, timer;


}chip;


#endif // CPU_H_INCLUDED
