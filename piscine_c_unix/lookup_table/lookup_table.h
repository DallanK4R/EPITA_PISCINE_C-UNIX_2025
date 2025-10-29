#ifndef LOOKUP_TABLE_H
#define LOOKUP_TABLE_H

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256]);

#endif /* ! LOOKUP_TABLE_H */
