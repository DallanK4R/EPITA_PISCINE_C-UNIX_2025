#ifndef HEAP_H
#define HEAP_H

// size_t
#include <stddef.h>

struct heap
{
    size_t size;
    size_t capacity;
    int *array;
};

/*
** Create a new heap and initialize it with size equals to 0 and capacity to 8.
** Returns `NULL` if an error occured.
*/
struct heap *create_heap(void);

/**
** Add `val` to the heap.
*/
void add(struct heap *heap, int val);

/*
** Delete the root of the heap.
** If the heap is empty, an assertion stops the program.
** Returns the root element.
*/
int pop(struct heap *heap);

/*
** Remove all elements from the heap and free `heap` structure.
*/
void delete_heap(struct heap *heap);

/*
** Display the elements of `heap` with a pre-order traversal.
*/
void print_heap(const struct heap *heap);

#endif /* ! HEAP_H */
