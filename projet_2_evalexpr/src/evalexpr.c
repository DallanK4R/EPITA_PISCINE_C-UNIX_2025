#include "evalexpr.h"

#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rpnevaluate(struct fifo *rpn)
{
    struct stack *res = stack_init();
    if (!res)
        err(2, "probleme de jajuer");
    while (rpn->head)
    {
        if (rpn->head->token.type >= POW && rpn->head->token.type <= SUB)
        {
            res = docalcbinary(res, rpn->head->token);
            if (!res)
                err(2, "probleme de jajuer2");
        }
        else if (rpn->head->token.type == INT)
        {
            res = stack_push(res, rpn->head->token);
            if (!res)
                err(2, "probleme de jajuer3");
        }
        fifo_pop(rpn);
    }
    int finaldata = res->head->token.data;
    stack_pop(res);
    if (res->head)
        err(2, "probleme de jajuer4");
    fifo_destroy(rpn);
    stack_destroy(res);
    return finaldata;
}

struct fifo *sn_to_rpn(struct fifo *sn)
{
    struct fifo *rpn = fifo_init();
    struct stack *operator= stack_init();
    int negate = 1;
    struct token oldt = sn->head->token;
    while (sn->head)
    {
        negate *= donegate(sn->head->token);
        if (sn->head->token.type == INT)
        {
            sn->head->token.data *= negate;
            negate = 1;
            rpn = fifo_push(rpn, sn->head->token);
        }
        else if (sn->head->token.type >= POW && sn->head->token.type <= SUB)
        {
            if (operator->head)
            {
                while (operator->head)
                {
                    if (ihp(operator->head->token, sn->head->token) > 0)
                    {
                        rpn = fifo_push(rpn, operator->head->token);
                        operator= stack_pop(operator);
                    }
                    else
                        break;
                }
            }
            operator= stack_push(operator, sn->head->token);
        }
        else if (sn->head->token.type == RPAR)
        {
            operator= stack_push(operator, sn->head->token);
            rpn = transfer_stack(operator, rpn);
        }
        else if (sn->head->token.type == LPAR)
        {
            if (oldt.type == INT)
                err(2, "paspossbile la parenthese wsh tfk");
            operator= stack_push(operator, sn->head->token);
        }
        oldt = sn->head->token;
        fifo_pop(sn);
    }
    return destroyall_andtransfer(sn, operator, rpn);
}

struct fifo *format_sn(char *s)
{
    int i = 0;
    struct fifo *sn = fifo_init();
    int isclose = 0;
    while (s[i])
    {
        if (!isspace(s[i]))
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                sn = format_nb(sn, s[i], isclose);
                isclose = 1;
            }
            else if (check_operator(s[i]))
            {
                sn = format_op(sn, s[i]);
                isclose = 0;
            }
            else
                err(1, "problemjijou");
        }
        else
        {
            isclose = 0;
        }
        i++;
    }
    return sn;
}

struct fifo *format_alrpn(char *s)
{
    int i = 0;
    struct fifo *sn = fifo_init();
    int isclose = 0;
    while (s[i])
    {
        if (!isspace(s[i]))
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                sn = format_nb(sn, s[i], isclose);
                isclose = 1;
            }
            else if (check_operator(s[i]))
            {
                sn = format_op_rpn(sn, s[i]);
                isclose = 0;
            }
            else
                err(1, "problejijou");
        }
        else
        {
            isclose = 0;
        }
        i++;
    }
    return sn;
}
