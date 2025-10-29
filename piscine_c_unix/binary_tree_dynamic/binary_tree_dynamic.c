#include "binary_tree_dynamic.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

size_t size(const struct binary_tree *tree)
{
    if (tree)
        return 1 + size(tree->left) + size(tree->right);
    else
        return 0;
}

int height(const struct binary_tree *tree)
{
    if (!tree)
        return 0;
    int hl = height(tree->left);
    int hr = height(tree->right);
    return (hl > hr ? hl : hr) + 1;
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (!tree)
        return;
    printf("%d ", tree->data);
    dfs_print_prefix(tree->left);
    dfs_print_prefix(tree->right);
}

void dfs_print_infix(const struct binary_tree *tree)
{
    if (!tree)
        return;
    dfs_print_infix(tree->left);
    printf("%d ", tree->data);
    dfs_print_infix(tree->right);
}

void dfs_print_postfix(const struct binary_tree *tree)
{
    if (!tree)
        return;
    dfs_print_postfix(tree->left);
    dfs_print_postfix(tree->right);
    printf("%d ", tree->data);
}

static int pow2_upto(int h, size_t *out)
{
    size_t v = 1;
    for (int i = 1; i < h; i++)
    {
        if (v > ((size_t)-1) / 2)
            return 0;
        v <<= 1;
    }
    *out = v;
    return 1;
}

int is_perfect(const struct binary_tree *tree)
{
    if (!tree)
        return 0;
    int h = height(tree);
    size_t n = size(tree);
    size_t p;
    if (h == 0)
        return 1;
    if (!pow2_upto(h, &p))
        return 0;
    return n == p * 2 - 1;
}

static int complete_check(const struct binary_tree *t, size_t idx, size_t n)
{
    if (!t)
        return 1;
    if (idx >= n)
        return 0;
    return complete_check(t->left, idx * 2 + 1, n)
        && complete_check(t->right, idx * 2 + 2, n);
}

int is_complete(const struct binary_tree *tree)
{
    if (!tree)
        return 0;
    size_t n = size(tree);
    if (n == 0)
        return 1;
    return complete_check(tree, 0, n);
}
