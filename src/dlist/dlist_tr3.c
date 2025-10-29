#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    if (!list)
        return;
    struct dlist_item *n = list->head;
    while (n)
    {
        n->data = n->data * n->data;
        n = n->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    if (!list || list->size < 2)
        return;
    struct dlist_item *n = list->head;
    while (n)
    {
        struct dlist_item *tmp = n->next;
        n->next = n->prev;
        n->prev = tmp;
        n = tmp;
    }
    struct dlist_item *t = list->head;
    list->head = list->tail;
    list->tail = t;
}

static struct dlist_item *node_at(const struct dlist *list, size_t index)
{
    if (index >= list->size)
        return NULL;
    if (index < list->size / 2)
    {
        struct dlist_item *n = list->head;
        for (size_t i = 0; i < index; i++)
            n = n->next;
        return n;
    }
    else
    {
        struct dlist_item *n = list->tail;
        for (size_t i = list->size - 1; i > index; i--)
            n = n->prev;
        return n;
    }
}

struct dlist *dlist_split_ataux(struct dlist *list, struct dlist *res)
{
    res->head = list->head;
    res->tail = list->tail;
    res->size = list->size;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return res;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (!list)
        return NULL;
    if (index > list->size)
        return NULL;
    struct dlist *res = malloc(sizeof(*res));
    if (!res)
        return NULL;
    if (list->size == 0 || index == list->size)
    {
        res->head = NULL;
        res->tail = NULL;
        res->size = 0;
        return res;
    }
    if (index == 0)
        return dlist_split_ataux(list, res);
    struct dlist_item *cut_prev = node_at(list, index - 1);
    struct dlist_item *cut = cut_prev ? cut_prev->next : NULL;
    if (!cut_prev || !cut)
    {
        free(res);
        return NULL;
    }
    res->head = cut;
    res->tail = list->tail;
    res->size = list->size - index;
    list->tail = cut_prev;
    list->size = index;
    cut_prev->next = NULL;
    cut->prev = NULL;
    return res;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list2->size == 0)
        return;
    if (list1->size == 0)
    {
        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->size = list2->size;
        list2->head = NULL;
        list2->tail = NULL;
        list2->size = 0;
        return;
    }
    list1->tail->next = list2->head;
    list2->head->prev = list1->tail;
    list1->tail = list2->tail;
    list1->size += list2->size;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
