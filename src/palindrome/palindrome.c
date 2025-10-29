
#include "palindrome.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int isok(char k)
{
    if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z')
        || (k >= '0' && k <= '9'))
        return 1;
    return 0;
}

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    if (s[0] == 0)
        return 1;
    int cpt = 0;
    while (s[cpt] != 0)
    {
        cpt++;
    }
    int l = 0;
    int r = cpt - 1;
    while (l < r)
    {
        while (l < r && !isok(s[l]))
        {
            l++;
        }
        while (l < r && !isok(s[r]))
        {
            r--;
        }
        if (s[l] != s[r])
        {
            return 0;
        }
        l++;
        r--;
    }

    return 1;
}
