
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int int_sqrt(int n)
{
    if (n < 0)
        return -1;
    if (n == 1)
        return 1;
    int jaaj = 0;
    for (int k = 0; k < n; k++)
    {
        if (k * k > n)
            break;
        jaaj = k;
    }

    return jaaj;
}
