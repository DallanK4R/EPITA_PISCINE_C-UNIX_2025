#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list *list_prepend(struct list *list, int value)
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

size_t list_length(struct list *list)
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

void list_print(struct list *list)
{
    while (list->next)
    {
        printf("%i ", list->data);
        list = list->next;
    }
    printf("%i\n", list->data);
}

void list_destroy(struct list *list)
{
    struct list *j;
    while (list)
    {
        j = list;
        list = list->next;
        free(j);
    }
}

struct list *list_append(struct list *list, int value)
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
