#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the
 * array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t k = 0;
	bst_t *tree;

	tree = NULL;
	if (size == 0)
	{
		return (NULL);
	}

	for (; k < size; k++)
	{
		bst_insert(&tree, array[k]);
	}

	return (tree);
}
