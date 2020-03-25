#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks linked list for cycles.
 *
 * @list: pointer to the head of a linked list.
 *
 * Return: 1 if there is a cycle, 0 on false.
 */

int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list->next;

	if (list == NULL || !(list->next))
		return (0);
	while ((fast->next) != NULL)
	{
		fast = fast->next;
		if (fast->next)
			fast = fast->next;
		else
			return (0);
		slow = slow->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
