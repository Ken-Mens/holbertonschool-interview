#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *anode;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	anode = *head;
	if (number < anode->n)
	{
		new->next = anode;
		(*head) = new;
		return (new);
	}
	while (anode->next && number > anode->next->n)
	{
		anode = anode->next;
	}
	new->next = anode->next;
	anode->next = new;
	return (new);
}
