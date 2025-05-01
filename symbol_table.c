#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scope {
    SymbolEntry *symbols;
    struct Scope *parent;
} Scope;

static Scope *current_scope = NULL;

void add_symbol(char *name, char *type) {
    // Check if already exists in current scope
    SymbolEntry *entry = current_scope->symbols;
    while (entry) {
        if (strcmp(entry->name, name) == 0) {
            fprintf(stderr, "Semantic error: Redeclaration of '%s'\n", name);
            exit(1);
        }
        entry = entry->next;
    }

    // Add new symbol
    entry = malloc(sizeof(SymbolEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->next = current_scope->symbols;
    current_scope->symbols = entry;
}

SymbolEntry *find_symbol(char *name) {
    Scope *scope = current_scope;
    while (scope) {
        SymbolEntry *entry = scope->symbols;
        while (entry) {
            if (strcmp(entry->name, name) == 0)
                return entry;
            entry = entry->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

void push_scope() {
    Scope *new_scope = malloc(sizeof(Scope));
    new_scope->parent = current_scope;
    new_scope->symbols = NULL;
    current_scope = new_scope;
}

void pop_scope() {
    if (current_scope) {
        Scope *old = current_scope;
        current_scope = current_scope->parent;
        
        // Free all symbols in the scope
        SymbolEntry *entry = old->symbols;
        while (entry) {
            SymbolEntry *next = entry->next;
            free(entry->name);
            free(entry->type);
            free(entry);
            entry = next;
        }
        free(old);
    }
}

void semantic_analysis(ASTNode *node) {
    if (!node) return;
    
    // Process current node
    if (strcmp(node->type, "VAR") == 0) {
        if (!find_symbol(node->value)) {
            fprintf(stderr, "Semantic error: Undeclared variable '%s'\n", node->value);
            exit(1);
        }
    }
    
    // Recursively process children
    semantic_analysis(node->left);
    semantic_analysis(node->right);
    semantic_analysis(node->next);
}