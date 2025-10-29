#include "bubble_sort.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void bubble_sort(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 1; j < size; j++)
        {
            if (array[j - 1] > array[j])
            {
                int o = array[j - 1];
                array[j - 1] = array[j];
                array[j] = o;
            }
        }
    }
}
