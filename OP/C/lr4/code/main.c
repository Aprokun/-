/*
 * С клавиатуры вводится последовательность
 * вещественных чисел, числа разделены запятыми.
 * Конец ввода – конец файла.
 * Записать введенную последовательность в строку в форме
 * с фиксированной точкой, сохранив три знака после точки
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// считывает вещественные числа из строки str и
// выводит их с тремя знаками после точки.
void printNums_fromStr_d(char *str)
{
    int sign = 1;
    size_t k = 0;
    double num = 0;

    while (*str != '\0')
    {
        while (*str == ' ' || *str == ',') str++;

        if (*str == '-')
        {
            sign = -1;
            str++;
        }

        while (*str != '.')
        {
            num = num * 10 + (*str - '0');
            str++;
        }

        str++;

        while (*str != ',' && *str != '\0')
        {
            num = num * 10 + (*str - '0');
            k++;
            str++;
        }

        num /= (pow(10,k));

        num *= sign;

        printf("%.3lf ", num);

        num = 0; k = 0;
    }
}

int main()
{
    char str[255];
    gets(str);
    printNums_fromStr_d(str);
}
