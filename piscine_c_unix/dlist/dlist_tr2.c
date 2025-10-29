#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

static struct dlist_item *node_at(const struct dlist *list, size_t index)
{
    if (index >= list->size)
        return NULL;
    struct dlist_item *n;
    if (index < list->size / 2)
    {
        n = list->head;
        for (size_t i = 0; i < index; i++)
            n = n->next;
    }
    else
    {
        n = list->tail;
        for (size_t i = list->size - 1; i > index; i--)
            n = n->prev;
    }
    return n;
}

int dlist_get(const struct dlist *list, size_t index)
{
    if (!list || index >= list->size)
        return -1;
    struct dlist_item *node = node_at(list, index);
    if (!node)
        return -1;
    return node->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (!list || element < 0 || index > list->size)
        return 0;
    if (index == 0)
        return dlist_push_front(list, element);
    if (index == list->size)
        return dlist_push_back(list, element);
    struct dlist_item *node = malloc(sizeof(*node));
    if (!node)
        return 0;
    struct dlist_item *pos = node_at(list, index);
    if (!pos)
    {
        free(node);
        return 0;
    }
    node->data = element;
    node->prev = pos->prev;
    node->next = pos;
    pos->prev->next = node;
    pos->prev = node;
    list->size++;
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (!list || element < 0)
        return -1;
    struct dlist_item *cur = list->head;
    size_t i = 0;
    while (cur)
    {
        if (cur->data == element)
            return i;
        cur = cur->next;
        i++;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (!list || index >= list->size)
        return -1;
    struct dlist_item *n = node_at(list, index);
    if (!n)
        return -1;
    int val = n->data;
    if (n->prev)
        n->prev->next = n->next;
    else
        list->head = n->next;
    if (n->next)
        n->next->prev = n->prev;
    else
        list->tail = n->prev;
    free(n);
    list->size--;
    return val;
}

void dlist_clear(struct dlist *list)
{
    if (!list)
        return;
    struct dlist_item *cur = list->head;
    while (cur)
    {
        struct dlist_item *next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
