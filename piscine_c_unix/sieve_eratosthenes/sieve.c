#include "sieve.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int k = i / 2;
        while (k != 1)
        {
            if (i % k == 0)
                break;
            k--;
        }
        if (k == 1)
            printf("%i\n", i);
    }
}
