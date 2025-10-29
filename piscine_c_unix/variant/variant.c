#include "variant.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void variant_display(const struct variant *e)
{
    if (!e)
        return;
    if (e->type == TYPE_INT)
        printf("%i\n", e->value.int_v);
    if (e->type == TYPE_FLOAT)
        printf("%f\n", e->value.float_v);
    if (e->type == TYPE_CHAR)
        printf("%c\n", e->value.char_v);
    if (e->type == TYPE_STRING)
        printf("%s\n", e->value.str_v);
}

bool variant_equal(const struct variant *left, const struct variant *right)
{
    if (!left && !right)
        return true;
    if (!left || !right)
        return false;
    if (left->type != right->type)
        return false;
    if (left->type == TYPE_INT)
        return left->value.int_v == right->value.int_v;
    if (left->type == TYPE_FLOAT)
        return left->value.float_v == right->value.float_v;
    if (left->type == TYPE_CHAR)
        return left->value.char_v == right->value.char_v;
    if (left->type == TYPE_STRING)
    {
        if (strcmp(left->value.str_v, right->value.str_v) == 0)
            return true;
        return false;
    }
    return true;
}

int variant_find(const struct variant *array, size_t len, enum type type,
                 union type_any value)
{
    if (!array)
        return 0;
    for (size_t k = 0; k < len; k++)
    {
        if (array[k].type == type)
        {
            if (array[k].type == TYPE_INT)
                if (array[k].value.int_v == value.int_v)
                    return k;
            if (array[k].type == TYPE_FLOAT)
                if (array[k].value.float_v == value.float_v)
                    return k;
            if (array[k].type == TYPE_CHAR)
                if (array[k].value.char_v == value.char_v)
                    return k;
            if (array[k].type == TYPE_STRING)
            {
                if (strcmp(array[k].value.str_v, value.str_v) == 0)
                    return k;
            }
        }
    }
    return -1;
}

float variant_sum(const struct variant *array, size_t len)
{
    float res = 0.0;
    for (size_t k = 0; k < len; k++)
    {
        if (array[k].type == TYPE_INT)
            res += array[k].value.int_v;
        if (array[k].type == TYPE_FLOAT)
            res += array[k].value.float_v;
    }
    return res;
}
