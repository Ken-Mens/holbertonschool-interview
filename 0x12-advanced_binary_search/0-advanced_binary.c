#include "search_algos.h"

/**
 * print_array - prints an array
 * @array: array to print
 * @l: left bound
 * @r: right bound
 * Return: void
 */

void print_away(int *array, size_t l, size_t r)
{
	size_t  idx;

	printf("Searching in array: ");
	for (idx = l; idx <= r; idx++)
	{
		printf("%d", array[idx]);
		if (idx < r)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - binary search
 * @array: array to search
 * @l: left bound
 * @r: right bound
 * @value: value to search for
 * Return: Index or -1
 */

int binary_search(int *array, size_t l, size_t r, int value)
{
	size_t mid;

	if (l < r)
	{
		print_away(array, l, r);
		mid = (l + r) / 2;
		if (array[mid] < value)
			{
				return (binary_search(array, mid + 1, r, value));
			}
		else	
			return (binary_search(array, l, mid, value));
	}
	if (array[l] == value)
		return (l);
	print_away(array, l, r);
	return (-1);
}

/**
 * advanced_binary - Finds index of value
 * @array: array to searched
 * @size: size of array
 * @value: value to searched for
 * Return: Index of value 
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
