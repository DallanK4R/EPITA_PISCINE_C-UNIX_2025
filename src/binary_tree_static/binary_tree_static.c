#include "binary_tree_static.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t size(const struct binary_tree *tree)
{
    if (tree == NULL)
        return 0;
    size_t k = 0;
    for (size_t i = 0; i <= tree->max_index; i++)
    {
        if (tree->data[i])
            k++;
    }
    return k;
}

int my_max(int a, int b)
{
    return a >= b ? a : b;
}

int heightbis(const struct binary_tree *tree, size_t index)
{
    if (!tree->data[index])
        return 0;
    if (2 * index + 2 > tree->max_index)
        return 0;
    if (tree->data[2 * index + 1])
    {
        if (tree->data[2 * index + 2])
            return 1
                + my_max(heightbis(tree, 2 * index + 1),
                         heightbis(tree, 2 * index + 2));
        else
            return 1 + my_max(heightbis(tree, 2 * index + 1), 0);
    }
    else
    {
        if (tree->data[2 * index + 2])
            return 1 + my_max(0, heightbis(tree, 2 * index + 2));
        else
            return 0;
    }
}

int height(const struct binary_tree *tree)
{
    if (tree == NULL)
        return -1;
    if (!tree->data[1] && !tree->data[2])
        return 0;
    return 1 + my_max(heightbis(tree, 1), heightbis(tree, 2));
}

void dfsaux(const struct binary_tree *tree, size_t index)
{
    if (index > tree->max_index)
        return;
    if (tree->data[index])
    {
        if (index != 0)
            printf("%i ", tree->data[index]->val);
        dfsaux(tree, index * 2 + 1);
        dfsaux(tree, index * 2 + 2);
    }
}

void dfs_print_prefix(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    if (tree->data[0])
    {
        printf("%i ", tree->data[0]->val);
        dfsaux(tree, 0);
    }
}

void printlvl(const struct binary_tree *tree, size_t index)
{
    printf("| ");
    for (size_t i = index; i < index * 2 + 1; i++)
    {
        if (tree->data[i])
            printf("%i ", tree->data[i]->val);
    }
}

void bfs_print(const struct binary_tree *tree)
{
    if (tree == NULL)
        return;
    if (tree->data[0])
    {
        printf("%i ", tree->data[0]->val);
        size_t i = 1;
        while (i < tree->max_index)
        {
            printlvl(tree, i);
            i = 2 * i + 1;
        }
    }
}
