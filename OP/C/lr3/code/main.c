///Удалить в шестнадцатеричной записи данного целого числа четные цифры.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char hex_digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

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

int dec_to_hex_wtht_evns(int dec_num)
{
    int dig, i = 0, hex_num_in_dec = 0;

    while (dec_num > 0)
    {
        dig = dec_num % 16;

        if ((dig % 2 != 0) || (dig == 0))
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

    print_dec_in_bin(num);

    int hex_num_in_dec = dec_to_hex_wtht_evns(num);

    printf("Inputted decimal num in hexadecimal: %X\n",num);
    printf("Inputted decimal num in hexadecimal without evens: %X\n",hex_num_in_dec);
    print_dec_in_bin(hex_num_in_dec);
}
