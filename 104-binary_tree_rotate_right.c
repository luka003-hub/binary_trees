#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: Pointer to new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	new = tree->left;
	tree->left = new->right;
	if (new->right != NULL)
	{
		new->right->parent = tree;
	}
	new->right = tree;
	new->parent = tree->parent;
	tree->parent = new;
	return (new);
}
