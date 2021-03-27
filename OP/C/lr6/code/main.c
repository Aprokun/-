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

/* возвращает "истину", если слово w - палиндром, иначе - "ложь" */
int is_palindrom(char *w) {
    char *revw = rev_str(w);
    int res = 1;

    while (*w != '\0' && *revw != '\0') {
        if (*w != *revw)
            res = 0;
        w++; revw++;
    }

    free(revw);
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

        if (*w == 'a' && is_palindrom(w)) res++;
    }

    return res;
}

int main() {
    char s[255];
    gets(s);

    size_t res = get_amount_palindroms_wth_a(s);

    printf("Result: %d palindroms with \"a\"", res);
}
