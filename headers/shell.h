#include "stdio.h"
#include "types.h"
#include "string.h"
#include "keyBoard.h"
void runCommand(const string command);
void startShell() 
{
    _printf("IDOS CANADA BC SOUTH SURREY v1.0\n",GREEN);
    _printf("2023\n",GREEN);
    _printf("IDOS>",RESET);
    while(1)
    {
        string input = readStr();
        runCommand(input);
    }
}
void runCommand(const string command)
{
    if(strcmp(command,"cls")==0)
    {
        
    }
}

 