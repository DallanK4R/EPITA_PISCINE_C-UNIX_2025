#include "insertion_sort.h"

#include <stdlib.h>

void insertion_sort(void **array, f_cmp comp)
{
    if (!*array)
        return;

    for (size_t i = 1; array[i]; ++i)
    {
        void *elt = array[i];
        size_t j = i;
        for (; j > 0 && comp(array[j - 1], elt) > 0; --j)
            array[j] = array[j - 1];
        array[j] = elt;
    }
}
