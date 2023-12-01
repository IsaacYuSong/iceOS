#include "types.h"
#include "stdio.h"
char getc()
{
    char c;
    asm volatile (
        "inb $0x64, %0\n"
        "testb $0x01, %0\n"
        "jz 1f\n"
        "inb $0x60, %b1\n"
        "1:\n"
        : "=a" (c)
        : "a" (0)
        );
    if (c == 0x1C) 
        return 0;
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
    case 0x35: return '\n'; 
    case 0x36: return ' ';  
    default: return 0;
    }
}

string readStr(string buffer, int bufferSize)
{
    int index = 0;
    while (1) 
    {
        char input = getc();
        if ((input == '\n' ) && index < bufferSize - 1)
        {
            printc('\n');
            buffer[index] = '\0'; 
            return buffer;  
        }
        else if (input == '\b' && index > 0) 
        {
            index--;
            offset--;
            printc(' ');
            offset--;
            buffer[index] = '\0';
            continue;
        }
        else if (input >= ' ' && index < bufferSize - 1) 
        {
            buffer[index] = input;
            index++;
            printc(input);
        }


    }
    return buffer;
}
