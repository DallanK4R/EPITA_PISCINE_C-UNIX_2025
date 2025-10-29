#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "evalexpr.h"

struct stack *stack_init(void)
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
        return NULL;
    s->head = NULL;
    return s;
}

struct stack *stack_push(struct stack *s, struct token token)
{
    if (!s)
        return NULL;
    struct list *l = malloc(sizeof(struct list));
    l->next = NULL;
    l->token = token;
    if (!s->head)
        s->head = l;
    else
    {
        l->next = s->head;
        s->head = l;
    }
    return s;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
        return NULL;
    if (!s->head)
        return NULL;
    struct list *l = s->head->next;
    free(s->head);
    s->head = l;
    return s;
}

void stack_destroy(struct stack *s)
{
    if (s)
    {
        struct list *l = s->head;
        while (l)
        {
            struct list *temp = l;
            l = l->next;
            free(temp);
        }
        free(s);
    }
}

/*

void stack_print(struct stack *s)
{
    if (!s)
        return;
    if (!s->head)
        return;
    struct list *new = s->head;
    while (new)
    {
        printf("%i\n", new->token.data);
        new = new->next;
    }
}

*/
