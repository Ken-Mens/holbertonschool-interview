#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <stdlib.h>
#include <stdio.h>

void swapped(int *beta, int *zeta);
void heapify(int *array, size_t n, int index, size_t size);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /*HEAP_SORT_H*/
