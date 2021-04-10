/*
 * С клавиатуры вводится последовательность
 * вещественных чисел, числа разделены запятыми.
 * Конец ввода – конец файла.
 * Записать введенную последовательность в строку в форме
 * с фиксированной точкой, сохранив три знака после точки
 */

#include <stdio.h>
#include <math.h>

/* считывает вещественные числа из потока ввода и
    выводит их с тремя знаками после точки. */
void print_nums_from()
{
    int sign, psign, k, p, i = 0;
    double num;
    char c;
    char str[255];

    gets(str);

    while (str[i] != '\0')
    {
        sign = 1, psign = 1,
        k = 0, p = 0, num = 0;

        while (str[i] == ' ' || str[i] == ',') i++;

        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;

        while (str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + (str[i] - '0');
            i++;
        }

        if (str[i] == '.') {
            i++;
            while ((str[i] >= '0') && (str[i] <= '9')) {
                ++k;
                num = num * 10 + str[i] - '0';
                i++;
            }
        }

        if ((str[i] == 'e') || (str[i] == 'E')) {
            i++;

            if (str[i] == '-') {
                psign = -1;
                i++;
            }

            while ((str[i] >= '0') && (str[i] <= '9')) {
                p = p * 10 + str[i] - '0';
                i++;
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
    print_nums_from();
}
