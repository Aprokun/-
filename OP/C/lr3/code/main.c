/* Удалить в шестнадцатеричной записи данного целого числа четные цифры. */

#include <stdio.h>
#include <stdlib.h>

//вывод беззнакового числа num в двоичном представлении.
void print_bin_u(unsigned int num)
{
    if (num)
    {
        print_bin_u(num >> 1);
        printf("%i",num & 1);
    }
}

//вывод числа num в двоичном представлении.
void print_bin(int num)
{
    if (num < 0)
    {
        putchar('-');
        print_bin_u(-num);
    }
    else if (num > 0)
    {
        print_bin_u(num);
    }
    else
        printf("0");
}

// возвращает преобразованное десятичное число num,
// в шестнадцатеричной записи которого отсутствуют чётные цифры.
int hex_without_evens(int num)
{
    size_t i = 0;
    int hex_num_in_dec = 0,
        sign = 1,
        dig;

    if (num < 0)
    {
        sign = -1;
        num = -num;
    }

    while (num > 0)
    {
        dig = num % 16;

        if ((dig & 1) == 1)
        {
            hex_num_in_dec += dig * (1 << (4*i));
            ++i;
        }

        num >>= 4;
    }

    hex_num_in_dec *= sign;

    return hex_num_in_dec;
}

int main()
{
    printf("Input decimal num:\n");
    int num;
    scanf("%i",&num);
    printf("Inputted num in bin\n");
    print_bin(num);
    printf("\n");

    int new_num = hex_without_evens(num);
    printf("Inputted num in hex:\n");

    if (num < 0)
    {
        printf("-%X\n", -num);
        printf("Inputted num in hex without even: -%X\n", -new_num);
    }
    else if (num >= 0)
    {
        printf("%X\n", num);
        printf("Inputted num in hex without even: %X\n", new_num);
    }

    printf("Inputted num in hex without even in bin:\n");
    print_bin(new_num);
}