#include "int_vector_hill.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int int_vector_hill(struct int_vector vec)
{
    if (vec.size == 0)
        return -1;
    int ct = 0;
    if (vec.size == 1)
        return 0;
    for (size_t o = 0; o < vec.size; o++)
    {
        if (vec.data[o] < 0)
            return -1;
    }
    size_t i = 0;
    while (vec.data[i] <= vec.data[i + 1])
    {
        if (vec.data[i] < vec.data[i + 1])
            ct = i + 1;
        if (i == vec.size - 2)
            return ct;
        i++;
    }
    while (vec.data[i] >= vec.data[i + 1])
    {
        if (i == vec.size - 2)
            return ct;
        i++;
    }
    return -1;
}
