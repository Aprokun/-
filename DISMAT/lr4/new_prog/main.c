#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

struct set {
    int *values;
    int min;
    int max;
};

int is_elem_in(struct set *s, int elem) {
    int *a = s->values;

    if (a[elem] == 1) {
        return 1;
    }

    return 0;
}

struct set create_set(int min, int max) {
    int n = max - min,
            *a = (int *) calloc(sizeof(int), n);
    struct set temp;

    temp.max = max;
    temp.min = min;

    temp.values = a;

    return temp;
}

void delete_set(struct set *s) {
    free(s->values);
    free(s);
}

struct set complemept_set(struct set *s) {
    int *a = s->values;
    struct set temp = create_set(s->min, s->max);
    int *b = temp.values;

    for (int i = s->min; i <= s->max; i++) {
        b[i] = (a[i] == 0 ? 1 : 0);
    }

    return temp;
}

void output_set(struct set *s) {
    int *values = s->values;

    printf("{ ");

    for (int i = s->min; i <= s->max - 1; i++) {
        if (values[i] == 1)
            printf("%d ", i);
    }
    if (values[s->max] == 1)
        printf("%d}\n", s->max);
    else
        printf("}");
}

void add(struct set *s, int value) {
    int *values = s->values;
    values[value] = 1;
}

void delete(struct set *s, int value) {
    int *values = s->values;

    if (values[value] == 1) {
        values[value] = 0;
    }
}

struct set union_set(struct set *s1, struct set *s2) {
    int new_min = MIN(s1->min, s2->min),
            new_max = MAX(s1->max, s2->max),
            *a = s1->values,
            *b = s2->values;
    struct set temp = create_set(new_min, new_max);
    int *t = temp.values;

    for (int i = s1->min; i < s1->max; i++) {
        if (t[i] == 0) t[i] = a[i];
    }

    for (int i = s2->min; i < s2->max; i++) {
        if (t[i] == 0) t[i] = b[i];
    }

    temp.max = new_max;
    temp.min = new_min;
    return temp;
}

struct set intersection_set(struct set *s1, struct set *s2) {
    int new_min = MAX(s1->min, s2->min),
            new_max = MIN(s1->max, s2->max),
            *a = s1->values, *b = s2->values;
    struct set temp = create_set(new_min, new_max);
    int *t = temp.values;

    for (int i = new_min; i < new_max; i++) {
        if ((a[i] == 1) && (b[i] == 1))
            t[i] = 1;
    }

    temp.max = new_max;
    temp.min = new_min;
    return temp;
}

int is_subset(struct set *s1, struct set *s2) {
    int *a = s2->values;

    for (int i = s2->min; i < s2->max; i++) {
        if (a[i] == 1) {
            if ((!is_elem_in(s1, i))) {
                return 0;
            }
        }
    }

    return 1;
}

struct set subtraction_set(struct set *s1, struct set *s2) {
    int *a = s1->values,
            *b = s2->values;
    struct set temp = create_set(s1->min, s1->max);
    int *t = temp.values;

    for (int i = s1->min; i < s2->max; i++) {
        if (s2->min <= i && i <= s2->max) {
            if (a[i] == 1 && b[i] == 1) {
                t[i] = 0;
            } else t[i] = a[i];
        } else t[i] = a[i];
    }

    temp.min = s1->min;
    temp.max = s1->max;
    return temp;
}

struct set sym_subtraction(struct set *s1, struct set *s2) {
    struct set t1, t2, temp;

    t1 = subtraction_set(s1, s2);
    t2 = subtraction_set(s2, s1);
    temp = union_set(&t1, &t2);

    delete_set(&t1);
    delete_set(&t2);

    return temp;
}

struct set get_set_from_array(int min, int max, const int *a, int n) {
    struct set temp = create_set(min, max);
    int *t = temp.values;

    for (int i = 0; i < n; ++i) {
        t[a[i]] = 1;
    }

    temp.max = max;
    temp.min = min;
    return temp;
}

void print_set_of_solves(struct set *s, struct set *emp) {
    int *a = s->values, r;

    for (int i = 0; i < 10; ++i) {
        if (a[i] == 0) {
            continue;
        } else
            r = i;

        if (is_subset(s, emp) && is_subset(emp, s)) {
            output_set(emp);
        } else {
            add(emp, r);
            delete(s, r);
            print_set_of_solves(s, emp);
        }


    }
}

int solve(struct set *a, struct set *b, struct set *c, struct set *x) {
    struct set t1, t2, t3, t4, com_x,
               t5, t6, t7;

    com_x = complemept_set(x);

    t1 = subtraction_set(c, x);

    t2 = subtraction_set(a, &com_x);
    t3 = complemept_set(&t2);

    t4 = sym_subtraction(&t1, &t3);


    t5 = subtraction_set(a, x);

    t6 = intersection_set(b, x);

    t7 = sym_subtraction(&t5, &t6);

    if (is_subset(&t7, &t4) && is_subset(&t4, &t7)) {
        return 1;
    }

    return 0;
}

int main() {
    struct set u = create_set(1, 10),
            e = create_set(1, 10),
            a = create_set(1, 10),
            b = create_set(1, 10),
            c = create_set(1, 10);

    struct set t1, t2, t3, t4, com_x, t5, t6, t7;

    //init A
    add(&a, 3);
    add(&a, 7);
    add(&a, 9);
    add(&a, 10);

    //init B
    add(&b, 1);
    add(&b, 3);
    add(&b, 8);
    add(&b, 9);
    add(&b, 10);

    //init C
    add(&c, 2);
    add(&c, 4);
    add(&c, 5);
    add(&c, 6);
    add(&c, 7);


    for (int i = 0; i < 1024; ++i) {
        struct set x = create_set(1, 10);

        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                add(&x, j);
            }
        }
//ex1
        com_x = complemept_set(&x);

        t1 = subtraction_set(&c, &x);

        t2 = subtraction_set(&a, &com_x);
        t3 = complemept_set(&t2);

        t4 = sym_subtraction(&t1, &t3);

        delete_set(&t1);
        delete_set(&t2);
        delete_set(&t3);
        delete_set(&t4);
        delete_set(&com_x);

//ex2
        t5 = subtraction_set(&a, &x);

        t6 = intersection_set(&b, &x);

        t7 = sym_subtraction(&t5, &t6);

        if (is_subset(&t7, &t4) && is_subset(&t4, &t7)) {
            output_set(&x);
        }

        delete_set(&x);
        delete_set(&t5);
        delete_set(&t6);
        delete_set(&t7);
    }
}
