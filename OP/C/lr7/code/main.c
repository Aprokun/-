/*
 * Дана матрица. Определить k – количество "особых"
 * элементов данной матрицы, считая элемент "особым", если
 * в строке слева от него находятся меньшие элементы, а справа – бóльшие
 */

#include <stdio.h>
#include <stdlib.h>

#define M 3 //число строк
#define N 3 //число столбцов

//возвращает 1, если в массиве а длины n слева от элемента,
//под индексом j_elem находятся только меньшие элменты,
//а справа - только большие
int is_valid(const int *a, size_t n, size_t j_elem) {
    int curr_elem = a[j_elem];

    //проверяем элементы, стоящие слева
    size_t i = 0, j = j_elem;
    while (i < j) {
        if (a[i] >= curr_elem) {
            return 0;
        }

        if (a[j - 1] >= curr_elem) {
            return 0;
        }

        i++; j--;
    }

    //проверяем элементы, стоящие справа
    i = j_elem + 1, j = n;
    while (i < j) {
        if (a[i] <= curr_elem) {
            return 0;
        }

        if (a[j - 1] <= curr_elem) {
            return 0;
        }

        i++; j--;
    }

    return 1;
}

//возвращает количество элементов матрицы а размера m на N,
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

//ввод матрицы а размера m на N
void input_matrix(int (*a)[N], size_t m) {
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < N; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

//выделяет память матрица a размера m на N
void create_matrix(int (**a)[N], size_t m) {
    *a = (int (*)[N])calloc(m, N * sizeof(int));
}

//освобождает память, выделенную под матрицу a
void delete_matrix(int (*a)[N]) {
    free(a);
}

int main() {
    int (*a)[N];
    create_matrix(&a, M);

    printf("Input matrix (%d x %d)\n", M, N);
    input_matrix(a, M);

    int k = get_amount_avr_elems(a, M);
    delete_matrix(a);
    printf("%d", k);
}
