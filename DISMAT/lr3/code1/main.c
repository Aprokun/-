#include <stdio.h>
#include <stdbool.h>

static bool sets[8][3] = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0},
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
};

void print_res(int res[]) {
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%d ", sets[i][j]);
        }
        printf("--- %d\n", res[i]);
    }
}

int is_equals(const int a[], const int b[], size_t size) {
    size_t i = 0;

    while (a[i] == b[i] && i <= size) i++;

    if (i == size)
        return 1;
    else
        return 0;
}

int main() {
    int res1[8], res2[8];

    for (size_t i = 0; i < 8; i++) {
        int a = sets[i][0], b = sets[i][1], c = sets[i][2],
        t = (~a | ~b | ~c);

        res1[i] = (((((a & b) & (~a | ~c)) ^ (a & c)) & (~b | ~c)) ^ (b & c)) | t;
        res2[i] = ((a & b) | (a & c) | (b & c)) & t;
    }

    print_res(res2);
    printf("-------------------------------------------------------\n");

    print_res(res1);
    printf("-------------------------------------------------------\n");

    if (is_equals(res1, res2, 8)) {
        printf("expressions is equal");
    } else
        printf("expressions is not equal");

    int r;
    scanf("%d", &r);
}
