#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list *list_pre(struct list *list, int value)
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

size_t list_len(struct list *list)
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

void list_pri(struct list *list)
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

void list_des(struct list *list)
{
    struct list *j;
    while (list)
    {
        j = list;
        list = list->next;
        free(j);
    }
}

struct list *list_app(struct list *list, int value)
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

struct list *list_insert(struct list *list, int value, size_t index)
{
    if (index >= list_len(list))
        return list_app(list, value);
    if (index == 0)
        return list_pre(list, value);
    struct list *j = malloc(sizeof(struct list));
    if (!j)
        return NULL;
    j->data = value;
    if (list == NULL)
        return j;
    struct list *l = list;
    size_t i = 0;
    while (i < index - 1)
    {
        l = l->next;
        i++;
    }
    struct list *k = l->next;
    l->next = j;
    j->next = k;
    return list;
}

struct list *list_remove(struct list *list, size_t index)
{
    if (index >= list_len(list))
        return list;
    if (list == NULL)
        return NULL;
    if (index == 0)
    {
        struct list *op = list->next;
        free(list);
        return op;
    }
    struct list *l = list;
    size_t i = 0;
    while (i < index - 1)
    {
        l = l->next;
        i++;
    }
    struct list *k = l->next->next;
    free(l->next);
    l->next = k;
    return list;
}

int list_find(struct list *list, int value)
{
    int i = 0;
    struct list *l = list;
    while (l)
    {
        if (l->data == value)
            return i;
        l = l->next;
        i++;
    }
    return -1;
}

struct list *list_concat(struct list *list, struct list *list2)
{
    if (list == NULL)
        return list2;
    if (list2 == NULL)
        return list;
    struct list *l = list;
    while (l->next)
    {
        l = l->next;
    }
    l->next = list2;
    return list;
}
