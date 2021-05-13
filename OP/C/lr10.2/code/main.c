#include <stdio.h>

/* возвращает созданный бинарный файл с именем file_name
и заполненный числами, введёнными с клавиатуры */
FILE * create_bin_file(char *file_name) {
    FILE *file = fopen(file_name, "wb+");

    printf("Input number of sequence\n");
    size_t t;
    scanf("%u", &t);

    double a[t];
    for (size_t i = 0; i < t; ++i) {
        scanf("%lf", &a[i]);
    }
    fwrite(&a, sizeof(double), t, file);
    fseek(file, 0, SEEK_SET);

    return file;
}


/* Замена чисел в файле c именем file_name со второго по предпоследнее
средним арифметическим данного, предыдущего и последующего */
void replace_with_avr(char *file_name) {
    FILE *f_w = create_bin_file(file_name);
    FILE *f_r = fopen(file_name, "r");

    double prev = 0, curr = 0, next = 0;

    //first init prev, curr, next
    fread(&prev, sizeof(prev), 1, f_r);
    fread(&curr, sizeof(curr), 1, f_r);
    fread(&next, sizeof(next), 1, f_r);

    fwrite(&prev, sizeof(prev), 1, f_w);
    double avr;
    while (feof(f_r) == 0) {
        avr = (prev + curr + next) / 3;
        fwrite(&avr, sizeof(avr), 1, f_w);

        prev = curr;
        curr = next;
        fread(&next, sizeof(next), 1, f_r);
    }
    avr = (prev + curr + next) / 3;
    fwrite(&avr, sizeof(avr), 1, f_w);
    fwrite(&next, sizeof(next), 1, f_w);

    fclose(f_w);
    fclose(f_r);
}

int main() {
    printf("Input file name\n");
    char file_name[50];
    scanf("%s", file_name);

    replace_with_avr(file_name);
}

//f.txt
//6
//123.123 321.321 23.23 414.4343 1222.2222 3.3