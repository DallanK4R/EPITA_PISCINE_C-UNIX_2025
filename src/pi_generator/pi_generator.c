#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

double pi_generator(int precision)
{
    if (precision <= 0)
        return 2.0;

    double temp = 1.0;
    for (int i = precision; i >= 1; --i)
    {
        temp = 1.0 + (i / (2.0 * i + 1.0)) * temp;
    }
    return 2.0 * temp;
}
