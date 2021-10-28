#include <stdio.h>
#include <stdlib.h>
#include "ROMInput.h"
#include "Machine.h"


int main()
{
    printf("Starting Chip-8 emulator\n");

    /*if(argc == 0)
    {
        printf("Incorrect program usage. Please provide a path to a ROM file");
        return 1;
    }*/
    startMachine();
    return 1;
}
