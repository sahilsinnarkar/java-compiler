#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct SymbolEntry {
    char *name;
    char *type;
    struct SymbolEntry *next;
} SymbolEntry;

void add_symbol(char *name, char *type);
SymbolEntry *find_symbol(char *name);

#endif
