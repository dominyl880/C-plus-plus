#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <iostream>

void footerExit()
{
  printf("===============================================================================\n");
  printf("----------------------------->Press [X] to Exit<-------------------------------\n");
}

void footerReturn()
{
  printf("===============================================================================\n");
  printf("---------------------------->Press [X] to Return<------------------------------\n");
}

void footerAny()
{

  printf("===============================================================================\n");
  printf("--------------------------->Press any key to Exit<-----------------------------\n");
  getch();
}