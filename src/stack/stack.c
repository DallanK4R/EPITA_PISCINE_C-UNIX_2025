#include "stack.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *k = malloc(sizeof(struct stack));
    k->data = e;
    k->next = s;
    return k;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *k = s->next;
    free(s);
    return k;
}

int stack_peek(struct stack *s)
{
    return s->data;
}

int main(void)
{}
