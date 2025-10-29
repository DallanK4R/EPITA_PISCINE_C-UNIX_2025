#include "gtree.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct gtree *gtree_create_node(char data)
{
    struct gtree *k = malloc(sizeof(struct gtree));
    if (!k)
        return NULL;
    k->data = data;
    k->sibling = NULL;
    k->child = NULL;
    return k;
}

int gtree_add_child(struct gtree *parent, struct gtree *child)
{
    if (!child || !parent)
        return 0;
    parent->child;
    return 1;
}

struct gtree *gtree_search_node(struct gtree *root, const char data)
{
    if (root)
    {
        if (root->data = data)
            return root;
        else if (gtree_search_node(root->sibling, data)->data == data)
            return gtree_search_node(root->sibling, data);
        else if (gtree_search_node(root->parent, data)->data == data)
            return gtree_search_node(root->parent, data);
        else
            return NULL;
    }
    return NULL;
}

void gtree_free(struct gtree *root)
{
    if (!root)
        return;
    if (root->child)
        gtree_free(root->child);
    if (root->sibling)
        gtree_free(root->sibling);
    free(root);
}

int gtreeaux(struct gtree *root, const char data)
{}

int gtree_del_node(struct gtree *root, const char data)
{
    if (root->data == data)
        return -1;
    if (root->children)
    {
        if (root->children->data == data)
        {
            struct gtree *temp = root->children;
            root->children = root->sibling;
            gtree_free(temp->children);
            free(temp);
            return 1;
        }
        else
        {
            if (gtree_del_node(root->children))
                return 1;
        }
    }
    if (root->sibling)
    {
        if (root->sibling->data == data)
        {
            struct gtree *temp = root->sibling;
            root->sibling = temp->sibling;
            gtree_free(temp->children);
            free(temp);
            return 1;
        }
        else
        {
            if (gtree_del_node(root->sibling))
                return 1;
        }
    }
    if (!root->child && !root->sibling)
        return 0;
}
