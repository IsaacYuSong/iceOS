#include "types.h"
#include "stdio.h"
static char buffer[256];

uint8 inb(uint16 port) 
{
    uint8 result;
    asm volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

char getc()
{
    char c;
    while ((inb(0x64) & 0x01) == 0);
    c = inb(0x60);
    switch (c) 
    {
    case 0x10: return 'q';
    case 0x11: return 'w';
    case 0x12: return 'e';
    case 0x13: return 'r';
    case 0x14: return 't';
    case 0x15: return 'y';
    case 0x16: return 'u';
    case 0x17: return 'i';
    case 0x18: return 'o';
    case 0x19: return 'p';
    case 0x1E: return 'a'; 
    case 0x1F: return 's'; 
    case 0x20: return 'd';
    case 0x21: return 'f';
    case 0x22: return 'g';
    case 0x23: return 'h';
    case 0x24: return 'j';
    case 0x25: return 'k';
    case 0x26: return 'l';
    case 0x2C: return 'z'; 
    case 0x2D: return 'x'; 
    case 0x2E: return 'c'; 
    case 0x2F: return 'v';
    case 0x31: return 'n';
    case 0x30: return 'b';
    case 0x32: return 'm'; 
    case 0x0E: return '\b';
    case 0x39: return ' '; 
    case 0x1C: return '\n';
    default: return 0;
    }
}
string readStr()
{
    int reading = 1;
    int index = 0;
    while (reading && index < sizeof(buffer) - 1)
    {
        char input = getc();
        if (input == '\b' && index > 0) 
        {
            index--;
            offset--;
            printc(' ');
            offset--;
            buffer[index] = '\0';
            continue;
        }
        // else if (input == '\n' && index <= 0)
        // {
        //     printc('\n');
        //     reading = 0;
        // }
        // else if (input == '\n')
        // {
        //     buffer[index] = '\0';
        //     return buffer
        //     reading = 0;
        // }
        else if (input >= ' ' && index < sizeof(buffer) - 1) 
        {
            buffer[index] = input;
            index++;
            printc(input);
        }
    }
    buffer[index] = '\0';
    return buffer;
}