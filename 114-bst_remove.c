#include "binary_trees.h"
/**
 * replacement - finds the min value in the right subtree
 * @tree: pointer to tree to check
 * Return: min value
 */
int replacement(bst_t *tree)
{
	int left = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left = replacement(tree->left);
		if (left == 0)
		{
			return (tree->n);
		}
		return (left);
	}

}
/**
 * twochildren - function that gets the min value
 * in the case where node to be removed has
 * two children
 * @node: pointer to the node with two children
 * Return: min value found
 */
int twochildren(bst_t *node)
{
	int new_value = 0;

	new_value = replacement(node->right);
	node->n = new_value;
	return (new_value);
}
/**
 *remove_ - removes a node based on number of children
 *@node: pointer to node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_(bst_t *node)
{
	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
		return (twochildren(node));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}
