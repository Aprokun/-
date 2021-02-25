/* Удалить в шестнадцатеричной записи данного целого числа четные цифры. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// меняет местами символы a и b.
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

<<<<<<< HEAD
// переворачивает строку str размера size.
void rev_str(char str[], size_t size)
{
    size_t i = 0, j = size - 1;

    while (i < j)
    {
        swap(&str[i], &str[j]);
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
=======
void rev_str(char str[], size_t len)
{
    size_t i = 0, j = len - 1;

    while (i < j)
    {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++; j--;
    }
>>>>>>> refs/remotes/origin/master
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

<<<<<<< HEAD
// возвращает преобразованное десятичное число dec_num,
// в шестнадцатеричной записи которого отсутствуют чётные цифры.
=======
void print_dec_in_bin(int dec_num)
{
    char res[255];
    size_t i = 0;

    while (dec_num > 0)
    {
        if (dec_num % 2 == 0)
        {
            res[i] = '0';
            ++i;
        }
        else
        {
            res[i] = '1';
            ++i;
        }

        dec_num /= 2;
    }

    rev_str(res,i-1);
    printf("%s\n",res);
}

>>>>>>> refs/remotes/origin/master
int dec_to_hex_wtht_evns(int dec_num)
{
    int dig, i = 0, hex_num_in_dec = 0;

    while (dec_num > 0)
    {
        dig = dec_num % 16;

        if ((dig % 2 != 0) || (dig == 0))
        {
            hex_num_in_dec += dig * powi(16, i);
            ++i;
        }

        dec_num >>= 4;
    }

    return hex_num_in_dec;
}

int main()
{
    printf("Input decimal num:\n");
    int num;
    scanf("%i", &num);

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
=======
    print_dec_in_bin(num);

    int hex_num_in_dec = dec_to_hex_wtht_evns(num);

    printf("Inputted decimal num in hexadecimal: %X\n",num);
    printf("Inputted decimal num in hexadecimal without evens: %X\n",hex_num_in_dec);
    print_dec_in_bin(hex_num_in_dec);
>>>>>>> refs/remotes/origin/master
}