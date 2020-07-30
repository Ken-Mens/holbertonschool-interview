#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to head node
 * Return: address of node where loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_p = head, *fast_p = head;

	if (!head)
		return (NULL);

	while (fast_p && slow_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
		{
			slow_p = head;
			while (slow_p != fast_p)
			{
				if (fast_p == NULL)
				{
					return (NULL);
				}
				slow_p = slow_p->next;
				fast_p = fast_p->next;
			}
			return (fast_p);
		}
	}
	return (NULL);
}
