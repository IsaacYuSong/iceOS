#ifndef STDIO_H
#define STDIO_H
#include "types.h"


static int offset = 0;
void printc(const char c) 
{
    volatile char* video_memory = (char*)0xb8000;
    video_memory[offset * 2] = c;
    offset++;
}

void resetOffset()
{
    offset=0;
}

void clearScreen() 
{
    uint16* videoMemory = (uint16*)0xB8000;
    const uint16 clearColor = 0x20 | (0x0F << 8); 

    for (int i = 0; i < 80 * 25; ++i) 
    {
        videoMemory[i] = clearColor;
    }
}


void printf(string str) 
{
    while (*str != '\0') 
    {
        printc(*str);
        str++;
    }
}

void *malloc(int nbytes)
{
    char var[nbytes];
    return &var;
}



#endif




