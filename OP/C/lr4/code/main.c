/*
 * С клавиатуры вводится последовательность
 * вещественных чисел, числа разделены запятыми.
 * Конец ввода – конец файла.
 * Записать введенную последовательность в строку в форме
 * с фиксированной точкой, сохранив три знака после точки
 */

#include <stdio.h>
#include <math.h>

/* считывает вещественные числа из строки str и
    выводит их с тремя знаками после точки. */
void print_nums_from(char *str)
{
    int sign, psign, k, p;
    double num;

    while (*str != '\0')
    {
        sign = 1, psign = 1,
        k = 0, p = 0, num = 0;

        while (*str == ' ' || *str == ',') str++;

        if (*str == '-')
        {
            sign = -1;
            str++;
        }
        else if (*str == '+')
            str++;

        while (*str >= '0' && *str <= '9')
        {
            num = num * 10 + (*str - '0');
            str++;
        }

        if (*str == '.') {
            str++;
            while ((*str >= '0') && (*str <= '9')) {
                ++k;
                num = num * 10 + *str - '0';
                ++str;
            }
        }

        if ((*str == 'e') || (*str == 'E')) {
            str++;

            if (*str == '-') {
                psign = -1;
                str++;
            }

            while ((*str >= '0') && (*str <= '9')) {
                p = p * 10 + *str - '0';
                ++str;
            }

            p *= psign;
        }

        int l = p - k;

        if (l < 0)
            num = (num * sign) / pow(10, -l);
        else
            num = num * sign * pow(10, l);

        printf("%.3lf ", num);
    }
}

int main()
{
    char str[255];
    gets(str);
    print_nums_from(str);
}
