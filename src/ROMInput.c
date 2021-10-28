//includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Machine.h"


FILE *rom;
char *fileBuffer;

void fileReader(const char *fileName, int programStart)
{
    //open the ROM file
    rom = fopen(fileName, "rb");
    //check if we were successful
    if(rom == NULL)
    {
        printf("File not found\n ");
        printf(fileName);
        printf("\n");
        
        #if DEBUG
        char buffer[250];
        _getcwd(buffer, sizeof(buffer)/sizeof(buffer[0]));
        printf("current working directory: %.*s ",sizeof(buffer)/sizeof(buffer[0]), buffer);
        #endif

        return;
    }

    //seek the end of the file so we can get the size
    fseek(rom, 0, SEEK_END);
    //get file size
    long fileSize = ftell(rom);
    if(fileSize > (4092 - 512))
    {
        printf("Program is too big for this Chip 8 implementation");
        return;
    }
    //go back to the start
    rewind(rom);
    //create a file buffer of type char with a size of char multiplied by the file size
    fileBuffer = (char*) malloc(sizeof(char) * fileSize);
    /*copy the file we read into  "fileBuffer", each element has a size of char (1 byte),
    it has "fileSize" of elements with a size of byte and we are copying from "rom"*/
    fread(fileBuffer, sizeof(char), fileSize, rom);
    //return a pointer to the buffer that contains the program ROM.
    int c = 0;
    int i = programStart;
    for( c ; c < fileSize; c++)
    {
        RAM[i] = fileBuffer[c];
        i++;
    }
}

void freeFile()
{
    free(fileBuffer);
    fclose(rom);
}
