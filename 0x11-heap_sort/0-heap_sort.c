#include "sort.h"

/**
 * heapify - heapifies
 * @array: pointer to  sorted array 
 * @n: size
 * @index: index to search through array
 * @size: size of heap sort
 */
void heapify(int *array, size_t n, int index, size_t size)
{
	int large = index;
	size_t left = (2 * index + 1);
	size_t right = (2 * index + 2);

	if (left < n && array[left] > array[large])
		large = left;

	if (right < n && array[right] > array[large])
		large = right;

	if (large != index)
	{
		swapped(&array[index], &array[large]);
		if (array[index] != array[large])
			print_array(array, size);
		heapify(array, n, large, size);
	}
}

/**
 * swap - swaps positions of values
 * @x: first value
 * @y: second value
 */
void swapped(int *beta, int *zeta)
{
	int temp = *beta;

	*beta = *zeta;
	*zeta = temp;
}

/**
 * heap_sort - sorts an array using heap sort algo
 * @array: pointer to array of integers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (size <= 1)
		return;

	idx = size / 2 - 1;
	for ( ; idx >= 0; idx--)
		heapify(array, size, idx, size);

	idx = size - 1;
	for ( ; idx > 0; idx--)
	{
		swapped(&array[0], &array[idx]);
		print_array(array, size);
		heapify(array, idx, 0, size);
	}
}
