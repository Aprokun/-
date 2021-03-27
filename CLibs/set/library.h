#ifndef SET_LIBRARY_H
#define SET_LIBRARY_H

struct set create_set();

struct set delete_set();

void output_set();

void add();

struct set complemept_set();

struct set union_set();

struct set intersection_set();

int is_subset();

struct set subtraction_set();

struct set sym_subtraction();

struct set get_set_from_array();

#endif //SET_LIBRARY_H
