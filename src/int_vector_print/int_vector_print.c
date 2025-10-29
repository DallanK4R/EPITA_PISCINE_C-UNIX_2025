#include "int_vector_print.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t i = 0;
    while (i < vec.size)
    {
        if (i < vec.size - 1)
            printf("%i ", vec.data[i]);
        else
            printf("%i\n", vec.data[i]);

        i++;
    }
}
