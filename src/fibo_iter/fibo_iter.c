
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    unsigned long a = 0;
    unsigned long b = 1;
    unsigned long c = 1;
    for (unsigned long i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
