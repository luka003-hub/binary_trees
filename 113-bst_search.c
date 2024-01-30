#include "binary_trees.h"
/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST
 * @value: value to search
 * Return: pointer to value or NULL if tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *point;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		point = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		point = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (point);
}
