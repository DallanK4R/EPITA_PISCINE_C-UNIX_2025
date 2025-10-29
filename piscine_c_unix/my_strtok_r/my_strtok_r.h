#ifndef MY_STRTOK_R_H
#define MY_STRTOK_R_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr);

#endif /* ! MY_STRTOK_R_H */
