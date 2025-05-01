#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"

static ICode *head = NULL, *tail = NULL;
static int temp_cnt = 0;
static int label_cnt = 0;

char *new_label() {
    char buf[16];
    sprintf(buf, "L%d", label_cnt++);
    return strdup(buf);
}

void init_codegen() {
    head = tail = NULL;
    temp_cnt = label_cnt = 0;
}

char *new_temp() {
    char buf[16]; sprintf(buf, "t%d", temp_cnt++);
    return strdup(buf);
}

void emit(const char *op, const char *arg1, const char *arg2, const char *res) {
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
        char *false_label = new_label();
        emit("IF_FALSE", cond, NULL, false_label);
        generate_IC(n->right);  // then block
        emit("LABEL", NULL, NULL, false_label);
    }
    else if (!strcmp(n->type, "IF_ELSE")) {
        char *cond = generate_expr_IC(n->left);
        char *false_label = new_label();
        char *end_label = new_label();
        emit("IF_FALSE", cond, NULL, false_label);
        generate_IC(n->right);  // then block
        emit("GOTO", NULL, NULL, end_label);
        emit("LABEL", NULL, NULL, false_label);
        generate_IC(n->next);   // else block
        emit("LABEL", NULL, NULL, end_label);
    }
    else if (!strcmp(n->type, "WHILE")) {
        char *start_label = new_label();
        char *end_label = new_label();
        emit("LABEL", NULL, NULL, start_label);
        char *cond = generate_expr_IC(n->left);
        emit("IF_FALSE", cond, NULL, end_label);
        generate_IC(n->right);  // loop body
        emit("GOTO", NULL, NULL, start_label);
        emit("LABEL", NULL, NULL, end_label);
    }
    else if (!strcmp(n->type, "RETURN")) {
        char *ret_val = generate_expr_IC(n->left);
        emit("RETURN", ret_val, NULL, NULL);
    }
    else if (!strcmp(n->type, "BLOCK")) {
        generate_IC(n->left);
    }
    else if (!strcmp(n->type, "FOR")) {
        char *start_label = new_label();
        char *end_label = new_label();
        char *incr_label = new_label();
        
        // Initialization
        generate_IC(n->left);
        
        // Start label
        emit("LABEL", NULL, NULL, start_label);
        
        // Condition
        char *cond = generate_expr_IC(n->right->left);
        emit("IF_FALSE", cond, NULL, end_label);
        
        // Body
        generate_IC(n->next);
        
        // Increment label
        emit("LABEL", NULL, NULL, incr_label);
        
        // Increment
        generate_IC(n->right->right);
        
        // Jump back
        emit("GOTO", NULL, NULL, start_label);
        
        // End label
        emit("LABEL", NULL, NULL, end_label);
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
        else if (i->op)
            printf("%s %s\n", i->op, i->result ? i->result : "");
    }
}