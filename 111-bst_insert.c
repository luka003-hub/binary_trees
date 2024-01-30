#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of BST
 * @value: value to store in the node to be inserted
 * Return: pointer to created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *temp;
	binary_tree_t *node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		node = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)node;
		*tree = new;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				new = bst_insert(&temp->left, value);
			else
			{
				node = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->left = (bst_t *)node;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new = bst_insert(&temp->right, value);
			else
			{
				node = binary_tree_node((binary_tree_t *)temp, value);
				new = temp->right = node;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
