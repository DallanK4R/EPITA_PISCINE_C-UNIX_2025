#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif /* ! HEAP_SORT_H */
