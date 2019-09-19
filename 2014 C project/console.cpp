#include <stdio.h>
#include <windows.h>
#include "console.h"

void textcolor(unsigned int text, unsigned int back)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | back);
}
