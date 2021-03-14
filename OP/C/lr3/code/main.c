/* Удалить в шестнадцатеричной записи данного целого числа четные цифры. */

#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// меняет местами символы a и b.
void ch_swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// переворачивает строку str размера size.
void rev_str(char str[], size_t size)
{
    size_t i = 0, j = size - 1;

    while (i < j)
    {
        ch_swap(&str[i], &str[j]);
        i++; j--;
    }
}

// возвращает двоичное представление числа num в виде строки.
// примечание: данная функция выделяет память под возвращаемую строку
char *dec_to_bin(int num)
{
    char *res = (char*)calloc(sizeof(char), 255);
    int i = 0;

    while (num > 0)
    {
        res[i] = (num & 1) == 0 ? '0' : '1';
        num >>= 1;
        i++;
    }

    rev_str(res,i);
    return res;
}

// возвращает num в степени degree.
int powi(int num, size_t degree)
{
    int res = 1;

    for (size_t i = 0; i < degree; i++)
    {
        res *= num;
    }

    return res;
}

// возвращает преобразованное десятичное число dec_num,
// в шестнадцатеричной записи которого отсутствуют чётные цифры.
int dec_to_hex_wtht_evns(int dec_num)
{
    int dig, i = 0, hex_num_in_dec = 0;

    while (dec_num > 0)
=======
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
>>>>>>> 9269fdb697c312c2f88d7d991f6ff8d94b1da455
    {
        dig = num % 16;

<<<<<<< HEAD
        if (dig % 2 != 0)
        {
            hex_num_in_dec += dig * powi(16, i);
            ++i;
        }

        dec_num >>= 4;
=======
        if ((dig & 1) == 1)
        {
            hex_num_in_dec += dig * (1 << (4*i));
            ++i;
        }

        num >>= 4;
>>>>>>> 9269fdb697c312c2f88d7d991f6ff8d94b1da455
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

<<<<<<< HEAD
    char *bin_num = dec_to_bin(num);
    printf("Inputted dec num in binary: %s\n", bin_num);


    int hex_num_in_dec = dec_to_hex_wtht_evns(num);
    char *hex_num_in_bin = dec_to_bin(hex_num_in_dec);

    printf("Inputted decimal num in hexadecimal: %X\n", num);
    printf("Inputted decimal num in hexadecimal without evens: %X\n", hex_num_in_dec);
    printf("Inputted decimal num in hexadecimal without evens to bin: %s", hex_num_in_bin);

    free(hex_num_in_bin);
    free(bin_num);
}
=======
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
>>>>>>> 9269fdb697c312c2f88d7d991f6ff8d94b1da455
