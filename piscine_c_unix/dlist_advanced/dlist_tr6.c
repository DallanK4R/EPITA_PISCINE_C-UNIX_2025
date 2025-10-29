#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_sort(struct dlist *list)
{
    if (!list || list->size < 2)
        return;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        struct dlist_item *p = list->head;
        while (p && p->next)
        {
            if (p->data > p->next->data)
            {
                int t = p->data;
                p->data = p->next->data;
                p->next->data = t;
                swapped = 1;
            }
            p = p->next;
        }
    }
}

void dlist_mergeauxjaj(struct dlist *list1, struct dlist *list2)
{
    list1->head = list2->head;
    list1->tail = list2->tail;
    list1->size = list2->size;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}

void dlist_mergeauxjaj2(struct dlist *list1, struct dlist *list2,
                        struct dlist_item *h, struct dlist_item *t)
{
    list1->head = h;
    list1->tail = t;
    list1->size += list2->size;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    if (!list1 || !list2 || list2->size == 0)
        return;
    if (list1->size == 0)
    {
        dlist_mergeauxjaj(list1, list2);
        return;
    }
    struct dlist_item *a = list1->head;
    struct dlist_item *b = list2->head;
    struct dlist_item *h = NULL;
    struct dlist_item *t = NULL;
    while (a || b)
    {
        struct dlist_item *pick;
        if (!b || (a && a->data <= b->data))
        {
            pick = a;
            a = a->next;
        }
        else
        {
            pick = b;
            b = b->next;
        }
        pick->prev = t;
        pick->next = NULL;
        if (t)
            t->next = pick;
        else
            h = pick;
        t = pick;
    }
    dlist_mergeauxjaj2(list1, list2, h, t);
}
