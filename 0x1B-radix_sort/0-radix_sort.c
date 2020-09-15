#include "sort.h"

/**
 * max_int - maximum integer in an unsorted int array
 * @array: array to be iterated
 * @bulk: size of the array
 * Return: max int in the array
 */

int max_int(int *array, int bulk)
{
	int mx = array[0];
	int foo = 1;

	for (; foo < bulk; foo++)
	{
		if (array[foo] > mx)
			mx = array[foo];
	}
	return (mx);
}

/**
 * count_sort - Counting sort for Radix sort algorhitm
 * @array: array
 * @size: size of the array
 * @n: integer to sort through
 * Return: void
 */

void count_sort(int *array, size_t size, int n)
{
	int *product = NULL;
	int count[10] = {0};
	size_t idx = 0;

	product = malloc(sizeof(int) * size);
	for (; idx < size; idx++)
		count[(array[idx] / n) % 10]++;
	idx = 1;
	for (; idx < 10; idx++)
		count[idx] += count[idx - 1];
	idx = size - 1;
	while (1)
	{
		product[count[(array[idx] / n) % 10] - 1] = array[idx];
		count[(array[idx] / n) % 10]--;
		if (idx == 0)
			break;
		idx--;
	}
	idx = 0;
	for (; idx < size; idx++)
		array[idx] = product[idx];
	free(product);
}

/**
 * radix_sort - radix sort
 * @array: array to sort
 * @size: size of array to sort
 * Return: null
 */

void radix_sort(int *array, size_t size)
{
	size_t mx, n;

	if (!array || size < 2)
		return;
	mx = max_int(array, size);
	n = 1;
	for (; mx / n > 0; n *= 10)
	{
		count_sort(array, size, n);
		print_array(array, size);
	}
}
