#include <stdio.h>
#include <math.h>

/* переворот числа num */
void numrev(int *num)
{
    int temp_num = 0;

    while (*num > 0)
    {
        temp_num = temp_num * 10 + *num % 10;
        *num /= 10;
    }

    *num = temp_num;
}
/* запись числа num в строку str */
void itos(const int num, char str[])
{
    int tnum = num;
    size_t i = 0;

    if (tnum < 0)
    {
        tnum = -tnum;
        str[i] = '-';
        i++;
    }

    numrev(&tnum);

    while (tnum > 0)
    {
        str[i] = tnum % 10 + '0';
        tnum /= 10;
        i++;
    }

    str[i] = '\0';
}

/* возвращает число, извлечённое из строки str */
int stoi(const char *str)
{
    int sign = 1,
        num = 0;

    while (*str == ' ' || *str == ',') str++;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    while ((*str != ' ') && (*str != '\0'))
    {
        num = num * 10 + (*str - '0');
        str++;
    }

    num *= sign;

    return num;
}

/* запись вещественного числа num в строку str */
void ftos(const double num, char str[])
{
    size_t i = 0, k = 0, presc = 6;
    double tnum = num;

    if (tnum < 0)
    {
        str[i] = '-';
        tnum = -tnum;
        i++;
    }

    //приведение числа к нормализованному виду
    while ((int)tnum > 0)
    {
        tnum /= 10;
        k++;
    }

    tnum *= 10;

    for ( ; k; tnum *= 10)
    {
        str[i] = (int)tnum + '0';

        i++; k--;

        if (k == 0)
        {
            str[i] = '.';
            i++;
        }

        tnum -= (int)tnum;
    }

    for (size_t j = 0; j < presc; j++)
    {
        str[i] = (int)tnum + '0';

        i++;

        tnum -= (int)tnum;
        tnum *= 10;
    }

    str[i] = '\0';
}

/* возвращает вещественное число, извлечённое из строки str */
double stof(char *str)
{
    int sign = 1;
    size_t k = 0;
    double num = 0;

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

    return num;
}

int main() {
    printf("1.Convert string to int\n"
           "2.Convert int to string\n"
           "3.Convert float to string\n"
           "4.Convert string to float\n");
    size_t v;

    scanf("%ud",&v);

    switch (v) {
        case 1:
            printf("Input string\n");

            char str_i[255];
            scanf("%s", str_i);

            printf("%d", stoi(str_i));
            break;
        case 2:
            printf("Input int\n");

            int num_i; char str1[255];
            scanf("%d", &num_i);

            itos(num_i, str1);
            printf("%s", str1);
            break;
        case 3:
            printf("Input float\n");

            double num_d; char str2[255];
            scanf("%lf", &num_d);

            ftos(num_d, str2);
            printf("%s", str2);
            break;
        case 4:
            printf("Input string\n");

            char str_f[255];
            scanf("%s", str_f);
            stof(str_f);

            printf("%lf", stof(str_f));
    }
}
