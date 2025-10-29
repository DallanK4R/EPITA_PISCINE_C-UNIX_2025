#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = *a + *b;
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = *a - *b;
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL)
        return;
    *a = *a * *b;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return 0;
    int k = *a / *b;
    int reminder = *a % *b;
    *a = k;
    return reminder;
}
