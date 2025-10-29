
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

unsigned int number_digits_rec(unsigned int n)
{
    if (n < 10)
        return 1;
    return 1 + number_digits_rec(n / 10);
}
