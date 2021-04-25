/*
 * Дана матрица. Определить k – количество "особых"
 * элементов данной матрицы, считая элемент "особым", если
 * в строке слева от него находятся меньшие элементы, а справа – бóльшие
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3 //число столбцов

//возвращает 1, если в массиве а длины n слева от элемента,
//под индексом j_elem находятся только меньшие элменты,
//а справа - только большие
int is_valid(const int *a, size_t n, size_t j_elem) {
    //проверяем элементы, стоящие слева (если таковые есть)
    for (size_t j = 0; j < j_elem; ++j) {
        if (a[j] >= a[j_elem]) {
            return 0;
        }
    }

    //проверяем элементы, стоящие справа (если таковые есть)
    for (size_t j = j_elem + 1; j < n ; ++j) {
        if (a[j] <= a[j_elem]) {
            return 0;
        }
    }

    return 1;
}

//возвращает количество элементов матрицы а размера m на n,
//у которых слева находятся только меньше элементы, а справа -
//только большие
int get_amount_avr_elems(int (*a)[N], size_t m) {
    int k = 0;

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (is_valid(a[i], N, j)) {
                k++;
            }
        }
    }

    return k;
}

//ввод матрицы а размера m на n
void input_matrix(int (*a)[N], size_t m) {
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < N; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

//выделяет память матрица a размера m на n
void create_matrix(int (**a)[N], size_t m) {
    *a = (int (*)[N])calloc(m, N * sizeof(int));
}

//освобождает память, выделенную под матрицу a
void delete_matrix(int (*a)[N]) {
    free(a);
}

int main() {
    printf("Input number of rows\n");
    size_t m;
    scanf("%d", &m);

    int (*a)[N];
    create_matrix(&a, m);

    printf("Input matrix (%d x 3)\n", m);
    input_matrix(a, m);

    int k = get_amount_avr_elems(a, m);
    delete_matrix(a);
    printf("%d", k);
}
