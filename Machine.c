#include "CPU.h"
#include "ROMInput.h"

//functions

//machine specs
unsigned char RAM[4096];
unsigned short display[64*32];

chip proc;
char *testFile = "Landing.ch8";

void startMachine()
{
    initialize(proc, RAM);
    loadProgram(testFile, RAM);
}

