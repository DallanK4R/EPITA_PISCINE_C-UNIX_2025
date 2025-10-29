#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static void print_node(const struct heap *h, size_t i, int *first)
{
    if (i >= h->size)
        return;
    if (*first)
        *first = 0;
    else
        putchar(' ');
    printf("%d", h->array[i]);
    print_node(h, 2 * i + 1, first);
    print_node(h, 2 * i + 2, first);
}

void print_heap(const struct heap *heap)
{
    int first = 1;
    if (heap && heap->size)
        print_node(heap, 0, &first);
    putchar('\n');
}
