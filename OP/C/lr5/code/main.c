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

/*
 * возвращает сумму элементов столбца под индексом i_col
 * матрицы a порядка size
 */
int get_sum_col(const int a[][MAX], size_t size, size_t i_col) {
    int sum = 0;

    for (size_t i = 0; i < size; i++) {
        sum += a[i][i_col];
    }

    return sum;
}

/*
 * возвращает количество элементов, каждый из которых
 * превышает сумму остальных элементов своего столбца, матрицы a порядка p
 */
size_t get_amount_spec_elems(const int a[][MAX], size_t p) {
    size_t res_amount = 0;
    int curr_col_sum;

    for (size_t j = 0; j < p; j++) {
        curr_col_sum = get_sum_col(a, p, j);

        for (size_t i = 0; i < p; i++) {
            if (a[i][j] > curr_col_sum - a[i][j])
                res_amount++;
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


