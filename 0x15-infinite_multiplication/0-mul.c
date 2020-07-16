#include "holberton.h"
#include <string.h>

/**
 * mem_set - helper function that mimics memset
 * @q: address
 * @c: set type
 * @size: size
 * Return: pointer
 */

void *mem_set(void *q, int c, int size)
{
	int idx;
	char *p = q;

    idx = 0;
	for (; idx < size ; idx++)
	{
		*p = c;
		p++;
	}
	return (q);
}

/**
 * _calloc - function that allocates memory for an array
 * @nmemb: nmemeber to be used.
 * @size: size parameter.
 * Return: Always 0.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int x = 0;
	char *memo;

	if (nmemb == 0 || size == 0)
	return (NULL);

	memo = malloc(nmemb * size);
	if (memo == NULL)
	return (NULL);
	for (; x < nmemb * size; x++)
		memo[x] = 0;
	return (memo);
}

/**
 * main - multiplies two positive numbers
 * @argc: first argument
 * @argv: second argument
 * Return: 0
 */

int main(int argc, char **argv)
{
	int l1, l2, carry, foo, b, idx, y;
	int *result;
    if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);
	result = _calloc(l1 + l2, sizeof(*result));

    idx = l1 - 1;
	for (; idx >= 0; idx--)
	{
		carry = 0;
		foo = argv[1][idx] - '0';
        y = l2 - 1;
		for (; y >= 0; y--)
		{
			b = argv[2][y] - '0';
			carry += result[idx + y + 1] + (foo * b);
			result[y + idx + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[idx + y + 1] += carry;
	}
	foo = result[0] == 0 ? 1 : 0;
	for (; foo < l1 + l2; foo++)
		printf("%d", result[foo]);
	printf("\n");
	free(result);
	return (0);
}
