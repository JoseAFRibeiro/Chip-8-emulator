#include <stdio.h>
#include "CPU.h"
#include "Machine.h"

//might use these later so might as well leave them here 
#define GET_3_HEX_DIGIT(opcode) (opcode & 0x0F00) >> 8
#define GET_2_HEX_DIGIT(opcode) (opcode & 0x00F0) >> 4
#define GET_1_HEX_DIGIT(opcode) (opcode & 0x000F)

uint16_t instruction;
uint16_t targetRegister;
uint8_t targetRegisterX; 
uint8_t targetRegisterY;

void opcode0(chip *cpu)
{
    instruction = cpu->instruction;

    if(instruction == 0x00E0)
    {
        for(int i = 0; i < sizeof(display)/sizeof(display[0]); i++)
        {
            display[i] = 1;
        }
    }
    else
    {
        cpu->stkPtr -= 1;
        cpu->programCounter = cpu->stack[0];
    }
}
void opcode1(chip *cpu)
{
    instruction = cpu->instruction;
    cpu->programCounter = instruction & 0x0FFF;
}

void opcode2(chip *cpu)
{
    cpu->stack[cpu->stkPtr] = cpu->programCounter;
    cpu->stkPtr += 1;  
}

void opcode3(chip *cpu)
{
    instruction = cpu->instruction;
    targetRegister = (instruction & 0x0F00) >> 8;
    uint8_t comparison = instruction & 0x00FF;

    if(cpu->V[targetRegister] == comparison)
    {
        cpu->programCounter += 2;
    }    
}

void opcode4(chip *cpu)
{
    instruction = cpu->instruction;
    targetRegister = (instruction & 0x0F00) >> 8;
    if(cpu->V[targetRegister != (instruction & 0x00FF)])
    {
        cpu->programCounter += 2;
    }
}

void opcode5(chip *cpu)
{
    instruction = cpu->instruction;
    targetRegisterX = (instruction & 0x0F00) >> 8;
    targetRegisterY = (instruction & 0x00F0) >> 8;

    if(targetRegisterX == targetRegisterY)
    {
        cpu->programCounter+= 2;
    }

}

void opcode6(chip *cpu)
{
    instruction = cpu->instruction;
    uint8_t value = instruction & 0x00FF;
    targetRegister = (instruction & 0x0F00) >> 8;
    cpu->V[targetRegister] = value;
}

void opcode7(chip *cpu)
{
    instruction = cpu->instruction;
    uint8_t value = instruction & 0x00FF;
    targetRegister = (instruction & 0x0F00) >> 8;
    cpu->V[targetRegister] += value;
}

void opcode8(chip *cpu)
{
    instruction = cpu->instruction;
    uint8_t subtype = instruction & 0x000F;
    targetRegisterX = (instruction & 0x0F00) >> 8;
    targetRegisterY = (instruction & 0x00F0) >> 4;

    switch (subtype)
    {
    case 0:
        cpu->V[targetRegisterX] = cpu->V[targetRegisterY];
        break;
    
    default:
        break;
    }
}

void opcode9(chip *cpu)
{
    
}

void opcodeA(chip *cpu)
{
    cpu->I = (cpu->instruction & 0x0FFF);
}

void opcodeB(chip *cpu)
{
    
}

void opcodeC(chip *cpu)
{
    
}

void opcodeD(chip *cpu)
{
    
}

void opcodeE(chip *cpu)
{
    
}

void opcodeF(chip *cpu)
{
    
}