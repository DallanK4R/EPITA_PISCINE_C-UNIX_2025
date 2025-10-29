
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_pow(int a, unsigned long b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return my_pow(a * a, b / 2);
    else
        return a * my_pow(a * a, (b - 1) / 2);
}
