#include <stdio.h>

void solve(int chocos[], int n, int i) {
    for (int x = 0; x < n; ++x) {

    }
}

int main() {
    int n;
    scanf("%d", &n);

    int amount_chocolates[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &amount_chocolates[i]);
    }

    int bought_chocolates[n];
    bought_chocolates[0] = amount_chocolates[0];
    for (int i = 1; i < n; i++) {
        bought_chocolates[i] = amount_chocolates[i];

        for (int j = i - 1; j >= 0; j--) {
            if (bought_chocolates[j] >= bought_chocolates[i]) {
                if (bought_chocolates[j] != 0) {
                    bought_chocolates[j] -= (bought_chocolates[j] - bought_chocolates[i]) + 1;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += bought_chocolates[i];
    }

    printf("%d", sum);
}