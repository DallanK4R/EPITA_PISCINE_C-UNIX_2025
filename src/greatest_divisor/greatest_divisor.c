#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        if (n % i == 0)
            return i;
    }
    return 1;
}
