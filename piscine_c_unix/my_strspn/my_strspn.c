#include "my_strspn.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t count = 0;
    while (s[count])
    {
        int i = 0;
        while (1)
        {
            if (accept[i] == 0)
                return count;
            if (s[count] == accept[i])
                break;
            i++;
        }
        count++;
    }
    return count;
}
