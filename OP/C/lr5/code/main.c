/*
 * Дана квадратная матрица. Определить k – количество "особых"
 * элементов матрицы, считая элемент "особым", если он больше
 * суммы остальных элементов своего столбца
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* ввод матрицы a порядка p */
void input_matrix(int a[][MAX], size_t p) {
    for (size_t i = 0; i < p; i++) {
        for (size_t j = 0; j < p; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

/* возвращает сумму элементов массива a размера size */
int get_sum_line_elems(const int a[], size_t size) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += a[i];
    }

    return sum;
}
/*
 * возвращает количество элементов, каждый из которых
 * превышает сумму остальных элементов строки, матрицы a порядка p
 */
size_t get_amount_spec_elems(const int a[][MAX], size_t p) {
    size_t res_amount = 0;
    int curr_line_sum;

    for (size_t i = 0; i < p; i++) {
        curr_line_sum = get_sum_line_elems(a[i],p);
        for (size_t j = 0; j < p; j++) {
            if (a[i][j] > curr_line_sum - a[i][j]) {
                res_amount++;
            }
        }
    }

    return res_amount;
}

int main() {
    size_t p;
    printf("Input matrix order\n");
    scanf("%u", &p);

    printf("Input matrix elements\n");
    int a[MAX][MAX];
    input_matrix(a, p);
    size_t res = get_amount_spec_elems(a, p);

    printf("%u", res);
}


