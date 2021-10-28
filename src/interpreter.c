#include <stdio.h>
#include "CPU.h"
#include "Machine.h"

unsigned char instruction;

void opcode0(chip cpu)
{
    #ifdef DEBUG
    printf("I reached the interpreter\n");
    #endif

    instruction = cpu.instruction;

    if(instruction == 0x00E0)
    {
        for(int i = 0; i < sizeof(display)/sizeof(display[0]); i++)
        {
            display[i] = 1;
        }
    }

    if(instruction == 0x00EE)
    {
        cpu.programCounter = cpu.stack[0];
        cpu.stkPtr -= 1;
    }
}

void opcode1(chip cpu)
{
    instruction = cpu.instruction;
    cpu.programCounter = instruction | 0x0FFF;
}

void opcode2(chip cpu)
{
    cpu.stack[cpu.stkPtr] = cpu.programCounter;
    cpu.stkPtr += 1;  
}

void opcode3(chip cpu)
{
    instruction = cpu.instruction;
    uint8_t targetRegister = instruction | 0x0F00;
    uint8_t comparison = instruction | 0x00FF;

    if(cpu.V[targetRegister] == comparison)
    {
        cpu.programCounter += 2;
    }    
}

void opcode4(chip cpu)
{
    
}

void opcode5(chip cpu)
{
    
}

void opcode6(chip cpu)
{
    
}

void opcode7(chip cpu)
{
    
}

void opcode8(chip cpu)
{
    
}

void opcode9(chip cpu)
{
    
}

void opcodeA(chip cpu)
{
    
}

void opcodeB(chip cpu)
{
    
}

void opcodeC(chip cpu)
{
    
}

void opcodeD(chip cpu)
{
    
}

void opcodeE(chip cpu)
{
    
}

void opcodeF(chip cpu)
{
    
}