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
    struct list *l = list;
    if (l == NULL)
        return;
    while (l)
    {
        printf("%i", l->data);
        if (l->next)
            putchar(' ');
        l = l->next;
    }
    putchar('\n');
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
