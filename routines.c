//includes
#include <stdio.h>
#include "BIOS.h"
#include "CPU.h"
#include "ROMInput.h"
//definitions
#define FONT_ARRAY_SIZE  sizeof(font)/sizeof(font[0])
#define PROGRAM_START_ADDRESS 0x200
//functions
/*void zeroRegs(chip proc);
void clearRAM(unsigned char RAM[]);
void loadFont(unsigned char RAM[]);
void loadProgram();
void reset();
void initialize();*/

void zeroRegs(chip proc)
{
    for(int i = 0; i <= 0xF; i++)
    {
        proc.V[i] = 0x0;
    }
    proc.buzzer = 0;
    proc.delay = 0;
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
    int programSize;
    int b = 0;
    char *programBuffer;
    fileReader(programName, &programSize, &programBuffer);

    for(int i = PROGRAM_START_ADDRESS; i < (programSize + PROGRAM_START_ADDRESS) ; i++)
    {
        RAM[i] = programBuffer[b];
        b++;
    }
    freeFile();
}

void reset()
{
    printf("not implemented yet :p");
}
