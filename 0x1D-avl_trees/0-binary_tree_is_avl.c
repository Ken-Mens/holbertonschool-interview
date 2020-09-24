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
	if (best_check(tree, INT_MIN, INT_MAX) != 1)
		return (0);
	return (1);
}

/**
 * best_check - checks for bestness
 * @root: root node of tree
 * @min: minimum value constraint
 * @max: maximum value constraint
 * Return: 1 if bst, 0 otherwise
 */

int best_check(const binary_tree_t *root, int min, int max)
{
	if (root == NULL)
		return (1);
	if (root->n < min || root->n > max)
		return (0);
	return (best_check(root->left, min, root->n - 1) &&
		best_check(root->right, root->n + 1, max));
}

/**
 * height_check - check tree height
 * @root: root node of  avl tree
 * Return: height of  avl tree
 */

int height_check(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);
	l = height_check(tree->left);
	r = height_check(tree->right);
	if (r > l)
		return (1 + r);
	return (1 + l);
}
