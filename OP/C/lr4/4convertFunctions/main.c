#include <stdio.h>
#include <windows.h>

/* возврат длины строки str */
int slen(char *str) {
    int i = 0;
    while (*str++ != '\0') i++;
    return (i);
}

/* переворот строки str */
char * rev_str(char *str) {
    char c;
    int i = 0;
    int j = slen(str) - 1;
    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++; j--;
    }
}

/* запись целого числа num в строку str */
char * itos(int num, char *str) {
    int sign = 1;
    char *p = str;

    if (num < 0) {
        num = -num;
        sign = -1;
    }

    while (num > 0) {
        *str++ = num % 10 + '0';
        num /= 10;
    }

    if (sign == -1)
        *str++ = '-';

    *str = '\0';

    rev_str(p);
    return(p);
}

/* извлечение целого числа из строки str */
int stoi(const char* str) {
    while ((*str <= ' ') && (*str > '\0'))
        ++str;

    int n = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;

    while ((*str >= '0') && (*str <= '9')) {
        n = n * 10 + *str - '0';
        ++str;
    }

    return (n * sign);
}

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

/* извлечение вещественного числа из строки str */
float stof(char* str) {
    while ((*str <= ' ') && (*str > '\0'))
        ++str;

    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;

    int a = 0;

    while ((*str >= '0') && (*str <= '9')) {
        a = a * 10 + (*str - '0');
        ++str;
    }

    int k = 0;

    if (*str == '.') {
        str++;
        while ((*str >= '0') && (*str <= '9')) {
            ++k;
            a = a * 10 + *str - '0';
            ++str;
        }
    }

    int p = 0;

    if ((*str == 'e') || (*str == 'E')) {
        str++;

        while ((*str >= '0') && (*str <= '9')) {
            p = p * 10 + *str - '0';
            ++str;
        }
    }

    int l = p - k;

    if (l < 0)
        return ((a * sign) / powf_(-l));
    else
        return (a * sign * powf_(l));
}

/* конкатенация строк str и add_s */
char * strcat_(char *str, char *add_s) {
    char *p = str;

    while (*str != '\0')
        ++str;

    while (*add_s != '\0') {
        *str = *add_s;
        ++str;
        ++add_s;
    }

    *str = '\0';
    return p;
}

/* получение нормальной формы вещественного числа f */
float normalize(float f, int* r) {
    float sign = 1;

    if (f < 0) {
        sign = -1;
        f = -f;
    }

    int rank = 0;

    while (f > 10) {
        f /= 10;
        ++rank;
    }

    while ((f < 10) && (f != 0)) {
        f *= 10;
        --rank;
    }

    *r = rank;
    return (sign * f);
}

/* запись вещественного числа f в строку str */
char * ftos(float f, char* str) {
    char *p = str;

    if (f < 0) {
        *str++ = '-';
        f = -f;
    }

    int r = 0;
    f = normalize(f, &r);

    int digit = (int) f;
    *str++ = digit + '0';
    f = f * 10;
    *str++ = '.';

    for (int i = 1; i < 6; ++i, f = f * 10) {
        int digit = (int)f % 10;
        *str++ = digit + '0';
    }

    *str++ = 'e';
    *str = '\0';
    char sr[255];
    itos(r, sr);

    strcat_ (str, sr);
    return (p);
}

int main() {
    system("chcp 65001");
    int num_i, v;
    float num_d;
    char s[255];

    printf("Выберите операцию:\n"
           "1.Перевод целого в строку\n"
           "2.Перевод вещественного в строку\n"
           "3.Перевод строки в целое\n"
           "4.Перевод строки в вещественное\n");
    scanf("%d", &v);

        switch (v)
        {
            case 1:
                printf("\nВведите целое число: ");
                scanf(" %i", &num_i);
                printf("Ваша строка с целым числом: \"%s\"", itos(num_i, s));
                break;
            case 2:
                printf("\nВведите вещественное число: ");
                scanf(" %f", &num_d);
                printf("Ваша строка с вещественным числом: \"%s\"", ftos(num_d, s));
                break;
            case 3:
                printf("\nВведите строку с целым числом: ");
                scanf("%s", s);
                printf("Ваше целое число: %i", stoi(s));
                break;
            case 4:
                printf("\nВведите строку с вещественным числом: ");
                scanf("%s", s);
                printf("Ваше вещественное число: %f", stof(s));
                break;
        }
}