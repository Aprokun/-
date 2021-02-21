#include <stdio.h>

int to_decimal(int hex_num)
{
    int dec_num = 0, c;

    while (hex_num > 0)
    {
        switch (hex_num % 16)
        {
            case 'F':
                c = 15;
                break;
            case 'E':
                c = 14;
                break;
            case 'D':
                c = 13;
                break;
            case 'C':
                c = 12;
                break;
            case 'B':
                c = 11;
                break;
            case 'A':
                c = 10;
                break;
            default:
                c = hex_num % 16;
                break;
        }

        s
    }
}

int reverse_num(int num)
{
    int reversed_num;

    while (num > 0)
    {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }

    return reversed_num;
}

int to_binary(int num)
{
    int bin_num = 0;

    while (num > 0)
    {
        bin_num = bin_num * 10 + num % 2;
        num /= 2;
    }

    return reverse_num(bin_num);
}

static int even_nums[] = {2, 4, 6, 8, 10, 12, 14, 16};

int main()
{
    printf("Input hexadecimal num:\n");
    int num;
    scanf("%x", &num);

    printf("%X",num % 16);

    int bin_num = toBinary(num);
    printf("Inputted num in binary: %i", bin_num);



    printf("Inputted hex num without odds%X",num);
}
