#include <stdio.h>
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

struct set {
    int *values;
    int n;
};

static struct set a, b, c, u;

int is_elem_in(struct set s, int elem) {
    int n = s.n;

    for (int i = 0; i < n; ++i) {
        if (s.values[i] == elem)
            return 1;
    }

    return 0;
}

void output_set(struct set *s) {
    int *values = s->values,
    n = s->n;

    printf("{");

    for (int i = 0; i <= n - 2; i++) {
        printf("%d, ", values[i]);
    }

    printf("%d}\n", values[n - 1]);
}

struct set intersection(struct set *s1, struct set *s2) {
    int t[8], j = 0, n = s1->n;
    struct set temp;

    for (int i = 0; i < n; i++) {
        int elem = s1->values[i];

        if (is_elem_in(*s2, elem)) {
            t[j] = elem;
            j++;
        }
    }

    temp.values = t; temp.n = j;
    return temp;
}

struct set subtraction(const struct set *s1, const struct set *s2) {
    int t[8], j = 0, n = s1->n;
    struct set temp;

    for (int i = 0; i < n; i++) {
        int elem = s1->values[i];

        if (!(is_elem_in(*s2, elem))) {
            t[j] = elem;
            j++;
        }
    }

    temp.values = t; temp.n = j;
    return temp;
}

struct set complement(struct set *s1) {
    int t[8], j = 0, n = s1->n;
    struct set temp;

    temp = subtraction(&u, s1);

    return temp;
}

int main() {
    int a_vals[] = {1, 3, 5, 7};
    int b_vals[] = {2, 3, 6, 7};
    int c_vals[] = {4, 5, 6, 7};
    int u_vals[] = {1, 2, 3, 4, 5, 6, 7};

    a.values = a_vals;
    b.values = b_vals;
    c.values = c_vals;
    u.values = u_vals;
    a.n = b.n = c.n = 4; u.n = 7;

}
