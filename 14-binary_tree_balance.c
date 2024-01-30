#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a balance tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t x = 0;
	size_t y = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			y = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			x = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((y > x) ? y : x);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree to measure balance factor
 * Return: balanced factor or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, bal = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		bal = left - right;
	}
	return (bal);
}
