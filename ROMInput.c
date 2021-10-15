//includes
#include <stdio.h>
#include <stdlib.h>


FILE *rom;
char *fileBuffer;

void fileReader(const char *fileName, int *size, char *programBuffer)
{
    //open the ROM file
    rom = fopen(fileName, "rb");
    //check if we were successful
    if(rom == NULL)
    {
        printf("File not found\n");
        return NULL;
    }

    //seek the end of the file so we can get the size
    fseek(rom, 0, SEEK_END);
    //get file size
    long fileSize = ftell(rom);
    //a dumb way to return the size to the calling function without returning
    *size = fileSize;
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
    *programBuffer = fileBuffer;
}

void freeFile()
{
    free(fileBuffer);
    fclose(rom);
}
