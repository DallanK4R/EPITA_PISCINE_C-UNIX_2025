#include "bst.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *k = malloc(sizeof(struct bst_node));
    k->left = NULL;
    k->right = NULL;
    k->data = value;
    return k;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (!tree)
        return create_node(value);
    if (value < tree->data)
        tree->left = add_node(tree->left, value);
    if (value > tree->data)
        tree->right = add_node(tree->right, value);
    return tree;
}

int get_and_remove_max_of_min(struct bst_node *tree, struct bst_node *parent)
{
    struct bst_node *ptr = tree;
    struct bst_node *prev = NULL;
    while (ptr->right)
    {
        prev = ptr;
        ptr = ptr->right;
    }
    int res = ptr->data;

    if (prev)
        prev->right = ptr->left;
    else
        parent->left = ptr->left;
    free(ptr);
    return res;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (tree)
    {
        if (tree->data == value)
        {
            if (tree->right && tree->left)
                tree->data = get_and_remove_max_of_min(tree->left, tree);
            else if (tree->right)
            {
                struct bst_node *tmp = tree->right;
                free(tree);
                tree = tmp;
            }
            else if (tree->left)
            {
                struct bst_node *tmp = tree->left;
                free(tree);
                tree = tmp;
            }
            else
            {
                free(tree);
                tree = NULL;
            }
        }
        else if (tree->data > value)
            tree->left = delete_node(tree->left, value);
        else
            tree->right = delete_node(tree->right, value);
    }
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (!tree)
        return NULL;
    if (value < tree->data)
        return find(tree->left, value);
    if (value > tree->data)
        return find(tree->right, value);
    if (value == tree->data)
        return tree;
    return NULL;
}

void free_bst(struct bst_node *tree)
{
    if (!tree)
        return;
    if (tree->left)
        free_bst(tree->left);
    if (tree->right)
        free_bst(tree->right);
    free(tree);
}
