#include <stdio.h>
#include <stdlib.h>

/* возврат длины строки str */
int slen(char *str) {
    size_t i = 0;
    while (*str++ != '\0') i++;
    return i;
}

/* обращение строки s */
char * rev_str(char *s) {
    int i = 0,
        j = slen(s) - 1;
    char *p = (char *)calloc(sizeof(char), j);

    while (j >= 0) {
        p[i] = s[j];
        i++; j--;
    }

    return p;
}

/* возвращает "истину", если строка s1 равна строке s2, иначе - "ложь" */
int is_str_equals(char *s1, char *s2) {
    int res = 1;

    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2)
            res = 0;
        s1++; s2++;
    }

    return res;
}

/* возвращает кол-во палиндромов, начинающихся с буквы 'a', строки s */
size_t get_amount_palindroms_wth_a(char *s) {
    size_t res = 0;

    while (*s != '\0') {
        while (*s == ' ' || *s == ',') s++;

        char w[255]; size_t i = 0;

        while (*s != ',' && *s != '\0') {
            w[i] = *s;
            s++; i++;
        }
        w[i] = '\0';

        char *revw = rev_str(w);

        if (*w == 'a' && is_str_equals(w, revw)) res++;
    }

    return res;
}

int main() {
    char s[255];
    gets(s);

    size_t res = get_amount_palindroms_wth_a(s);

    printf("Result: %d palindroms with \"a\"", res);
}
