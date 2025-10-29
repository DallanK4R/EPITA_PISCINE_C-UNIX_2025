
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_abs(int n)
{
    return n < 0 ? -n : n;
}
