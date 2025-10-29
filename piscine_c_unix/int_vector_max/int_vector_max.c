#include "int_vector_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int int_vector_max(const struct int_vector vec)
{
    int cpt = vec.data[0];
    for (size_t i = 0; i < vec.size; i++)
    {
        if (vec.data[i] > cpt)
            cpt = vec.data[i];
    }
    return cpt;
}
