#ifndef ROMINPUT_H_INCLUDED
#define ROMINPUT_H_INCLUDED

#include "commands.h"
#include <stdlib.h>
#include <stdio.h>

int file_in(struct chip8 *CPU, const char *filename, const char *mode)
{
    FILE * rom = fopen(filename, mode);

    if(rom == NULL)
    {
        printf("no file found\n");
        return 0;
    }

    fseek(rom, 0, SEEK_END);
    long file_size = ftell(rom);
    rewind(rom);

    char *file_buffer = (char*)malloc(sizeof(char)* file_size);

    size_t result = fread(file_buffer,1, file_size, rom);

    if((4096- 512) > file_size)
    {
        for(int i = 0; i < file_size; i++)
        {
            CPU->memory[i + 512] = file_buffer[i];
        }
    }else
    {
         printf("error: not enough memory");
         return 0;
    }
    fclose(rom);
    free(file_buffer);

    return 1;
}

#endif // ROMINPUT_H_INCLUDED
