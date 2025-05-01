#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Scope {
    SymbolEntry *symbols;
    struct Scope *parent;
    int is_function_scope;
} Scope;

static Scope *current_scope = NULL;
static char *current_function_type = NULL;

// Helper function to check type compatibility
static int types_compatible(const char *type1, const char *type2) {
    if (!type1 || !type2) return 0;
    if (strcmp(type1, type2) == 0) return 1;
    
    // Allow some implicit conversions
    if (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0) return 1;
    if (strcmp(type1, "char") == 0 && strcmp(type2, "int") == 0) return 1;
    
    return 0;
}

char* get_expression_type(ASTNode *node) {
    if (!node) return NULL;
    
    if (strcmp(node->type, "VAR") == 0) {
        SymbolEntry *entry = find_symbol(node->value);
        return entry ? strdup(entry->type) : NULL;
    }
    else if (strcmp(node->type, "NUM") == 0) return strdup("int");
    else if (strcmp(node->type, "FLOAT") == 0) return strdup("float");
    else if (strcmp(node->type, "CHAR") == 0) return strdup("char");
    else if (strcmp(node->type, "BOOL") == 0) return strdup("bool");
    else if (strcmp(node->type, "BIN_OP") == 0) {
        char *ltype = get_expression_type(node->left);
        char *rtype = get_expression_type(node->right);
        
        if (!ltype || !rtype) {
            free(ltype);
            free(rtype);
            return NULL;
        }
        
        // Check operator-specific type rules
        if (strcmp(node->value, "+") == 0 || strcmp(node->value, "-") == 0) {
            if (strcmp(ltype, "bool") == 0 || strcmp(rtype, "bool") == 0) {
                fprintf(stderr, "Semantic error: Arithmetic on bool values\n");
                free(ltype);
                free(rtype);
                return NULL;
            }
        }
        
        char *result_type = types_compatible(ltype, rtype) ? strdup(ltype) : NULL;
        free(ltype);
        free(rtype);
        return result_type;
    }
    else if (strcmp(node->type, "FUNC_CALL") == 0) {
        SymbolEntry *func = find_symbol(node->value);
        if (!func) {
            fprintf(stderr, "Semantic error: Undefined function '%s'\n", node->value);
            return NULL;
        }
        return strdup(func->type);
    }
    return NULL;
}

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

void push_scope(int is_function) {
    Scope *new_scope = malloc(sizeof(Scope));
    new_scope->parent = current_scope;
    new_scope->symbols = NULL;
    new_scope->is_function_scope = is_function;
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
        
        if (old->is_function_scope && current_function_type) {
            free(current_function_type);
            current_function_type = NULL;
        }
        
        free(old);
    }
}

void check_assignment(ASTNode *target, ASTNode *value) {
    char *target_type = get_expression_type(target);
    char *value_type = get_expression_type(value);
    
    if (!target_type || !value_type) {
        fprintf(stderr, "Semantic error: Invalid types in assignment\n");
        exit(1);
    }
    
    if (!types_compatible(target_type, value_type)) {
        fprintf(stderr, "Semantic error: Type mismatch in assignment (%s vs %s)\n",
                target_type, value_type);
        exit(1);
    }
    
    free(target_type);
    free(value_type);
}

void check_return_type(ASTNode *expr) {
    if (!current_function_type) return;
    
    if (strcmp(current_function_type, "void") == 0 && expr) {
        fprintf(stderr, "Semantic error: Void function returning a value\n");
        exit(1);
    }
    
    if (expr) {
        char *return_type = get_expression_type(expr);
        if (!return_type || !types_compatible(current_function_type, return_type)) {
            fprintf(stderr, "Semantic error: Return type mismatch (%s expected, got %s)\n",
                    current_function_type, return_type ? return_type : "unknown");
            exit(1);
        }
        free(return_type);
    }
}

void semantic_analysis(ASTNode *node) {
    if (!node) return;
    
    if (strcmp(node->type, "VAR") == 0) {
        if (!find_symbol(node->value)) {
            fprintf(stderr, "Semantic error: Undeclared variable '%s'\n", node->value);
            exit(1);
        }
    }
    else if (strcmp(node->type, "ASSIGN") == 0) {
        check_assignment(node->left, node->right);
    }
    else if (strcmp(node->type, "FUNCTION") == 0) {
        current_function_type = strdup(node->right->value);
        push_scope(1);  // Function scope
    }
    else if (strcmp(node->type, "RETURN") == 0) {
        check_return_type(node->left);
    }
    else if (strcmp(node->type, "FUNC_CALL") == 0) {
        // TODO: Add parameter type checking
        if (!find_symbol(node->value)) {
            fprintf(stderr, "Semantic error: Undefined function '%s'\n", node->value);
            exit(1);
        }
    }
    
    // Recursively process children
    semantic_analysis(node->left);
    semantic_analysis(node->right);
    semantic_analysis(node->next);
}