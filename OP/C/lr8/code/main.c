#include <stdio.h>
#include <malloc.h>

/* структура, описывающая массив слов text */
struct text {
    char w[255];
    size_t text_len;
};

/* копирует строку from в строку to */
void strcopy(const char from[], char to[]) {
    size_t i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }

    to[i] = 0;
}

/* возвращает длину считанного c клавиатуры слова строки s, если она меньше, чем n;
 * возвращает '-2', если строка s закончилась;
 * возвращает 'EOF', если считанное слово оказалось больше, чем n */
int put_word(char *s, int n) {
    char word[n];

    size_t i = 0;
    word[i] = getchar();
    while (word[i] != '\n' && word[i] != ' ' && word[i] != '\0') {
        s[i] = word[i];
        i++;
        word[i] = getchar();
    }

    if (word[i] == '\n') {
        return -2;
    }

    if (i < n) {
        word[i] = 0;
        return i;
    } else return EOF;
}

/*возвращает '1', если строка s1 совпадает со строкой s2, иначе - '0'*/
int is_str_equals(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return 0;
        }

        s1++; s2++;
    }

    return 1;
}

/* возвращает указатель на массив слов длины k,
 * buf_len - размер буфера для слова */
struct text *create_free_arr(int k, int buf_len) {
    struct text *text = (struct text *) calloc(sizeof(struct text), k);
    size_t i = 0;
    char buf[buf_len + 1];

    printf("Input text\n");
    int word_status = 0;

    while (word_status != -2) {
        word_status = put_word(buf, buf_len);

        if (k >= 0)
            k--;
        else
            realloc(text, ++k);

        strcopy(buf, text[i].w);
        for (size_t j = 0; j < buf_len; ++j) {
            buf[j] = 0;
        }
        i++;
    }

    if (i == k) {
        text->text_len = k;
    } else text->text_len = i;


    return text;
}

/* возвращает '1', если масси слов reversed - обратная перестановка
 * массива слова source, иначе - '0' */
int is_reverse_order(struct text source[], struct text reversed[]) {
    if (source->text_len != reversed->text_len) {
        return 0;
    }

    size_t len = source->text_len;
    for (size_t i = 0; i < len; ++i) {
        if (!(is_str_equals(source[i].w, reversed[(len - 1) - i].w))) {
            return 0;
        }
    }

    return 1;
}

int main() {
    struct text *text1 = create_free_arr(5, 255);
    struct text *text2 = create_free_arr(5, 255);

    if (is_reverse_order(text1, text2)) {
        printf("This is reversed text");
    } else printf("This is not reversed text");
}