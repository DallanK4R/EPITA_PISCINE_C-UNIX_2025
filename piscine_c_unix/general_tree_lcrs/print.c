#include "print.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void gtreepr(const struct gtree *root)
{
    if (root)
    {
        fprintf(stdout, " %i", root->data);
        gtpreepr(root->child);
        gtpreepr(root->sibling);
    }
}

void gtree_print_preorder(const struct gtree *root)
{
    if (root)
        fprintf(stdout, "%i", root->data);
    gtpreepr(root->child);
    gtpreepr(root->sibling);
    if (root)
        fprintf(stdout, "\n");
}
