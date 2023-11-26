#include "stdio.h"
#include "types.h"
#include "string.h"
#include "keyBoard.h"

void startShell() 
{
    char input[256]; 

    readStr(input, sizeof(input));
    printf(input);
}