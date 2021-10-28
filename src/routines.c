//includes
#include <stdio.h>
#include "BIOS.h"
#include "CPU.h"
#include "ROMInput.h"

void zeroRegs(chip proc)
{
    for(int i = 0; i <= 0xF; i++)
    {
        proc.V[i] = 0x0;
    }
    proc.buzzer = 0;
    proc.delay = 0;
    proc.stkPtr = 0;
}

void clearRAM(unsigned char RAM[])
{
    for(int i = 0; i <= sizeof(*RAM)/sizeof(RAM[0]); i++ )
    {
        RAM[i] = 0;
    }
}

void loadFont(unsigned char RAM[])
{
    for(int i = 0x0; i <= FONT_ARRAY_SIZE; i++ )
    {
        RAM[i] = font[i];
    }
}

void initialize(chip proc, unsigned char RAM[])
{
    zeroRegs(proc);
    clearRAM(RAM);
    loadFont(RAM);
}

void loadProgram(char *programName, unsigned char RAM[])
{

    fileReader(programName, RAM, PROGRAM_START_ADDRESS);
    freeFile();
}

void reset()
{
    printf("not implemented yet :p");
}
