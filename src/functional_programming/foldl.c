#include "functional_programming.h"

int foldl(int *array, size_t len, int (*func)(int, int))
{
    if (!len)
        return 0;
    return func(foldl(array, len - 1, func), array[len - 1]);
}
