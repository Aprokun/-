#ifndef SET_LIBRARY_H
#define SET_LIBRARY_H

struct set create_set(int min, int max);

void delete_set(struct set *s);

void output_set(struct set *s);

void add(struct set *s, int value);

struct set complemept_set(struct set *s);

struct set union_set(struct set *s1, struct set *s2);

struct set intersection_set(struct set *s1, struct set *s2);

int is_subset(struct set *s1, struct set *s2);

struct set subtraction_set(struct set *s1, struct set *s2);

struct set sym_subtraction(struct set *s1, struct set *s2);

struct set get_set_from_array(int min, int max, const int *a, int n);

#endif //SET_LIBRARY_H
