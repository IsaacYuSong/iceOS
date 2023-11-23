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

    switch (c)
    {
    case 0x10: return 'q'; break;
    case 0x11: return 'w'; break;
    case 0x12: return 'e'; break;
    case 0x13: return 'r'; break;
    case 0x14: return 't'; break;
    case 0x15: return 'y'; break;
    case 0x16: return 'u'; break;
    case 0x17: return 'i'; break;
    case 0x18: return 'o'; break;
    case 0x19: return 'p'; break;
    case 0x1E: return 'a'; break;
    case 0x1F: return 's'; break;
    case 0x20: return 'd'; break;
    case 0x21: return 'f'; break;
    case 0x22: return 'g'; break;
    case 0x23: return 'h'; break;
    case 0x24: return 'j'; break;
    case 0x25: return 'k'; break;
    case 0x26: return 'l'; break;
    case 0x2C: return 'z'; break;
    case 0x2D: return 'x'; break;
    case 0x2E: return 'c'; break;
    case 0x2F: return 'v'; break;
    case 0x30: return 'b'; break;
    case 0x31: return 'n'; break;
    case 0x32: return 'm'; break;
    case 0x08: return '\b';
    }
    return c;
}

string readStr(string buffer, int bufferSize)
{
    int index = 0;
    while (1) {
        char input = getc();

        if (input == '\n')
        {
            printc('\n');
            buffer[index] = '\0';
            return buffer;
        }
        else if (input == '\b' && index > 0)
        {
            index--;
            printc('\b');
            printc(' ');
            buffer[index] = '\0';
        }
        else if (input >= ' ' && index < bufferSize - 1) {
            buffer[index] = input;
            index++;
            printc(input);
        }
    }

    return buffer;
}

