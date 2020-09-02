#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - add node to the end of circular doubly linked list
 * @list: head of the Doubly linked list
 * @str: malloc'd string
 * Return: address of the new node or NULL
 */

List *add_node_end(List **list, char *str)
{
	List *foo, *tail;

	if (!list)
		return (NULL);
	foo = malloc(sizeof(List));
	foo->str = strdup(str);
	if (!(foo->str))
	{
		free(foo->str);
		return (NULL);
	}
	if (*list)
	{
		tail = (*list)->prev;
		tail->next = foo;
		foo->prev = tail;
		foo->next = (*list);
		(*list)->prev = foo;
	}
	else
	{
		foo->next = foo;
		foo->prev = foo;
		(*list) = foo;
	}
	return (foo);
}

/**
 * add_node_begin - add node at the start of a doubly linked list
 * @list: head of the Doubly Linked List
 * @str: malloc'd string ref
 * Return: address of the new node or NULL
 */

List *add_node_begin(List **list, char *str)
{
	List *foo = NULL;

	foo = add_node_end(list, str);
	if (!foo)
		return (NULL);
	(*list) = foo;
	return (foo);
}
