#include "my_strstr.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_strstr(const char *haystack, const char *needle)
{
    if (*needle == 0)
        return 0;
    int i = 0;
    int tempi = 0;
    int j = 0;
    while (haystack[i] != 0)
    {
        if (haystack[i] == needle[0])
        {
            j = 0;
            tempi = i;
            while (haystack[tempi] != 0)
            {
                if (needle[j] == 0)
                    return i;
                if (haystack[tempi] != needle[j])
                    break;
                j++;
                tempi++;
            }
        }
        i++;
    }
    if (needle[j] == 0)
        return i - 1;
    return -1;
}
