#include <stdio.h>

int M = 5, N = 5;

void input_matr(int a[][N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
}

int is_avr_elem(int a[M][N], int i, int j) {

    int curr_elem = a[i][j];

    //check elements before
    for (int k = 0; k < j; ++k) {
        int t = a[i][k];
        if (t >= curr_elem) {
            return 0;
        }
    }

    //check elements after
    for (int k = j + 1; k < N; ++k) {
        int t = a[i][k];
        if (curr_elem >= t) {
            return 0;
        }
    }

    return 1;
}

int get_amnt_avr_elems(int a[M][N]) {

    int res = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (is_avr_elem(a, i, j)) {
                res++;
            }
        }
    }

    return res;
}

int main() {
    int a[M][N];

    input_matr(a);

    int res = get_amnt_avr_elems(a);
    printf("%d", res);
}
