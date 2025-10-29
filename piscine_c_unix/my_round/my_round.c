
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_round(float n)
{
    if (n >= 0)
    {
        int value = n;
        if (n - value >= 0.5)
            return n + 1;
        else
            return n;
    }
    else
    {
        int value = n;
        if (n - value <= -0.5)
            return n - 1;
        else
            return n;
    }
}
