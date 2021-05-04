#include <stdio.h>

/* считывает слово с файла f в буфер buf */
void read_word(FILE *f, char *buf) {
    char c = fgetc(f);
    size_t i = 0;
    while (c != '\n' && c != ' ' &&  c != '\377') {
        buf[i] = c;
        i++;
        c = fgetc(f);
    }

    buf[i] = 0;
}

/*
 * возвращает '1', если длина слова w не больше n,
 * иначе - '0'
 */
int is_valid_word(char *w, int n) {
    size_t c = 0;

    while (*w != '\0' && c < n) {
        c++; w++;
    }

    if (c == n) {
        return 0;
    } else {
        return 1;
    }
}

/* очищает буфер buf длины buf_len */
void clear_buf(char buf[], size_t buf_len) {
    for (size_t i = 0; i < buf_len; ++i) {
        buf[i] = 0;
    }
}

/*
 * закрывает для чтения, а затем удаляет файл inp;
 * переименовывает файл с именем out_file_name на inp_file_name (имя входного файла);
 * закрывает файл out для записи;
 */
void close_files(FILE *inp, char *inp_file_name, FILE *out, char *out_file_name) {
    fclose(inp);
    fclose(out);

    rename(out_file_name, inp_file_name);
    remove(inp_file_name);
}

/*
 * удаляет слова из файла с именем file_name, длина
 * которых превышает (или равна) n
 */
void delete_words_from(char *file_name, int n) {
    FILE *inp = fopen(file_name, "r");
    FILE *out = fopen("output.txt", "w");
    size_t buf_len = 256;


    if (inp != NULL) {
        while (feof(inp) == 0) {
            char buf[buf_len];
            read_word(inp, buf);
            
            if (is_valid_word(buf, n)) {
                fprintf(out, "%s ", buf);
            }
            
            clear_buf(buf, buf_len);
        }
    } else {
        perror("A file with this name wasn't found");
    }

    close_files(inp, file_name, out, "output.txt");
}

int main() {
    printf("Input source file name\n");
    char file_name[50];
    scanf("%s", file_name);

    printf("Input number\n");
    int n;
    scanf("%d", &n);

    delete_words_from(file_name, n);

}
