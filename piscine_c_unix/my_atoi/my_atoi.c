#include "my_atoi.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    int sign = 0;
    int number = 0;
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
            else
                sign = -1;
        }
        else if (str[i] == '+')
            if (sign || number)
                return 0;
            else
                sign = 1;
        else if (str[i] >= '0' && str[i] <= '9')
        {
            if (number)
                res *= 10;
            number = 1;
            res += str[i] - '0';
        }
        else
        {
            return 0;
        }
        i++;
    }

    if (!sign)
        return res;
    else
        return res * sign;
}
