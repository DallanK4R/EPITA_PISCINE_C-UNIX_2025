#include "vector.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    struct vector *v = malloc(sizeof(struct vector));
    v->data = malloc(sizeof(int) * n);
    v->capacity = n;
    v->size = 0;
    return v;
}

void vector_destroy(struct vector *v)
{
    if (!v)
        return;
    free(v->data);
    free(v);
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (n == 0)
        return vector_resize(v, 1);
    if (n < v->capacity)
    {
        if (v->size > n)
            v->size = n;
        v->capacity = n;
        return v;
    }
    if (n > v->capacity)
    {
        v->data = realloc(v->data, n * sizeof(int));
        if (!v->data)
            return NULL;
    }
    v->capacity = n;
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (!v)
        return NULL;
    if (v->size == v->capacity)
        v = vector_resize(v, v->capacity * 2);
    v->data[v->size] = elt;
    v->size++;
    return v;
}

void vector_print(const struct vector *v)
{
    if (!v)
        return;
    for (size_t i = 0; i < v->size; i++)
    {
        printf("%i", v->data[i]);
        if (i != v->size - 1)
            printf(",");
    }
    printf("\n");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    free(v->data);
    v->size = 0;
    v->data = malloc(sizeof(int) * n);
    v->capacity = n;
    return v;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v)
        return NULL;
    if (i > v->size)
        return NULL;
    if (v->size == i)
        return vector_append(v, elt);
    if (v->size == v->capacity)
    {
        v = vector_resize(v, v->capacity * 2);
        if (v == NULL)
            return NULL;
    }
    for (size_t j = v->size; j > i; j--)
    {
        v->data[j] = v->data[j - 1];
    }
    v->data[i] = elt;
    v->size++;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v)
        return NULL;
    if (i > v->size)
        return NULL;
    if (v->size == i - 1)
    {
        v->size--;
        if (v->size <= v->capacity / 2)
            v = vector_resize(v, v->capacity / 2);
        return v;
    }
    for (size_t j = i; j < v->size; j++)
    {
        v->data[j] = v->data[j + 1];
    }
    v->size--;
    if (v->size <= v->capacity / 2)
        v = vector_resize(v, v->capacity / 2);
    return v;
}
