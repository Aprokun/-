#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[254];
	char cvar;
	int ivar = 0;
	float fvar = 0.0;
	double dvar = 0.000;
	
	puts("Input string:");
	gets_s(str,255);
	puts("Inputted string:");
	puts(str);

	puts("Input symbol:");
	cvar = getchar();
	puts("Inputted symbol:");
	putchar(cvar);
	

	scanf("\nInput int: %i \n Input float: %f", &ivar, &fvar);
	printf("Inputted int: %i \n Inputted float: %f", ivar, fvar);
}