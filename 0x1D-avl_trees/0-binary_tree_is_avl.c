#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl - Determines if a binary tree is an AVL tree
 * @tree: root node of tree
 * Return: 1 if tree is a valid AVL, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (bst_check(tree, INT_MIN, INT_MAX) != 1)
		return (0);
	return (1);
}

/**
 * bst_check - checks for bestness
 * @root: root node of tree
 * @min: minimum value constraint
 * @max: maximum value constraint
 * Return: 1 if bst, 0 otherwise
 */

int bst_check(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	return (bst_check(root->left, min, root->n - 1) &&
		bst_check(root->right, root->n + 1, max));
}

/**
 * height_check - check tree height
 * @root: root node of tree
 * Return: height of tree
 */

int height_check(const binary_tree_t *root)
{
	int l, r;

	if (root == NULL)
		return (0);
	l = height_check(root->left);
	r = height_check(root->right);
	if (r > l)
		return (1 + r);
	return (1 + l);
}
