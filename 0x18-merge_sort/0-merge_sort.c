#include "sort.h"
/**
 * merge_split - Splits subarray
 * @array: array of integers
 * @size: Number of elements in array
 * @tempo: pointer to integer variable
 * Return: None
 */
void merge_split(int *array, size_t size, int *tempo)
{
	int m = size / 2;

	if (size < 2)
		return;
	merge_split(array, m, tempo);
	merge_split(array + m,  size - m, tempo);
	merger(array, size, m, tempo);
}
/**
 * merge_sort - Sorts array using merge sort algorithm
 * @array: array of integers
 * @size: Number of elements in array
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *tempo = NULL;

	if (size < 2)
		return;
	tempo = malloc(sizeof(int) * size);
	merge_split(array, size, tempo);
	free(tempo);
}
/**
 * merger - Merges subarrays
 * @array: pointer to array of integers
 * @size: Number of elements in array
 * @m: integer index
 * @tempo: pointer to integer variable
 * Return: Null
 */
void merger(int *array, int size, int m, int *tempo)
{
	int uno, tres, dos;

	printf("Merging...\n[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);
	uno = 0;
	dos = 0;
	tres = m;
	for (; dos < size; dos++)
	{

		if (tres == size)
		{
			tempo[dos] = array[uno];
			uno++;
		}
		else if (array[tres] < array[uno])
		{
			tempo[dos] = array[tres];
			tres++;
		}
		else if (uno == m)
		{
			tempo[dos] = array[tres];
			tres++;
		}
		else
		{
			tempo[dos] = array[uno];
			uno++;
		}
	}
	uno = 0;
	for (; uno < size; uno++)
	{
		array[uno] = tempo[uno];
	}
	printf("[Done]: ");
	print_array(tempo, size);
}
