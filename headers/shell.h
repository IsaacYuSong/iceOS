#include "stdio.h"
#include "types.h"
#include "string.h"
#include "keyBoard.h"

void startShell() 
{
    char input[256];
    printf("IDOS>");
    readStr(input, sizeof(input));
    if(strEql(input,"clear"))
    {
        clearScreen();
    }
}