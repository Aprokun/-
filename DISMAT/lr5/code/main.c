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

int * get_array_from_set(struct set *s) {
    int *a = s->values,
        j = 0;

    for (int i = s->min; i <= s->max; ++i) {
        if (a[i] == 1) {
            j++;
        }
    }

    int *res = (int *) calloc(sizeof(int), j);
    j = 0;

    for (int i = s->min; i < s->max; ++i) {
        if (a[i] == 1) {
            res[j] = i;
            j++;
        }
    }

    return res;
}

//
//subset methods
//
void output_array_with_mask(struct set *s, const int *mask, int n) {
    int is_empty = 1,
    *M = s->values;

    printf("{");
    for (int i = 0; i < n; i++) {
        if (mask[i] != 0) {
            printf("%d, ", M[i]);
            is_empty = 0;
        }
    }

    if (is_empty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

static void get_subsets_inner(int i, int n, int *M) {
    static int D[100];
    for (int x = 0; x <= 1; x++) {
        D[i] = x;
        if (i == n - 1)
            output_array_with_mask(M, D, n);
        else
            get_subsets_inner(i + 1, n, M);
    }
}

void get_subsets(int* M, int n) {
    get_subsets_inner(0, n, M);
}

int main() {
    struct set A = create_set(3, 5),
               B = create_set(2, 7),
               C = create_set(1, 10);

    //fill sets
    for (int i = 3; i < 6; ++i) {
        add(&A, i);
    }

    for (int i = 2; i < 8; ++i) {
        add(&B, i);
    }

    for (int i = 1; i < 11; ++i) {
        add(&C, i);
    }
    //end fill sets

    get_subsets(A.values, 5)

}
