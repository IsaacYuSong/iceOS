#include "stdio.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BASE 0xb8000

#define COLOR_BLACK      0
#define COLOR_BLUE       1
#define COLOR_GREEN      2
#define COLOR_CYAN       3
#define COLOR_RED        4
#define COLOR_MAGENTA    5
#define COLOR_BROWN      6
#define COLOR_LIGHT_GRAY 7
#define COLOR_DARK_GRAY  8
#define COLOR_LIGHT_BLUE 9
#define COLOR_LIGHT_GREEN 10
#define COLOR_LIGHT_CYAN  11
#define COLOR_LIGHT_RED   12
#define COLOR_LIGHT_MAGENTA 13
#define COLOR_YELLOW      14
#define COLOR_WHITE       15

static int cursorX = 0;
static int cursorY = 0;


void clearScreen()
{
    for (int y = 0; y < VGA_HEIGHT; y++)
    {
        for (int x = 0; x < VGA_WIDTH; x++)
        {
            printc(' ', COLOR_BLACK);
        }
    }

    cursorX = 0;
    cursorY = 0;
}

void setCursorPosition(int x, int y)
{
    cursorX = x;
    cursorY = y;
}

void printc(char c, char color)
{
    volatile char* video_memory = (char*)VGA_BASE;
    int index = (cursorY * VGA_WIDTH + cursorX) * 2;

    video_memory[index] = c;
    video_memory[index + 1] = color;

    cursorX++;
    if (cursorX >= VGA_WIDTH)
    {
        cursorX = 0;
        cursorY++;
    }


    if (cursorY >= VGA_HEIGHT)
    {
        cursorY = VGA_HEIGHT - 1;

        for (int y = 1; y < VGA_HEIGHT; y++)
        {
            for (int x = 0; x < VGA_WIDTH; x++)
            {
                int destIndex = ((y - 1) * VGA_WIDTH + x) * 2;
                int srcIndex = (y * VGA_WIDTH + x) * 2;
                video_memory[destIndex] = video_memory[srcIndex];
            }
        }
        // Clear the last row
        for (int x = 0; x < VGA_WIDTH; x++)
        {
            int index = ((VGA_HEIGHT - 1) * VGA_WIDTH + x) * 2;
            video_memory[index] = ' ';
            video_memory[index + 1] = COLOR_BLACK;
        }
    }
}

// Function to print a string with color at the current cursor position
void printString(string str, char color)
{
    while (*str != '\0')
    {
        printc(*str, color);
        str++;
    }
}