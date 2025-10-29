#include "bst_static.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int ensure_capacity(struct bst *tree, size_t need)
{
    if (need <= tree->capacity)
        return 1;
    size_t cap = tree->capacity ? tree->capacity : 1;
    while (cap < need)
        cap *= 2;
    struct value **ndata = realloc(tree->data, cap * sizeof(*ndata));
    if (!ndata)
        return 0;
    for (size_t i = tree->capacity; i < cap; i++)
        ndata[i] = NULL;
    tree->data = ndata;
    tree->capacity = cap;
    return 1;
}

struct bst *init(size_t capacity)
{
    struct bst *t = malloc(sizeof(*t));
    if (!t)
        return NULL;
    if (capacity == 0)
        capacity = 1;
    t->data = calloc(capacity, sizeof(*t->data));
    if (!t->data)
    {
        free(t);
        return NULL;
    }
    t->capacity = capacity;
    t->size = 0;
    return t;
}

void add(struct bst *tree, int value)
{
    if (!tree)
        return;
    size_t i = 0;
    for (;;)
    {
        if (!ensure_capacity(tree, i + 1))
            return;
        if (!tree->data[i])
        {
            tree->data[i] = malloc(sizeof(*tree->data[i]));
            if (!tree->data[i])
                return;
            tree->data[i]->val = value;
            tree->size++;
            return;
        }
        if (value == tree->data[i]->val)
            return;
        i = (value < tree->data[i]->val) ? (2 * i + 1) : (2 * i + 2);
    }
}

int search(struct bst *tree, int value)
{
    if (!tree || tree->capacity == 0)
        return -1;
    size_t i = 0;
    while (i < tree->capacity && tree->data[i])
    {
        if (value == tree->data[i]->val)
            return i;
        i = (value < tree->data[i]->val) ? (2 * i + 1) : (2 * i + 2);
    }
    return -1;
}

void bst_free(struct bst *tree)
{
    if (!tree)
        return;
    if (tree->data)
    {
        for (size_t i = 0; i < tree->capacity; i++)
            if (tree->data[i])
                free(tree->data[i]);
        free(tree->data);
    }
    free(tree);
}
