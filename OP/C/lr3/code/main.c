///Удалить в шестнадцатеричной записи данного целого числа четные цифры.

#include <stdio.h>
#include <stdlib.h>

static char hex_digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int rev_num(int num)
{
    int res = 0;

    while (num > 0)
    {
        res = num * 10 + num % 10;
        num /= 10;
    }

    return res;
}

int dec_to_bin(int num)
{
    int res = 0;

    while (num > 0)
    {
        res = 10 * res + num % 2;
        num /= 2;
    }

    res = rev_num(res);

    return res;
}

int pow(int num, size_t degree)
{
   int res = 1;

   for (size_t i = 0; i < degree; i++)
   {
       res *= num;
   }

    return res;
}

int dec_to_hex_wtht_evns(int dec_num)
{
    int dig, i = 0, hex_num_in_dec = 0;

    while (dec_num > 0)
    {
        dig = dec_num % 16;

        if (dig % 2 != 0)
        {
            hex_num_in_dec += dig * pow(16, i);
            ++i;
        }

        dec_num /= 16;
    }

    return hex_num_in_dec;
}

int main()
{
    printf("Input decimal num:\n");
    int num;
    scanf("%i", &num);

    int bin_num = dec_to_bin(num);
    printf("Inputted dec num in binary: %i", bin_num);


    int hex_num_in_dec = dec_to_hex_wtht_evns(num);
    int hex_num_in_bin = dec_to_bin(hex_num_in_dec);

    printf("Inputted decimal num in hexadecimal: %X\n",num);
    printf("Inputted decimal num in hexadecimal without evens: %X\n",hex_num_in_dec);
    printf("Inputted decimal num in hexadecimal without evens in bin: %i", hex_num_in_bin);
}
