#ifndef STDIO_H
#define STDIO_H
#include "types.h"
static int offset = 0;
void printc(const char c) 
{
    volatile char* video_memory = (char*)0xb8000;
    if (c == '\n') 
    {
        offset = (offset / 80 + 1) * 80;
    } 
    else 
    {
        video_memory[offset * 2] = c;
        offset++;
    }

}




void *malloc(int bytes)
{
	char variable[bytes];
	return &variable;
}


void printf(string str) 
{
    while (*str != '\0') 
    {
        printc(*str);
        str++;
    }
}


#endif




