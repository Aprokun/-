/* Удалить в шестнадцатеричной записи данного целого числа четные цифры. */

#include <stdio.h>
#include <stdlib.h>

//вывод беззнакового числа num в двоичном представлении.
void print_int_in_bin_u(unsigned int num)
{
    if (num)
    {
        print_int_in_bin_u(num >> 1);
        printf("%i",num & 1);
    }
}

//вывод числа num в двоичном представлении.
void print_int_in_bin(int num)
{
    if (num < 0)
    {
        putchar('-');
        print_int_in_bin_u(- (unsigned int) num);
    }
    else if (num > 0)
    {
        print_int_in_bin_u(num);
    }
    else
    {
        putchar('0');
    }
}

// возвращает преобразованное десятичное число dec_num,
// в шестнадцатеричной записи которого отсутствуют чётные цифры.
int dec_to_hex_wtht_evns(int dec_num)
{
    size_t i = 0;
    int hex_num_in_dec = 0,
        sym = 1,
        dig;

    if (dec_num < 0)
    {
        sym = -1;
        dec_num *= sym;
    }

    while (dec_num > 0)
    {
        dig = dec_num % 16;

        if ((dig & 1) == 1)
        {
            hex_num_in_dec += dig * (1 << (4*i));
            ++i;
        }

        dec_num >>= 4;
    }

    hex_num_in_dec *= sym;

    return hex_num_in_dec;
}

int main()
{
    printf("Input decimal num:\n");
    int num;
    scanf("%i",&num);
    printf("Inputted num in bin\n");
    print_int_in_bin(num);
    printf("\n");

    int hex_num_in_dec = dec_to_hex_wtht_evns(num);
    printf("Inputted num in hex:\n");

    if (num < 0)
    {
        printf("-%X\n", -num);
        printf("Inputted num in hex without even: -%X\n", -hex_num_in_dec);
    }
    else if (num > 0)
    {
        printf("%X\n", num);
        printf("Inputted num in hex without even: %X\n", hex_num_in_dec);
    }

    printf("Inputted num in hex without even in bin:\n");
    print_int_in_bin(hex_num_in_dec);
}