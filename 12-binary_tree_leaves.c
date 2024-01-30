#include "binary_trees.h"
/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, a = 0, b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		b = binary_tree_leaves(tree->left);
		a = binary_tree_leaves(tree->right);
		leaf = b + a;
		return ((!b && !a) ? leaf + 1 : leaf + 0);
	}
}
