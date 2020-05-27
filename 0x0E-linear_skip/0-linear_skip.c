#include "search.h"

/**
 * linear_skip - searches for element in sorted skip list
 * @list: skip list of integers
 * @value: search value
 * Return: Address of the valued node or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipd = NULL;
	skiplist_t *plchd = NULL;

	if (list == NULL)
		return (NULL);
	skipd = list;
	while (skipd)
	{
		plchd = skipd->express;
		printf("Value checked at index [%lu] = [%i]\n",
		       (plchd)->index, (plchd)->n);
		if ((plchd)->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			       skipd->index, (plchd)->index);
			break;
		}
		if (!(plchd)->express)
		{
			skipd = skipd->express;
			plchd = skipd;
			while (plchd->next)
				plchd = plchd->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       skipd->index, plchd->index);
			break;
		}
		skipd = skipd->express;
	}
	while (plchd <= skipd->next)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       skipd->index, skipd->n);
		if (skipd->n == value)
			return (skipd);
		if (skipd->n > value)
			return (NULL);
		skipd = skipd->next;
	}
	printf("Value checked at index [%lu] = [%i]\n", skipd->index, skipd->n);
	return (NULL);
}
