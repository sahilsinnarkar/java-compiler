#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"

static ICode *head = NULL, *tail = NULL;
static int temp_cnt = 0;

void init_codegen() {
    head = tail = NULL;
    temp_cnt = 0;
}

char *new_temp() {
    char buf[16]; sprintf(buf, "t%d", temp_cnt++);
    return strdup(buf);
}

void emit(const char *op, const char *arg1,
          const char *arg2, const char *res) {
    ICode *instr = malloc(sizeof(ICode));
    instr->op     = strdup(op);
    instr->arg1   = arg1 ? strdup(arg1) : NULL;
    instr->arg2   = arg2 ? strdup(arg2) : NULL;
    instr->result = res  ? strdup(res)  : NULL;
    instr->next   = NULL;
    if (!head) head = tail = instr;
    else        { tail->next = instr; tail = instr; }
}

char *generate_expr_IC(ASTNode *e) {
    if (!e) return NULL;
    if (!strcmp(e->type, "NUM") || !strcmp(e->type, "FLOAT") || !strcmp(e->type, "VAR")) {
        return strdup(e->value);
    }
    if (!strcmp(e->type, "BIN_OP")) {
        char *l = generate_expr_IC(e->left);
        char *r = generate_expr_IC(e->right);
        char *t = new_temp();
        emit(e->value, l, r, t);
        return t;
    }
    return NULL;
}

void generate_IC(ASTNode *n) {
    if (!n) return;
    
    if (!strcmp(n->type, "ASSIGN")) {
        char *src = generate_expr_IC(n->right);
        emit("=", src, NULL, n->left->value);
    }
    else if (!strcmp(n->type, "IF")) {
        char *cond = generate_expr_IC(n->left);
        emit("IF_FALSE", cond, NULL, "L0");
        generate_IC(n->right);  // then block
        emit("LABEL", NULL, NULL, "L0");
    }
    else if (!strcmp(n->type, "IF_ELSE")) {
        char *cond = generate_expr_IC(n->left);
        emit("IF_FALSE", cond, NULL, "L0");
        generate_IC(n->right);  // then block
        emit("GOTO", NULL, NULL, "L1");
        emit("LABEL", NULL, NULL, "L0");
        generate_IC(n->next);   // else block
        emit("LABEL", NULL, NULL, "L1");
    }
    else if (!strcmp(n->type, "BLOCK")) {
        generate_IC(n->left);  // process statements in block
    }
    
    generate_IC(n->left);
    generate_IC(n->right);
    generate_IC(n->next);
}

void print_IC() {
    for (ICode *i = head; i; i = i->next) {
        if (i->arg2)
            printf("%s = %s %s %s\n", i->result, i->arg1, i->op, i->arg2);
        else if (i->arg1)
            printf("%s %s %s\n", i->op, i->arg1, i->result);
        else
            printf("%s %s\n", i->op, i->result);
    }
}
