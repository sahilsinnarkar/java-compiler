%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *type;
    char *value;
    char *dataType;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
} ASTNode;

typedef struct SymbolEntry {
    char *name;
    char *type;
    struct SymbolEntry *next;
} SymbolEntry;

typedef struct SymbolTable {
    SymbolEntry *entries;
    struct SymbolTable *parent;
} SymbolTable;

SymbolTable *current_scope = NULL;
ASTNode *root = NULL;

void push_scope();
void pop_scope();
void add_symbol(char *name, char *type);
SymbolEntry *find_symbol(char *name);
void semantic_analysis(ASTNode *node);
char* get_expr_type(ASTNode *expr);

ASTNode* createNode(char *type, char *value, ASTNode *left, ASTNode *right, ASTNode *next) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->dataType = NULL;
    node->left = left;
    node->right = right;
    node->next = next;
    return node;
}

void printAST(ASTNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s", node->type);
    if (node->value) printf(" (%s)", node->value);
    if (node->dataType) printf(" [%s]", node->dataType);
    printf("\n");
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
    printAST(node->next, level);
}

extern int yylineno;
extern char *yytext;
void yyerror(const char *s);
int yylex();
%}

%union {
    int ival;
    double dval;
    char *sval;
    struct ASTNode *node;
}

%token INT FLOAT IF ELSE SWITCH CASE DEFAULT FOR WHILE DO BREAK CONTINUE
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON ASSIGN COLON
%token GT LT EQ NE
%token <ival> NUMBER
%token <dval> FLOAT_NUM
%token <sval> IDENTIFIER
%token END
%token PLUS

%type <node> program stmt_list stmt declaration expr condition if_stmt block assignment

%%

program:
    stmt_list END { 
        printf("Parsing completed successfully\n");
        root = $1; 
        $$ = $1; 
    }
    | error { 
        yyerror("syntax error"); 
        YYABORT; 
    }
    ;

stmt_list:
    stmt_list stmt { 
        ASTNode *list = $1;
        while (list->next) list = list->next;
        list->next = $2;
        $$ = $1;
    }
    | stmt { $$ = createNode("STMT_LIST", NULL, $1, NULL, NULL); }
    | /* empty */ { $$ = createNode("EMPTY_STMT", NULL, NULL, NULL, NULL); }
    ;

stmt:
    declaration
    | if_stmt
    | assignment
    | block
    ;

declaration:
    INT IDENTIFIER SEMICOLON {
        $$ = createNode("DECLARATION", $2, createNode("TYPE", "int", NULL, NULL, NULL), NULL, NULL);
    }
    | FLOAT IDENTIFIER SEMICOLON {
        $$ = createNode("DECLARATION", $2, createNode("TYPE", "float", NULL, NULL, NULL), NULL, NULL);
    }
    ;

assignment:
    IDENTIFIER ASSIGN expr SEMICOLON {
        $$ = createNode("ASSIGN", NULL, 
            createNode("VAR", $1, NULL, NULL, NULL), 
            $3, NULL);
    }
    ;

expr:
    NUMBER {
        char num[20]; sprintf(num, "%d", $1);
        $$ = createNode("NUM", num, NULL, NULL, NULL);
        $$->dataType = "int";
    }
    | FLOAT_NUM {
        char num[20]; sprintf(num, "%.2f", $1);
        $$ = createNode("FLOAT", num, NULL, NULL, NULL);
        $$->dataType = "float";
    }
    | IDENTIFIER {
        $$ = createNode("VAR", $1, NULL, NULL, NULL);
    }
    | expr PLUS expr { $$ = createNode("BIN_OP", "+", $1, $3, NULL); }
    | expr GT expr { $$ = createNode("CONDITION", ">", $1, $3, NULL); }
    ;

if_stmt:
    IF LPAREN condition RPAREN block {
        $$ = createNode("IF", NULL, $3, $5, NULL);
    }
    | IF LPAREN condition RPAREN block ELSE block {
        $$ = createNode("IF_ELSE", NULL, $3, $5, $7);
    }
    ;

block:
    LBRACE stmt_list RBRACE {
        $$ = createNode("BLOCK", NULL, $2, NULL, NULL);
    }
    ;

condition:
    expr { $$ = $1; }
    ;

%%

void push_scope() {
    SymbolTable *new_scope = malloc(sizeof(SymbolTable));
    new_scope->entries = NULL;
    new_scope->parent = current_scope;
    current_scope = new_scope;
}

void pop_scope() {
    if (current_scope) {
        SymbolTable *old = current_scope;
        current_scope = current_scope->parent;
        SymbolEntry *entry = old->entries;
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

void add_symbol(char *name, char *type) {
    SymbolEntry *entry = malloc(sizeof(SymbolEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->next = current_scope->entries;
    current_scope->entries = entry;
}

SymbolEntry *find_symbol(char *name) {
    SymbolTable *scope = current_scope;
    while (scope) {
        SymbolEntry *entry = scope->entries;
        while (entry) {
            if (strcmp(entry->name, name) == 0) return entry;
            entry = entry->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

void semantic_analysis(ASTNode *node) {
    if (!node) return;

    if (strcmp(node->type, "DECLARATION") == 0) {
        char *name = node->value;
        char *type = node->left->value;
        
        if (find_symbol(name)) {
            fprintf(stderr, "Error: '%s' redeclared\n", name);
            exit(1);
        }
        add_symbol(name, type);
    }
    else if (strcmp(node->type, "ASSIGN") == 0) {
        ASTNode *var = node->left;
        ASTNode *expr = node->right;
        
        SymbolEntry *entry = find_symbol(var->value);
        if (!entry) {
            fprintf(stderr, "Error: '%s' undeclared\n", var->value);
            exit(1);
        }
        
        char *exprType = get_expr_type(expr);
        if (strcmp(entry->type, exprType) != 0) {
            fprintf(stderr, "Type error: %s vs %s\n", entry->type, exprType);
            exit(1);
        }
    }
    else if (strcmp(node->type, "BLOCK") == 0) {
        push_scope();
        semantic_analysis(node->left);
        pop_scope();
    }
    else {
        semantic_analysis(node->left);
        semantic_analysis(node->right);
        semantic_analysis(node->next);
    }
}

char* get_expr_type(ASTNode *expr) {
    if (!expr) return NULL;
    
    if (strcmp(expr->type, "VAR") == 0) {
        SymbolEntry *entry = find_symbol(expr->value);
        if (!entry) {
            fprintf(stderr, "Error: '%s' undeclared\n", expr->value);
            exit(1);
        }
        return entry->type;
    }
    else if (strcmp(expr->type, "NUM") == 0) return "int";
    else if (strcmp(expr->type, "FLOAT") == 0) return "float";
    else if (strcmp(expr->type, "CONDITION") == 0) return "bool";
    
    return NULL;
}

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\nToken: '%s'\n", 
            yylineno, s, yytext);
}

int main() {
    printf("Enter code (Ctrl+D to end):\n");
    push_scope();
    if (yyparse() == 0) {
        printf("\nAST:\n");
        printAST(root, 0);
        semantic_analysis(root);
        printf("Semantic analysis passed\n");
    }
    pop_scope();
    return 0;
}