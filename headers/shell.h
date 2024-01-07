#include "stdio.h"
#include "types.h"
#include "string.h"
#include "keyBoard.h"
void startShell() 
{
    printf("IDOS>");


    while(1)
    {
        string input = readStr();
        /*if(strcmp(input,"help")==0)
        {
            printf("commands:\n");
            printf("cls - clears screen\n");
            printf("dir - shows the files and folders in the current directory\n");
            printf("cd - changes the directory\n");
        }*/
    }
}
