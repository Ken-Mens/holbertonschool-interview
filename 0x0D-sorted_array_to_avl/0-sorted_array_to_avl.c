#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL tree from sorted array
 *
 * @array: array to tree
 * @size: size of array to tree
 * Return: Pointer to tree root
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *node = NULL;
    size_t mid;

    if (!size || !array)
        return (NULL);
    node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);
    mid = (size - 1) / 2;
    node->n = array[mid];
    node->parent = NULL;
    if (mid > 0)
        node = sorted_array_to_avl(array, mid);
    else
        node->left = NULL;
    if (size > (mid + 1))
        node = sorted_array_to_avl(&array[mid + 1], size - (mid + 1));
    else    
        node->right = NULL;
    return (node);
}
