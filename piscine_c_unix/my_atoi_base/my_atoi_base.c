#include "my_atoi_base.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_len(const char *s)
{
    int cpt = 0;
    while (s[cpt])
    {
        cpt++;
    }
    return cpt;
}

int findi(const char c, const char *base)
{
    int i = 0;
    while (base[i])
    {
        if (c == base[i])
            return i;

        i++;
    }
    return -1;
}

int my_atoi_base(const char *str, const char *base)
{
    int lb = my_len(base);
    int i = 0;
    int sign = 0;
    int number = 0;
    int res = 0;
    while (str[i] != 0)
    {
        if (str[i] == ' ')
        {
            if (sign || number)
                return 0;
        }
        else if (str[i] == '-')
        {
            if (sign || number)
                return 0;
            sign = -1;
        }
        else if (str[i] == '+')
        {
            if (sign || number)
                return 0;
            sign = 1;
        }
        else if (findi(str[i], base) != -1)
        {
            if (number)
                res *= lb;
            int ind = findi(str[i], base);
            if (ind == -1)
                return 0;
            res += ind;
            number = 1;
        }
        else
        {
            return 0;
        }
        i++;
    }
    return !sign ? res : res * sign;
}
