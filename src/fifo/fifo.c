#include "fifo.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *q = malloc(sizeof(struct fifo));
    if (!q)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *new = malloc(sizeof(struct list));
    if (!new)
        return;
    new->next = NULL;
    new->data = elt;
    if (fifo->tail == NULL)
    {
        fifo->tail = new;
        fifo->head = new;
    }
    else
    {
        fifo->tail->next = new;
        fifo->tail = new;
    }
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    if (fifo->size == 1)
    {
        free(fifo->head);
        fifo->head = NULL;
        fifo->tail = NULL;
    }
    else
    {
        struct list *temp = fifo->head;
        fifo->head = fifo->head->next;
        free(temp);
    }
    fifo->size--;
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size)
    {
        fifo_pop(fifo);
    }
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    if (fifo->size == 0)
        return;
    struct list *new = fifo->head;
    while (new)
    {
        printf("%i\n", new->data);
        new = new->next;
    }
}
