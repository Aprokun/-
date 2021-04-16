#include <stdio.h>
#include <time.h>

void get_accommodations(int a[4], int n, int k);

void output_arr(int a[], int n) {
    printf("{");

    for (int i = 0; i < n; ++i) {
        printf("%d, ", a[i]);
    }

    printf("\b\b}\n");
}

void get_combinations_inner(int a[], int n, int i, int k, int b) {
    static int c[100];

    for (int j = b; j < n; ++j) {
        c[i] = a[j];

        if (i == k - 1) {
            output_arr(c, k);
        } else {
            get_combinations_inner(a, n, i + 1, k, j + 1);
        }
    }
}

void get_combinations(int a[], int n, int k) {
    get_combinations_inner(a, n, 0, k, 0);
}

void output_array_with_mask(const int a[], int n, const int mask[]) {
    int is_empty = 1;

    printf("{");
    for (int i = 0; i < n; i++) {
        if (mask[i]) {
            printf("%d, ", a[i]);
            is_empty = 0;
        }
    }

    if (is_empty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

static void get_subsets_inner(int *a, int n, int i) {
    static int d[100];

    for (int x = 0; x < 2; ++x) {
        d[i] = x;

        if (i == n - 1) {
            output_array_with_mask(a, n, d);
        } else {
            get_subsets_inner(a, n, i + 1);
        }
    }
}

void get_subsets(int a[], int n) {
    get_subsets_inner(a, n, 0);
}

static void get_permutations_inner(int a[], int n, int i) {
    static int m[100];
    static int t[100];

    for (int j = 0; j < n; ++j) {
        if (t[j] == 0) {
            m[i] = a[j];
            t[j] = 1;

            if (i == n - 1) {
                output_arr(m, n);
            } else {
                get_permutations_inner(a, n, i + 1);
            }

            t[j] = 0;
        }
    }
}

void get_permutations(int a[], int n) {
    get_permutations_inner(a, n, 0);
}

void get_accommodation_inner(int a[], int n, int k, int i) {
    static int o[100];
    static int t[100];

    for (int j = 0; j < n; ++j) {
        if (t[j] == 0) {
            o[i] = a[j];
            t[j] = 1;

            if (i == k - 1) {
                output_arr(o, k);
            } else {
                get_accommodation_inner(a, n, k, i + 1);
            }

            t[j] = 0;
        }
    }
}

void get_accommodations(int a[4], int n, int k) {
    get_accommodation_inner(a, n, k, 0);
}

int main() {
    int a[] = {3, 5, 6, 9, 2};
    int b[] = {1, 2, 3, 6, 7, 8, 9, 4};
    time_t beg, end;

    beg = time(NULL);
    //combinations
    get_combinations(a, 5, 1);
    //end combinations
    end = time(NULL);

    printf("------------------------\n");

    double diff = difftime(end, beg);
    printf("затрачено: %f", diff);
    printf("------------------------\n");


    //permutations
    get_permutations(b, 7);
    //end permutations

    printf("------------------------\n");

    //accommodations
    get_accommodations(a, 4, 3);
    //end accommodations

}
