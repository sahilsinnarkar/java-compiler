#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"

typedef struct ICode {
    char *op, *arg1, *arg2, *result;
    struct ICode *next;
} ICode;

void init_codegen();
char *new_temp();
void emit(const char *op, const char *arg1,
          const char *arg2, const char *res);
char *generate_expr_IC(ASTNode *e);
void generate_IC(ASTNode *n);
void print_IC();

#endif