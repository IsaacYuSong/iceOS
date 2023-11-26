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

void printf(string str) 
{
    while (*str != '\0') 
    {
        printc(*str);
        str++;
    }
}


void cursorBack() 
{
    asm volatile (
        "mov $0x02, %%ah\n"   
        "mov $0x0000, %%bx\n" 
        "mov $0x01, %%ch\n"   
        "mov $0x00, %%cl\n"   
        "int $0x10\n"
        : : : "ah", "bh", "bx", "ch", "cl"
    );
}

void cursorForward() {
    asm volatile (
        "mov $0x03, %%ah\n"   // Set AH to 0x03 for "Get Cursor Position" function
        "int $0x10\n"          // Call interrupt 0x10 (video services)
        "add $0x0001, %%cx\n"  // Increment CX to move the cursor forward by one column
        "mov $0x02, %%ah\n"   // Set AH to 0x02 for "Set Cursor Position" function
        "int $0x10\n"          // Call interrupt 0x10 (video services)
        : : : "ah", "cx"
    );
}






void *malloc(int nbytes)
{
    char var[nbytes];
    return &var;
}









#endif





