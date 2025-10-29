#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void add(struct heap *heap, int val)
{
    if (heap->size == heap->capacity)
    {
        size_t nc = heap->capacity * 2;
        int *na = realloc(heap->array, nc * sizeof(int));
        if (!na)
            return;
        heap->array = na;
        heap->capacity = nc;
    }
    size_t i = heap->size++;
    heap->array[i] = val;
    while (i > 0)
    {
        size_t p = (i - 1) / 2;
        if (heap->array[p] >= heap->array[i])
            break;
        swap(&heap->array[p], &heap->array[i]);
        i = p;
    }
}
