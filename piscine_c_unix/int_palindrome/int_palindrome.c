
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    if (n < 10)
        return 1;
    int r = 0;
    int t = n;
    while (t != 0)
    {
        r = (r * 10) + (t % 10);
        t = t / 10;
    }
    if (r == n)
        return 1;
    else
        return 0;
}
