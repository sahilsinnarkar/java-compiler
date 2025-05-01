#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"

typedef struct SymbolEntry {
    char *name;
    char *type;
    struct SymbolEntry *next;
} SymbolEntry;

// Scope management
void push_scope();
void pop_scope();

// Symbol table functions
void add_symbol(char *name, char *type);
SymbolEntry *find_symbol(char *name);

// Semantic analysis
void semantic_analysis(ASTNode *node);

#endif