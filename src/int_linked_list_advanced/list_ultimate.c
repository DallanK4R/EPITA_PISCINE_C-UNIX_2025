#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list *list_pr(struct list *list, int value)
{
    struct list *k = malloc(sizeof(struct list));
    if (!k)
        return NULL;
    k->data = value;
    if (list == NULL)
        return k;
    k->next = list;
    return k;
}

size_t list_le(struct list *list)
{
    size_t i = 0;
    struct list *l = list;
    while (l)
    {
        l = l->next;
        i++;
    }
    return i;
}

void list_prin(struct list *list)
{
    if (list == NULL)
        return;
    while (list->next)
    {
        printf("%i ", list->data);
        list = list->next;
    }
    printf("%i\n", list->data);
}

void list_de(struct list *list)
{
    struct list *j;
    while (list)
    {
        j = list;
        list = list->next;
        free(j);
    }
}

struct list *list_ap(struct list *list, int value)
{
    struct list *k = malloc(sizeof(struct list));
    if (!k)
        return NULL;
    k->data = value;
    k->next = NULL;
    if (list == NULL)
        return k;
    struct list *l = list;
    while (l->next)
        l = l->next;
    l->next = k;
    return list;
}

struct list *list_sort(struct list *list)
{
    struct list *l = list;
    size_t k = list_le(list);

    for (size_t i = 0; i < k; i++)
    {
        l = list;
        for (size_t j = 0; j < k - 1; j++)
        {
            if (l->next->data < l->data)
            {
                int temp = l->data;
                l->data = l->next->data;
                l->next->data = temp;
            }
            l = l->next;
        }
    }
    return list;
}

struct list *list_reverse(struct list *list)
{
    struct list *l = list;
    size_t len = list_le(list);
    for (size_t i = 0; i < len / 2; i++)
    {
        struct list *l1 = list;
        size_t temp = 0;
        while (temp < len - i - 1)
        {
            l1 = l1->next;
            temp++;
        }
        int jaaj = l1->data;
        l1->data = l->data;
        l->data = jaaj;
        l = l->next;
    }
    return list;
}

struct list *list_split(struct list *list, size_t index)
{
    if (index >= list_le(list) - 1)
        return NULL;
    if (list == NULL)
        return NULL;
    size_t i = 0;
    struct list *l = list;
    while (i < index)
    {
        l = l->next;
        i++;
    }
    struct list *l1 = l->next;
    l->next = NULL;
    return l1;
}
