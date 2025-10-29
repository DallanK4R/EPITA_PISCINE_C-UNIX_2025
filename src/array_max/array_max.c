#include "array_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

int array_max(const int array[], size_t size)
{
    if (size == 0)
        return INT_MIN;
    int k = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    return k;
}
