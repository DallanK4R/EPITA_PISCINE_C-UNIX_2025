
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
        return 0;
    int mult = 1;
    for (int j = 0; j < k; j++)
    {
        mult *= 10;
    }
    int faken = n % mult;
    faken /= (mult / 10);
    return faken;
}
