#include "malloc_tuto.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *create_array(size_t size)
{
    int *arr = malloc(sizeof(int) * size);
    if (!arr)
        return NULL;
    return arr;
}

void free_array(int *arr)
{
    if (!arr)
        return;
    free(arr);
}

void read_and_inc(int *v)
{
    if (!v)
        return;
    printf("%i", *v);
    *v += 1;
}

char *my_strdup(const char *str)
{
    if (!str)
        return NULL;
    size_t c = 1;
    while (str[c - 1])
    {
        c++;
    }
    char *j = malloc(sizeof(char) * c);
    if (!j)
        return NULL;
    memcpy(j, str, c);
    *(j + c - 1) = 0;
    return j;
}

char *my_strndup(const char *str, size_t n)
{
    if (!str)
        return NULL;
    char *new = malloc(sizeof(char) * (n + 1));
    if (!new)
        return NULL;
    size_t i = 0;
    for (; i < n && str[i] != 0; i++)
    {
        new[i] = str[i];
    }
    new[i] = 0;
    return new;
}
