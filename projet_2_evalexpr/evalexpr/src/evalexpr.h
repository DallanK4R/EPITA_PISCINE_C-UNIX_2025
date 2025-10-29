#ifndef EVALEXPR_H
#define EVALEXPR_H

#include <assert.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Token

enum token_type
{
    INT, // 0
    UADD, // 1
    USUB, // 2
    POW, // 3
    MULT, // 4
    DIV, // 5
    MOD, // 6
    ADD, // 7
    SUB, // 8
    LPAR, // 9
    RPAR, // 10
};

struct token
{
    enum token_type type;
    int data;
};

// Struct List

struct list
{
    struct token token;
    struct list *next;
};

// Struct Stack

struct stack
{
    struct list *head;
};

struct stack *stack_init(void);
struct stack *stack_push(struct stack *s, struct token token);
struct stack *stack_pop(struct stack *s);
void stack_destroy(struct stack *s);
// void stack_print(struct stack *s);

// Struct Fifo

struct fifo
{
    struct list *head;
    struct list *tail;
    size_t size;
};

struct fifo *fifo_init(void);
struct fifo *fifo_push(struct fifo *fifo, struct token token);
void fifo_pop(struct fifo *fifo);
void fifo_clear(struct fifo *fifo);
void fifo_destroy(struct fifo *fifo);
// void fifo_print(const struct fifo *fifo);

// Functions priority

int ihp(struct token t1, struct token t2);
int is_higher_precedenceu(struct token t2);
int is_higher_precedencepow(struct token t2);
int is_higher_precedencemult(struct token t2);

// Utils functions

int my_pow(int a, int b);
struct fifo *transfer_stack(struct stack *operator, struct fifo * rpn);
struct stack *docalcbinary(struct stack *res, struct token token);
int check_operator(char c);
struct fifo *format_nb(struct fifo *sn, char c, int isclose);
int check_operator_type(struct fifo *sn);
struct fifo *format_op(struct fifo *sn, char c);
struct fifo *format_op_rpn(struct fifo *sn, char c);
int donegate(struct token token);

// Utils functions 2

struct fifo *destroyall_andtransfer(struct fifo *sn, struct stack *operator,
                                    struct fifo * rpn);

// Main functions

int rpnevaluate(struct fifo *rpn);
struct fifo *sn_to_rpn(struct fifo *sn);
struct fifo *format_sn(char *s);
struct fifo *format_alrpn(char *s);

#endif /* ! EVALEXPR_H */
