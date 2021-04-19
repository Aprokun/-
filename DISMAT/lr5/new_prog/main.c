#include <stdio.h>

void output_arr(int a[], int n) {
    printf("{");

    for (int i = 0; i < n; ++i) {
        printf("%d, ", a[i]);
    }

    printf("\b\b}\n");
}

void get_accommodation_with_repeats(int a[], int n, int k, int i) {
    static int o[100];

    for (int j = 0; j < n; ++j) {
        o[i] = a[j];

        if (i == k - 1) {
            output_arr(o, k);
        } else {
            get_accommodation_with_repeats(a, n, k, i + 1);
        }

    }
}

void get_combinations_with_repeats(int a[], int n, int k, int i, int b) {
    static int c[100];

    for (int j = b; j < n; ++j) {
        c[i] = a[j];

        if (i == k - 1) {
            output_arr(c, k);
        } else {
            get_combinations_with_repeats(a, n, k, i + 1, j);
        }
    }
}

int main() {
    int a[] = {1, 2, 3};
    //get_accommodation_with_repeats(a, 3, 2, 0);
    //printf("--------------------------\n");
    get_combinations_with_repeats(a, 3, 3, 0, 0);
}
