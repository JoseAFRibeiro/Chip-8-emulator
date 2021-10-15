#include "CPU.h"
#include "BIOS.h"

#define FONT_ARRAY_SIZE sizeof(font)/sizeof(font[0])
//functions
void zeroRegs();
void clearRAM();
void loadFont();
//machine specs
unsigned char RAM[4096];
unsigned short display[64*32];

chip proc;

void zeroRegs()
{
    for(int i = 0; i <= 0xF; i++)
    {
        proc.V[i] = 0x0;
    }
}

void clearRAM()
{
    for(int i = 0; i <= sizeof(RAM)/sizeof(RAM[0]); i++ )
    {
        RAM[i] = 0;
    }
}

void loadFont()
{
    for(int i = 0x0; i <= FONT_ARRAY_SIZE; i++ )
    {
        RAM[i] = font[i];
    }
}

void initialize()
{
    struct Chip8_CPU proc;
    zeroRegs();
    clearRAM();
    loadFont();
}