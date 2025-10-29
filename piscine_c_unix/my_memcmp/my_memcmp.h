#ifndef MY_MEMCMP_H
#define MY_MEMCMP_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int my_memcmp(const void *s1, const void *s2, size_t num);

#endif /* ! MY_MEMCMP_H */
