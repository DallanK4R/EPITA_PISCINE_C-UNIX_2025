
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned long factorial(unsigned n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
