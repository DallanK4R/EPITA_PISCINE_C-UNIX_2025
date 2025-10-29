#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree_static.h"

int is_complete(const struct binary_tree *tree)
{
    if (!tree)
        return 1;
    if (tree->max_index >= CAPACITY)
        return 0;
    if (tree->max_index == 0)
        return tree->data[0] != NULL;
    int seen_empty = 0;
    for (size_t i = 0; i <= tree->max_index; i++)
    {
        if (!tree->data[i])
            seen_empty = 1;
        else if (seen_empty)
            return 0;
    }
    return tree->data[0] != NULL;
}

static int all_present_until(const struct binary_tree *tree, size_t last)
{
    if (last >= CAPACITY)
        return 0;
    for (size_t i = 0; i <= last; i++)
        if (!tree->data[i])
            return 0;
    return 1;
}

int is_perfect(const struct binary_tree *tree)
{
    if (!tree)
        return 1;
    if (!is_complete(tree))
        return 0;
    size_t deepest = 0;
    for (size_t i = 0; i <= tree->max_index; i++)
        if (tree->data[i])
            deepest = i;
    size_t level_end = 0;
    size_t h = 0;
    while (level_end < deepest && (1 << (h + 1)) - 2 < CAPACITY)
    {
        h++;
        level_end = (1 << (h + 1)) - 2;
    }
    if (level_end >= CAPACITY)
        return 0;
    if (!all_present_until(tree, level_end))
        return 0;
    return tree->max_index <= level_end;
}
