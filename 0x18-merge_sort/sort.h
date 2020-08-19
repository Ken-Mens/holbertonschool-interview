#ifndef _SORT_HEADER_
#define _SORT_HEADER_
#include <stdio.h>
#include<stdlib.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merger(int *array, int size, int m, int *tempo);
void merge_split(int *array, size_t size, int *tempo);

#endif /*_SORT_HEADER_*/
