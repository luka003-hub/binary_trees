#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: Poipointer to new root node of tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	new = tree->right;
	tree->right = new->left;
	if (new->left != NULL)
	{
		new->left->parent = tree;
	}
	new->left = tree;
	new->parent = tree->parent;
	tree->parent = new;
	return (new);
}
