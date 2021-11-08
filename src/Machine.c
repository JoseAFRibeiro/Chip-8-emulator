#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "CPU.h"
#include "ROMInput.h"
#include "routines.h"
#include "interpreter.h"
#include "Machine.h"

//macros
#define GET_OPCODE_MSB(opcode) opcode >> 12 
//funcions
void initialize();
void emulateCycle();

chip proc;

char *testFile = "./ROM/Landing.ch8";

void startMachine()
{
    initialize(proc, RAM);
    loadProgram(testFile, 0x200);
    emulateCycle();
}

void emulateCycle()
{
    proc.programCounter = 0x200;

    while (1)
    {

    proc.instruction = RAM[proc.programCounter];
    proc.instruction = proc.instruction << 8;   
    proc.instruction = proc.instruction | RAM[proc.programCounter + 1];
    /*when the cycle ends, move the PC by 2 ram locations
    0x200     instruction
    0x200 + 1 data
    0x200 + 2 instruction
    0x200 + 3 data
    */

    #ifdef DEBUG 
        printf("%x\n", proc.instruction);
    #endif
    //get the significan't bit only bit shifting
    opcodeLUT[GET_OPCODE_MSB(proc.instruction)](&proc);

    proc.programCounter += 2;
    //if allowed to run ad eternum it will eventually ty to read outside the RAM array and segfault... so don't do that
    }

}