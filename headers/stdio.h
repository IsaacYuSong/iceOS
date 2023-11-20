#ifndef STDIO_H
#define STDIO_H
#include "types.h"


void printc(const char c) 
{
    static int offset = 0;
    volatile char* video_memory = (char*)0xb8000;
    video_memory[offset * 2] = c;
    offset++;
}

void printf(string str) {
    while (*str != '\0') {
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






