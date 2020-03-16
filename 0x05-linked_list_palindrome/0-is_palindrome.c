#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * is_palindrome - method to check if or not a linked list is a palindrome
 *
 * @head: head of the linked list
 *
 * Return: 1 if palindrome, otherwise 0
 */

int is_palindrome(listint_t **head)
{
	listint_t **side = NULL;
	
	int result = 0;

	if (!head)
                return (0);
        if (!*head || (*head)->next == NULL)
                return (1);
	side = head;
	result = traverse(side, *side);
	return (result);
}

/**
 * traverse - Recursive function to check a linked list for palindrome
 *
 * @left: side value to check
 * @right: bottom value to check
 *
 * Return: 1 or otherwise 0;
 */

int traverse(listint_t **left, listint_t *right)
{
	int result = 1;
	int tempo = -1;

	if (right == NULL)
		return (1);
	result = traverse(left, right->next);
	if (result == 0)
		return (0);
	if ((*left)->n == right->n)
			tempo = 1;
		else
			tempo = 0;
		*left = (*left)->next;
		return (tempo);
}
