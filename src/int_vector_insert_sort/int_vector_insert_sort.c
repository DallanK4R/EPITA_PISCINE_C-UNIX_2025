#include "int_vector_insert_sort.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        for (size_t j = 1; j < vec.size; j++)
        {
            if (vec.data[j] < vec.data[j - 1])
                vec = swap(vec, j, j - 1);
        }
    }
    return vec;
}
