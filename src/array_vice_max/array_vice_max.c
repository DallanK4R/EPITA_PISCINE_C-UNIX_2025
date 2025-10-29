#include "array_vice_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int array_vice_max(const int vec[], size_t size)
{
    int max;
    int vmax;
    if (vec[0] >= vec[1])
    {
        max = vec[0];
        vmax = vec[1];
    }
    else
    {
        max = vec[1];
        vmax = vec[0];
    }
    for (size_t i = 2; i < size; i++)
    {
        if (vec[i] > max)
        {
            vmax = max;
            max = vec[i];
        }
        if (vec[i] < max && vec[i] > vmax)
            vmax = vec[i];
    }
    return vmax;
}
