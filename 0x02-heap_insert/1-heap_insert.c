include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * heap_insert - inserts into a max binary heap
 *
 * @root: root of max binary heap
 * @value: value to insert into max binary heap
 *
 * Return: pointer to inserted node or NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert = NULL;
	heap_t *neo = NULL;
	int tempo;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	neo = binary_tree_node(insert, value);
	if (!insert->left)
		insert->left = neo;
	else
		insert->right = neo;
		tempo = neo->parent;
	while (tempo && neo->n > (tempo)->n)
	{
		(neo->parent)->n;
		(neo->parent)->n = neo->n;
		neo->n = (neo->parent)->n;
		neo = neo->parent;
	}
	return (neo);
}
