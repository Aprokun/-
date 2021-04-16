#include <stdio.h>

#define N 100

int MIN_ROWS = N, num, ROWS_MASK[N], a[N][N];

/*вывод матрицы с маской row_mask*/
void print_matr_with_row_mask(const int row_mask[], int m, int n) {
    for (int i = 0; i < m; ++i) {
        if (row_mask[i]) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[i][j]);
            }

            printf("\n");
        }
    }
}

/*копирование массива this размера n в массив other*/
void copy_arr(const int this[], int n, int other[]) {
    for (int i = 0; i < n; ++i) {
        other[i] = this[i];
    }
}

/*возвращает сумму столбца col по выбранной маске строк mask длины m*/
int get_col_sum_by_mask(const int *mask, int m, int col) {
    int sum = 0;

    for (int i = 0; i < m; ++i) {
        if (mask[i] == 1) {
            int t = a[i][col];
            sum += t;
        }
    }

    return sum;
}

/*возвращает "истину", если каждое значение массива cols_sum размера n
 *превышает num, иначе - "ложь"*/
static int check_cols_sum(int n, const int *cols_sum) {
    for (int j = 0; j < n; ++j) {
        if (cols_sum[j] <= num) {
            return 0;
        }
    }

    return 1;
}

/*помещает сумму столбцов в массив cols_sum*/
static void set_cols_sum(int m, int n, const int *d, int *cols_sum) {
    for (int j = 0; j < n; ++j) {
        int sum = get_col_sum_by_mask(d, m, j);
        cols_sum[j] = sum;
    }
}

/*рекурсивная функция: генерирует подмножества множества строк матрицы a
 *размера m строк и n столбцов*/
static void get_subsets_inner(int m, int n, int i) {
    static int d[100];
    static int cols_sum[N];

    for (int x = 0; x < 2; ++x) {
        d[i] = x;

        if (i == n - 1) {
            set_cols_sum(m, n, d, cols_sum);

            int c = 0;
            for (int j = 0; j < n; ++j) {
                if (d[j] == 1) c++;
            }

            if (check_cols_sum(n, cols_sum) && c < MIN_ROWS) {
                MIN_ROWS = c;
                copy_arr(d, n, ROWS_MASK);
            }
        } else {
            get_subsets_inner(m, n, i + 1);
        }
    }
}

/*функция-оболочка для get_subsets_inner*/
void get_rows_subsets(int m, int n) {
    get_subsets_inner(m, n, 0);
}

int main() {
    scanf("%d", &num);

    int n, m;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    get_rows_subsets(m, n);
    printf("%d\n", MIN_ROWS);
    print_matr_with_row_mask(ROWS_MASK, m, n);

}
