#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED
#include "CPU.h"

typedef void (*opcode_fptr)(chip *);
//functions 
void opcode0(chip *cpu);
void opcode1(chip *cpu);
void opcode2(chip *cpu);
void opcode3(chip *cpu);
void opcode4(chip *cpu);
void opcode5(chip *cpu);
void opcode6(chip *cpu);
void opcode7(chip *cpu);
void opcode8(chip *cpu);
void opcode9(chip *cpu);
void opcodeA(chip *cpu);
void opcodeB(chip *cpu);
void opcodeC(chip *cpu);
void opcodeD(chip *cpu);
void opcodeE(chip *cpu);
void opcodeF(chip *cpu);
//opcode Lookup Table
static const opcode_fptr (*opcodeLUT[16])(chip *cpu)={
    opcode0, opcode1, opcode2, opcode3, opcode4,
    opcode5, opcode6, opcode7, opcode8, opcode9,
    opcodeA, opcodeB, opcodeC, opcodeD, opcodeE,
    opcodeF
};
//the original Chip-8 implementation has 36 instructions. In order to make a smaller array we are going
//to use the most significant 4 bits (0x[thisone]000) to tell us which type of codes we want to use
#endif