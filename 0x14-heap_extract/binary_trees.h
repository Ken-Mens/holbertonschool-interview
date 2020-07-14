#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *tree);
int heap_extract(heap_t **root);
void heapify(heap_t *heap);
void swap(binary_tree_t *node1, binary_tree_t *node2);
binary_tree_t *get_nth(binary_tree_t *node, size_t n);
size_t tree_size(heap_t *tree);
#endif /* BINARY_TREES_H */
