#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - function creates a binary tree node
 *
 * @parent: parent of created node
 * @value: value of node
 *
 * Return: pointer to neo node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *neo;

	neo = malloc(sizeof(binary_tree_t));
	if (!neo)
		return (NULL);
	neo->parent = parent;
	neo->n = value;
	neo->left = NULL;
	neo->right = NULL;
	return (neo);
}
