/*
 * С клавиатуры вводится последовательность
 * вещественных чисел, числа разделены запятыми.
 * Конец ввода – конец файла.
 * Записать введенную последовательность в строку в форме
 * с фиксированной точкой, сохранив три знака после точки
 */

#include <stdio.h>

/* возведение 10 в степень p */
float powf_(int p) {
    float f = 1;

    if (p > 0)
        while (p != 0) {
            --p;
            f *= 10;
        }
    else
        while (p != 0) {
            ++p;
            f /= 10;
        }

    return f;
}

/* возвращает извлечённое вещественное число из потока ввода */
float stof() {
    char c = getchar();

    if (c != '\n' && c != '\0') {
        while ((c <= ' ') && (c > '\0'))
            c = getchar();;

        int sign = 1;

        if (c == '-') {
            sign = -1;
            c = getchar();
        } else if (c == '+')
            c = getchar();

        int a = 0;

        while ((c >= '0') && (c <= '9')) {
            a = a * 10 + (c - '0');
            c = getchar();
        }

        int k = 0;

        if (c == '.') {
            c = getchar();
            while ((c >= '0') && (c <= '9')) {
                ++k;
                a = a * 10 + c - '0';
                c = getchar();
            }
        }

        int p = 0;

        if ((c == 'e') || (c == 'E')) {
            c = getchar();

            while ((c >= '0') && (c <= '9')) {
                p = p * 10 + c - '0';
                c = getchar();
            }
        }

        int l = p - k;

        if (l < 0)
            return ((a * sign) / powf_(-l));
        else
            return (a * sign * powf_(l));
    } else {
        return EOF;
    }
}

/* считывает вещественные числа из потока ввода и
    выводит их с тремя знаками после точки */
void print_nums_from()
{
    double num;

    while ((num = stof()) != EOF) {
        printf("%.3f\n", num);
    }
}

int main()
{
    print_nums_from();
}
