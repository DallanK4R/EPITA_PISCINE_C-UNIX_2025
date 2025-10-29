#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;
    struct dlist_item *node = malloc(sizeof(struct dlist_item));
    if (!node)
        return 0;
    node->data = element;
    node->prev = NULL;
    node->next = list->head;
    if (list->head)
        list->head->prev = node;
    else
        list->tail = node;
    list->head = node;
    list->size++;
    return 1;
}

int dlist_push_back(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;
    struct dlist_item *node = malloc(sizeof(struct dlist_item));
    if (!node)
        return 0;
    node->data = element;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail)
        list->tail->next = node;
    else
        list->head = node;
    list->tail = node;
    list->size++;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    if (!list)
        return;
    struct dlist_item *curr = list->head;
    while (curr)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

size_t dlist_size(const struct dlist *list)
{
    if (!list)
        return 0;
    return list->size;
}
