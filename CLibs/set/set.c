#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

struct set {
    int *values;
    int min;
    int max;
};

struct set create_set(int min, int max) {
    int n = max - min,
            *a = (int *)calloc(sizeof(int), n);
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

void output_set(struct set *s) {
    int *values = s->values,
            n = s->max - s->min;

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

struct set complement_set(struct set *s) {
    int *a = s->values;
    struct set temp = create_set(s->min, s->max);
    int *b = temp.values;

    for (int i = s->min; i <= s->max; i++) {
        b[i] = (a[i] == 0 ? 1 : 0);
    }

    return temp;
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

    temp.max = new_max; temp.min = new_min;
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

    temp.max = new_max; temp.min = new_min;
    return temp;
}

int is_subset(struct set *s1, struct set *s2) {
    int *a = s1->values,
            *b = s2->values;

    for (int i = s2->min; i < s2->max; i++) {
        if (b[i] != a[i])
            return 0;
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

    temp.min = s1->min; temp.max = s1->max;
    return temp;
}

struct set sym_subtraction(struct set *s1, struct set *s2) {
    struct set t1, t2, temp;

    t1 = subtraction_set(s1, s2);
    t2 = subtraction_set(s2, s1);
    temp = union_set(&t1, &t2);

    delete_set(&t1); delete_set(&t2);

    return temp;
}

struct set get_set_from_array(int min, int max, const int *a, int n) {
    struct set temp = create_set(min, max);
    int *t = temp.values;

    for (int i = 0; i < n; ++i) {
        t[a[i]] = 1;
    }

    temp.max = max; temp.min = min;
    return temp;
}