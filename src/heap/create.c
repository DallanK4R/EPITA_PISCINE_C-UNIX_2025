#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *k = malloc(sizeof(struct heap));
    if (!k)
        return NULL;
    k->size = 0;
    k->capacity = 8;
    k->array = malloc(8 * sizeof(int));
    if (!k->array)
        return NULL;
    return k;
}
