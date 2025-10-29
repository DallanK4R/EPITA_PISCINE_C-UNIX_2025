#include "heap_sort.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

static void jaaj(int *a, size_t start, size_t end)
{
    size_t r = start;
    while (2 * r + 1 < end)
    {
        size_t child = 2 * r + 1;
        if (child + 1 < end && a[child] < a[child + 1])
            child++;
        if (a[r] < a[child])
        {
            swap(&a[r], &a[child]);
            r = child;
        }
        else
            return;
    }
}

void heapify(int *array, size_t size)
{
    if (size < 2)
        return;
    for (size_t i = (size - 2) / 2 + 1; i-- > 0;)
        jaaj(array, i, size);
}

void heap_sort(int *array, size_t size)
{
    if (size < 2)
        return;
    heapify(array, size);
    for (size_t end = size; end > 1; end--)
    {
        swap(&array[0], &array[end - 1]);
        jaaj(array, 0, end - 1);
    }
}
