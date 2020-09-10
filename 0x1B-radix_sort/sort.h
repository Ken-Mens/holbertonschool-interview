#ifndef SORT_HEAD
#define SORT_HEAD
#include <stdlib.h>

void print_array(const int *array, size_t size);
int max_int(int *array, int bulk);
void count_sort(int *array, size_t size, int n);
void radix_sort(int *array, size_t size);

#endif /*SORT_HEAD*/
