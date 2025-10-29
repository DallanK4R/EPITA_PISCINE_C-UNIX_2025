#include "check_alphabet.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
        return 1;
    int i = 0;
    while (*(alphabet + i) != 0)
    {
        int j = 0;
        while (*(str + j) != 0)
        {
            if (*(alphabet + i) == *(str + j))
                break;
            j++;
        }
        if (*(str + j) == 0)
            return 0;
        i++;
    }
    return 1;
}
