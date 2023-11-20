#include "../headers/stdio.h"
#include "../headers/keyBoard.h"
#include "../headers/types.h"
extern int main() 
{
    printf(">");
    string input=readStr();
    printf(input);
    return 0;  
}

