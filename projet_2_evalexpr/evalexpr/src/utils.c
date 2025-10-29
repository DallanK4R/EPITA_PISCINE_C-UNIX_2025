#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexpr.h"

int my_pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return my_pow(a * a, b / 2);
    else
        return a * my_pow(a * a, (b - 1) / 2);
}

struct fifo *transfer_stack(struct stack *operator, struct fifo * rpn)
{
    while (operator->head)
    {
        if (operator->head->token.type == LPAR)
        {
            operator= stack_pop(operator);
            break;
        }
        if (operator->head->token.type != RPAR && operator->head->token
                .type != LPAR)
        {
            rpn = fifo_push(rpn, operator->head->token);
        }
        operator= stack_pop(operator);
    }
    return rpn;
}

struct stack *docalcbinary(struct stack *res, struct token token)
{
    if (!res->head)
        err(2, "uyshrg");
    struct token token1 = res->head->token;
    res = stack_pop(res);
    if (!res->head)
        err(2, "uyshrg");
    struct token token2 = res->head->token;
    res = stack_pop(res);
    struct token result;
    result.type = INT;
    if (token.type == ADD)
        result.data = token2.data + token1.data;
    else if (token.type == SUB)
        result.data = token2.data - token1.data;
    else if (token.type == MULT)
        result.data = token2.data * token1.data;
    else if (token.type == DIV)
    {
        if (token1.data == 0)
            err(3, "bi 0 div");
        result.data = token2.data / token1.data;
    }
    else if (token.type == MOD)
    {
        if (token1.data == 0)
            err(3, "bi 0 div");
        result.data = token2.data % token1.data;
    }
    else if (token.type == POW)
    {
        if (token1.data < 0)
            err(3, "bi neg pow");
        result.data = my_pow(token2.data, token1.data);
    }
    res = stack_push(res, result);
    return res;
}

struct fifo *format_nb(struct fifo *sn, char c, int isclose)
{
    if (sn->tail)
    {
        if (sn->tail->token.type == INT && isclose)
        {
            sn->tail->token.data *= 10;
            sn->tail->token.data += c - '0';
        }
        else
        {
            struct token temp;
            temp.type = INT;
            temp.data = c - '0';
            sn = fifo_push(sn, temp);
        }
    }
    else
    {
        struct token temp;
        temp.type = INT;
        temp.data = c - '0';
        sn = fifo_push(sn, temp);
    }
    return sn;
}

int check_operator_type(struct fifo *sn)
{
    if (sn->tail)
    {
        if (sn->tail->token.type == INT || sn->tail->token.type == RPAR)
            return 0;
        return 1;
    }
    return 1;
}

struct fifo *format_op(struct fifo *sn, char c)
{
    struct token temp;
    temp.data = -1;
    if (c == '-')
    {
        if (check_operator_type(sn))
            temp.type = USUB;
        else
            temp.type = SUB;
    }
    else if (c == '+')
    {
        if (check_operator_type(sn))
            temp.type = UADD;
        else
            temp.type = ADD;
    }
    else if (c == '/')
        temp.type = DIV;
    else if (c == '%')
        temp.type = MOD;
    else if (c == '^')
        temp.type = POW;
    else if (c == '*')
        temp.type = MULT;
    else if (c == '(')
        temp.type = LPAR;
    else if (c == ')')
        temp.type = RPAR;
    sn = fifo_push(sn, temp);
    return sn;
}

int check_operator(char c)
{
    if (c == '-' || c == '+' || c == '/' || c == '%' || c == '^' || c == '*'
        || c == '(' || c == ')')
        return 1;
    return 0;
}

struct fifo *format_op_rpn(struct fifo *sn, char c)
{
    struct token temp;
    temp.data = -1;
    if (c == '-')
        temp.type = SUB;
    else if (c == '+')
        temp.type = ADD;
    else if (c == '/')
        temp.type = DIV;
    else if (c == '%')
        temp.type = MOD;
    else if (c == '^')
        temp.type = POW;
    else if (c == '*')
        temp.type = MULT;
    sn = fifo_push(sn, temp);
    return sn;
}

int donegate(struct token token)
{
    if (token.type == USUB)
        return -1;
    return 1;
}
