/*
 * Дана матрица. Определить k – количество "особых"
 * элементов данной матрицы, считая элемент "особым", если
 * в строке слева от него находятся меньшие элементы, а справа – бóльшие
 */

#include <stdio.h>
#include <stdlib.h>

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
int get_amount_avr_elems(int **a, size_t m, size_t n) {
    int k = 0;

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (is_valid(a[i], n, j)) {
                k++;
            }
        }
    }

    return k;
}

//ввод матрицы а размера m на n
void input_matrix(int **a, size_t m, size_t n) {
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

//выделяет память матрица a размера m на n
void create_matrix(int ***a, size_t m, size_t n) {
    *a = (int **)calloc(m, sizeof(int *));
    for (size_t i = 0; i < m; ++i) {
        (*a)[i] = (int *) calloc(n, sizeof(int));
    }
}

//освобождает память, выделенную под матрицу a
void delete_matrix(int **a, size_t m) {
    for (size_t i = 0; i < m; ++i) {
        free(a[i]);
    }

    free(a);
}

int main() {
    printf("Input number of rows\n");
    int m;
    scanf("%d", &m);

    printf("Input number of columns\n");
    int n;
    scanf("%d", &n);

    int **a;
    create_matrix(&a, m, n);

    printf("Input matrix (%d x %d)\n", m, n);
    input_matrix(a, m, n);

    int k = get_amount_avr_elems(a, m, n);
    delete_matrix(a, m);
    printf("%d", k);
}
