#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

int ihp(struct token t1, struct token t2)
{
    if (t1.type == POW)
        return is_higher_precedencepow(t2);
    if (t1.type == MOD)
        return 1;
    if (t1.type >= MULT && t1.type <= DIV)
        return is_higher_precedencemult(t2);
    if (t1.type == SUB)
    {
        if (t2.type == SUB || t2.type == ADD)
            return 1;
        return 0;
    }
    if (t1.type == ADD)
        return 0;
    return 0;
}

int is_higher_precedencepow(struct token t2)
{
    if (t2.type == POW)
        return 0;
    if (t2.type >= MULT && t2.type <= MOD)
        return 1;
    return 1;
}

int is_higher_precedencemult(struct token t2)
{
    if (t2.type == POW)
        return 0;
    if (t2.type >= MULT && t2.type <= MOD)
        return 1;
    return 1;
}
