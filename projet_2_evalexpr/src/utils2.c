#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

struct fifo *destroyall_andtransfer(struct fifo *sn, struct stack *operator,
                                    struct fifo * rpn)
{
    rpn = transfer_stack(operator, rpn);
    stack_destroy(operator);
    fifo_destroy(sn);
    return rpn;
}
