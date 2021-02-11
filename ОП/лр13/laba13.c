#define _CRT_NO_WARNINGS
#include <stdio.h>

int main() 
{
    char str[255];

    str = gets_s();

    char c;

    c = getchar();

    puts(str);

    putchar(c);

}