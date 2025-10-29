#ifndef MY_MEMCPY_H
#define MY_MEMCPY_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n);

#endif /* ! MY_MEMCPY_H */
