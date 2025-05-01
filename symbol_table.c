#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"  // this already includes SymbolEntry struct

SymbolEntry *symbolTable = NULL;

void add_symbol(char *name, char *type) {
    SymbolEntry *entry = malloc(sizeof(SymbolEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->next = symbolTable;
    symbolTable = entry;
}

SymbolEntry *find_symbol(char *name) {
    SymbolEntry *current = symbolTable;
    while (current) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
