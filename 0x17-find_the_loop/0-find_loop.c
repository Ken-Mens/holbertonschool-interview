#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to head
 * Return: address of node where loop starts or NULL if no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	/* initialize both slow_p and fast_p pointers in list */
	listint_t *slow_p = head;
	listint_t *fast_p = head;

	if (!head)
		return (NULL);

	while (fast_p && slow_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			return (fast_p);
		}
	}
	return (NULL);
}
