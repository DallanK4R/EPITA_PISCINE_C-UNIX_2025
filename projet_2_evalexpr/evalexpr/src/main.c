#define _POSIX_C_SOURCE 200809
#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

int main(int argc, char *argv[])
{
    if (argc > 2)
        return 4;
    if (argc == 2)
    {
        if (strcmp(argv[1], "-rpn"))
            return 4;
    }
    char *line = NULL;
    size_t j = 0;

    int k = getline(&line, &j, stdin);
    if (k < 0)
    {
        free(line);
        return 4;
    }
    if (k == 0)
    {
        free(line);
        return 0;
    }
    if (!line)
    {
        return 0;
    }
    if (*line == 0 || *line == '\n')
    {
        free(line);
        return 0;
    }
    if (argc == 1)
    {
        struct fifo *sn = format_sn(line);
        free(line);
        struct fifo *rpn = sn_to_rpn(sn);
        int result = rpnevaluate(rpn);
        printf("%i\n", result);
        return 0;
    }
    else
    {
        struct fifo *jaj = format_alrpn(line);
        free(line);
        int res = rpnevaluate(jaj);
        printf("%i\n", res);
        return 0;
    }
}
