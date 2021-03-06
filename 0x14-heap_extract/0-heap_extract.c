#include "binary_trees.h"

/**
 * tree_size - traverses binary tree
 * and return size
 * @tree: binary tree
 * Return: number of elements of a tree
 */
size_t tree_size(heap_t *tree)
{
	size_t left_side = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);
	else
	{
		left_side = tree_size(tree->left);
		right_size = tree_size(tree->right);
	}
	
	if (left_side > right_size)
		return(left_side + 1);
	else return (right_size + 1);
}

/**
 * swap - swap two nodes of binary tree
 * @node1: first 
 * @node2: second
*/
void swap(binary_tree_t *node1, binary_tree_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * get_nth - get nth node
 * @node: heap node
 * @n: idx of node
 * Return: parent if n is greater than size
 */
binary_tree_t *get_nth(binary_tree_t *node, size_t n)
{
	int idx, foo;

	idx = 0;
	for (; 1 << (idx + 1) <= (int)n; ++idx)
		;
	--idx;
	for (; idx >= 0; --idx)
	{
		foo = 1 << idx;
		if (n & foo)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * heapify - fully heapifies nodes
 * @heap: heap
 */
void heapify(heap_t *heap)
{
	binary_tree_t *largest, *node;

	if (!heap)
		return;
	node = heap;
	while (node->left)
	{
		largest = node->left;
		if (node->right && node->n < node->right->n
		    && node->right->n > node->left->n)
		{
			swap(node->right, node);
			largest = node->right;
		}
		else if (node->n < node->left->n)
		{
			swap(node->left, node);
		}
		node = largest;
	}
}

/**
 * heap_extract - extracts root node from heap
 * @root: root of the heap
 * Return: value from extracted node, 0 if failed
 */
int heap_extract(heap_t **root)
{
	heap_t *last_dance;
	int info;

	if (!root)
		return (0);
	last_dance = get_nth(*root, tree_size(*root));
	info = (*root)->n;
	(*root)->n = last_dance->n;
	if (last_dance->parent)
	{
		if (last_dance->parent->left == last_dance)
			last_dance->parent->left = NULL;
		else
			last_dance->parent->right = NULL;
	}
	else
	{
		*root = NULL;
	}
	free(last_dance);
	heapify(*root);
	return (info);
}
