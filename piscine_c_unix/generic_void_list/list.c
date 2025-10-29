#include "list.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    if (!value || data_size == 0)
        return NULL;

    struct list *node = malloc(sizeof(*node));
    if (!node)
        return NULL;

    node->data = malloc(data_size);
    if (!node->data)
    {
        free(node);
        return NULL;
    }

    memcpy(node->data, value, data_size);
    node->next = list;
    return node;
}

size_t list_length(struct list *list)
{
    size_t n = 0;
    while (list)
    {
        n++;
        list = list->next;
    }
    return n;
}

void list_destroy(struct list *list)
{
    while (list)
    {
        struct list *next = list->next;
        free(list->data);
        free(list);
        list = next;
    }
}
