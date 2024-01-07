#ifndef STDIO_H
#define STDIO_H
#include "types.h"
#define RESET   7
#define RED     4
#define GREEN   2
#define YELLOW  14
#define BLUE    1
#define MAGENTA 5
#define CYAN    3
#define ORANGE  6
#define GRAY    8
#define LIGHTBLUE  9
#define LIGHTGREEN  10
#define LIGHTCYAN   11
#define LIGHTRED    12
#define LIGHTMAGENTA 13
#define LIGHTGRAY    7
static int offset = 0;
void _printc(const char c,const char colour) 
{
    volatile char* video_memory = (char*)0xb8000;
    if (c == '\n') 
    {
        offset = (offset / 80 + 1) * 80;
    } 
    else 
    {
        int index = offset * 2;
        video_memory[index] = c;
        video_memory[index + 1] = colour;
        offset++;
    }

}
void printc(const char c)
{
    _printc(c, RESET);  
}
void _printf(string str, const char colour) 
{
    while (*str != '\0') 
    {
        _printc(*str,colour);
        str++;
    }
}
void printf(string str)
{
    _printf(str, RESET);  
}
#endif