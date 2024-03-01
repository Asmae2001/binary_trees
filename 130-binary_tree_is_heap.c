#include "binary_trees.h"

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: Index of the current node
 * @node_count: Number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
    /* If the tree is empty or if the current index exceeds the number of nodes */
    if (tree == NULL)
        return (1);

    if (index >= node_count)
        return (0);

    /* Recursively check the left and right subtrees */
    return (binary_tree_is_complete(tree->left, 2 * index + 1, node_count) &&
            binary_tree_is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_heap_util - Check if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap_util(const binary_tree_t *tree)
{
    /* If the tree is empty, it's a valid Max Binary Heap */
    if (tree == NULL)
        return (1);

    /* If the current node has no children, it satisfies the heap property */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* If the current node has a left child but no right child, check the heap property */
    if (tree->right == NULL)
        return (tree->n >= tree->left->n && binary_tree_is_heap_util(tree->left));

    /* If the current node has both left and right children, check the heap property */
    if (tree->n >= tree->left->n && tree->n >= tree->right->n)
        return (binary_tree_is_heap_util(tree->left) && binary_tree_is_heap_util(tree->right));

    return (0); /* If none of the above conditions are satisfied, it's not a valid Max Binary Heap */
}

/**
 * binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    size_t node_count = binary_tree_size(tree);
    size_t index = 0;

    /* If the tree is empty, it's not a valid Max Binary Heap */
    if (tree == NULL)
        return (0);

    /* Check if the tree is a complete tree */
    if (!binary_tree_is_complete(tree, index, node_count))
        return (0);

    /* Check if the tree satisfies the Max Binary Heap property */
    return (binary_tree_is_heap_util(tree));
}
