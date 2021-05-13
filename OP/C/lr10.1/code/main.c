#include <stdio.h>

/* возвращает длину строки str */
size_t slen_(char *str) {
    size_t i = 0;

    while (*str != '\0') {
        i++; str++;
    }

    return i;
}

/*
 * удаляет слова из файла с именем file_name, длина
 * которых превышает (или равна) n
 */
void delete_words_from(char *file_name, size_t n) {
    FILE *inp_r = fopen(file_name, "r"),
         *inp_w = fopen(file_name, "r+");
    size_t buf_len = 256;
    long r;

    fseek(inp_r, 0, SEEK_END);
    int file_size = ftell(inp_r);
    fseek(inp_r, 0, SEEK_SET);

    if (inp_r != NULL) {
        while (feof(inp_r) == 0) {

            char buf[buf_len];
            fscanf(inp_r, "%s", buf);

            long word_len = slen_(buf);

            if (word_len < n) {
                fprintf(inp_w, "%s ", buf);
                r = ftell(inp_w);
            }
        }


        while (r < file_size) {
            fputc(' ', inp_w);
            r++;
        }
    } else {
        perror("A file with this name wasn't found");
    }

    fclose(inp_r);
    fclose(inp_w);
}

int main() {
    printf("Input source file name\n");
    char file_name[50];
    scanf("%s", file_name);

    printf("Input number\n");
    size_t n;
    scanf("%u", &n);

    delete_words_from(file_name, n);

}
