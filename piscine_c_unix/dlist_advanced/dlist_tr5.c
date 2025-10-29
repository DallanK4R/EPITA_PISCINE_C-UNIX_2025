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

void dlist_shift(struct dlist *list, int offset)
{
    if (!list || list->size < 2 || offset == 0)
        return;
    size_t n = list->size;
    size_t k = offset >= 0 ? offset % n : (n - ((-offset) % n)) % n;
    if (k == 0)
        return;
    size_t new_head_idx = n - k;
    struct dlist_item *nh = node_at(list, new_head_idx);
    struct dlist_item *nt = nh->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    nt->next = NULL;
    nh->prev = NULL;
    list->head = nh;
    list->tail = nt;
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (!list || element < 0)
        return 0;
    if (list->size == 0)
        return dlist_push_front(list, element);
    if (element <= list->head->data)
        return dlist_push_front(list, element);
    if (element >= list->tail->data)
        return dlist_push_back(list, element);
    struct dlist_item *p = list->head->next;
    while (p && p->data < element)
        p = p->next;
    struct dlist_item *n = malloc(sizeof(*n));
    if (!n)
        return 0;
    n->data = element;
    n->prev = p->prev;
    n->next = p;
    p->prev->next = n;
    p->prev = n;
    list->size++;
    return 1;
}

int dlist_remove_eq(struct dlist *list, int element)
{
    if (!list || element < 0 || list->size == 0)
        return 0;
    struct dlist_item *n = list->head;
    while (n && n->data != element)
        n = n->next;
    if (!n)
        return 0;
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
    return 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *r = malloc(sizeof(*r));
    if (!r)
        return NULL;
    r->head = NULL;
    r->tail = NULL;
    r->size = 0;
    if (!list || list->size == 0)
        return r;
    struct dlist_item *p = list->head;
    while (p)
    {
        struct dlist_item *n = malloc(sizeof(*n));
        if (!n)
        {
            struct dlist_item *c = r->head;
            while (c)
            {
                struct dlist_item *nx = c->next;
                free(c);
                c = nx;
            }
            free(r);
            return NULL;
        }
        n->data = p->data;
        n->prev = r->tail;
        n->next = NULL;
        if (r->tail)
            r->tail->next = n;
        else
            r->head = n;
        r->tail = n;
        r->size++;
        p = p->next;
    }
    return r;
}
