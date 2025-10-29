#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void delete_heap(struct heap *heap)
{
    if (!heap)
        return;
    free(heap->array);
    free(heap);
}
