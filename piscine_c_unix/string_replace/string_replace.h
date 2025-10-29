#ifndef STRING_REPLACE_H
#define STRING_REPLACE_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

char *string_replace(char c, const char *str, const char *pattern);

#endif /* ! STRING_REPLACE_H */
