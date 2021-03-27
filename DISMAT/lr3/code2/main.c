#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b) (a < b ? a : b)

struct set {
    int *values;
    int n;
};

int is_elem_in(struct set *s1, int elem) {
    for (int i = 0; i < s1->n; ++i) {
        if (s1->values[i] == elem)
            return 1;
    }

    return 0;
}

struct set intersection(struct set *s1, struct set *s2) {
    int n = MIN(s1->n, s2->n), j = 0,
        *t = (int *)calloc(sizeof(int), n);
    struct set temp;

    for (int i = 0; i < n; ++i) {
        int elem = s1->values[i];

        if (is_elem_in(s2, elem)) {
            t[j] = elem;
            j++;
        }
    }

    temp.n = j; temp.values = t;
    return temp;
}

struct set union_(struct set *s1, struct set *s2) {
    int n = s1->n + s2->n, j = s1->n,
        *t = (int *)calloc(sizeof(int), n);
    struct set temp;

    for (int i = 0; i < s1->n; i++)
        t[i] = s1->values[i];

    for (int i = 0; i < s2->n; i++) {
        int elem = s2->values[i];

        if (!(is_elem_in(s1, elem))) {
            t[j] = elem;
            j++;
        }
    }

    temp.n = j; temp.values = t;
    return temp;
}

struct set subtraction(struct set *s1, struct set *s2) {
    int n = s1->n, j = 0,
        *t = (int *)calloc(sizeof(int), n);
    struct set temp;

    for (int i = 0; i < n; i++) {
        int elem = s1->values[i];

        if (!(is_elem_in(s2, elem))) {
            t[j] = elem;
            j++;
        }
    }

    temp.n = j; temp.values = t;
    return temp;
}

struct set sym_subtraction(struct set *s1, struct set *s2) {
    struct set temp, t1, t2;

    t1 = subtraction(s1, s2);
    t2 = subtraction(s2, s1);
    temp = union_(&t1, &t2);


    return temp;
}

void output(struct set *s) {
    printf("{");

    for (int i = 0; i < s->n-1; i++) {
        printf("%d, ", s->values[i]);
    }

    printf("%d}\n", s->values[s->n-1]);
}

int is_equals(struct set *s1, struct set *s2) {
    if (s1->n != s2->n)
        return 0;

    for (int i = 0; i < s1->n; i++) {
        int elem = s1->values[i];

        if (!(is_elem_in(s2, elem)))
            return 0;
    }

    return 1;
}

int main() {
    struct set a;
    int av[] = {1, 3, 5, 7};
    a.values = av; a.n = 4;

    struct set b;
    int bv[] = {2, 3, 6, 7};
    b.values = bv; b.n = 4;

    struct set c;
    int cv[] = {4, 5, 6, 7};
    c.values = cv; c.n = 4;


    struct set t1, t2, t3, t4, t5, t6, t7, t8,
               t9, t10, t11, t12, res1, res2;

    //Expression №1
    t1 = intersection(&a, &b);
    t2 = intersection(&b, &c);
    t3 = intersection(&a, &c);

    t4 = subtraction(&t1, &t3);
    t5 = sym_subtraction(&t4, &t3);
    t6 = subtraction(&t5, &t2);
    t7 = sym_subtraction(&t6, &t2);

    t8 = intersection(&t1, &c);

    res1 = subtraction(&t7, &t8);

    output(&res1);

    //Expression №2
    t1 = subtraction(&a, &b);
    t2 = subtraction(&b, &c);
    t3 = subtraction(&a, &c);

    t4 = subtraction(&a, &t1);
    t5 = subtraction(&a, &t3);
    t6 = subtraction(&b, &t2);

    t7 = subtraction(&t4, &t5);
    t8 = sym_subtraction(&t7, &t5);
    t9 = subtraction(&t8, &t6);
    t10 = sym_subtraction(&t9, &t6);

    t11 = subtraction(&c, &t4);
    t12 = subtraction(&c, &t11);

    res2 = subtraction(&t10, &t12);
    output(&res2);

    if (is_equals(&res1, &res2))
        printf("Expressions are equals");
    else
        printf("Expressions are not equals");

    int r;
    scanf("%d", &r);
}
