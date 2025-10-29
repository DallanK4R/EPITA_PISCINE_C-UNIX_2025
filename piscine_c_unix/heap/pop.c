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

int pop(struct heap *heap)
{
    assert(heap);
    assert(heap->size > 0);
    int ret = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    size_t i = 0;
    while (1)
    {
        size_t l = 2 * i + 1;
        size_t r = 2 * i + 2;
        size_t m = i;
        if (l < heap->size && heap->array[l] > heap->array[m])
            m = l;
        if (r < heap->size && heap->array[r] > heap->array[m])
            m = r;
        if (m == i)
            break;
        swap(&heap->array[i], &heap->array[m]);
        i = m;
    }
    if (heap->capacity > 8 && heap->size < heap->capacity / 2)
    {
        size_t nc = heap->capacity / 2;
        if (nc < 8)
            nc = 8;
        int *na = realloc(heap->array, nc * sizeof(int));
        if (na)
        {
            heap->array = na;
            heap->capacity = nc;
        }
    }
    return ret;
}
