#include <stdio.h>

int put_word(char *s, int n) {
    static int i = 0;
    char word[n];
    scanf("%s", word);

    while (word[i] != '\0') {
        *s = word[i];
        i++; s++;
    }

    s[i] = ' ';
    i++;

    if (i - 1 == n) {
        return i - 1;
    } else {
        return EOF;
    }
}

int main() {
    char str[255];

    put_word(str, 3);

    printf("%s", str);

    put_word(str, 2);

    printf("%s", str);

}
