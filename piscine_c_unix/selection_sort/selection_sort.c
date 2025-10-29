
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

size_t array_min(const int arr[], size_t start, size_t size)
{
    int min = arr[start];
    size_t mini = start;
    for (size_t k = start + 1; k < size; k++)
    {
        if (arr[k] < min)
        {
            mini = k;
            min = arr[k];
        }
    }
    return mini;
}

void selection_sort(int arr[], size_t size)
{
    size_t li = 0;
    for (size_t i = 0; i < size; i++)
    {
        li = array_min(arr, i, size);
        int temp = arr[i];
        arr[i] = arr[li];
        arr[li] = temp;
    }
}
