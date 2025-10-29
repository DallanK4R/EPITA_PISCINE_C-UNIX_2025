#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include "binary_tree_dynamic.h"

int is_degenerate(const struct binary_tree *tree)
{
    if (!tree)
        return 1;
    if (tree->left && tree->right)
        return 0;
    return is_degenerate(tree->left ? tree->left : tree->right);
}

int is_full(const struct binary_tree *tree)
{
    if (!tree)
        return 1;
    int l = tree->left != NULL;
    int r = tree->right != NULL;
    if (l != r)
        return 0;
    return is_full(tree->left) && is_full(tree->right);
}

static int bst_check(const struct binary_tree *t, long long lo, long long hi)
{
    if (!t)
        return 1;
    if ((long long)t->data < lo || (long long)t->data > hi)
        return 0;
    if (!bst_check(t->left, lo, (long long)t->data))
        return 0;
    return bst_check(t->right, (long long)t->data + 1, hi);
}

int is_bst(const struct binary_tree *tree)
{
    return bst_check(tree, -(1LL << 62), (1LL << 62));
}
