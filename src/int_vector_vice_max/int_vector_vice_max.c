#include "int_vector_vice_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max;
    int vmax;
    if (vec.data[0] >= vec.data[1])
    {
        max = vec.data[0];
        vmax = vec.data[1];
    }
    else
    {
        max = vec.data[1];
        vmax = vec.data[0];
    }
    for (size_t i = 2; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            vmax = max;
            max = vec.data[i];
        }
        if (vec.data[i] < max && vec.data[i] > vmax)
            vmax = vec.data[i];
    }
    return vmax;
}
