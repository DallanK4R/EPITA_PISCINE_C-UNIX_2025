#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "seiralize.h"

int gtree_serialize(const char *filename, const struct gtree *root)
{
    if (!filename)
        return -1;
    if (*filename == 0)
        return -1;
    if (!root)
        return -1;
    if (!root->child && !root->sibling)
        return -1;
    FILE *f = fopen(filename,"w+");
    if (!f)
        return -1;




}

