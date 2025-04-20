%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "codegen.h"

    extern int yylineno;
    extern char *yytext;
    void yyerror(const char *s);
    int yylex();

    /* symbol table & semantic */
    void push_scope();
    void pop_scope();
    void add_symbol(char *name, char *type);
    struct SymbolEntry *find_symbol(char *name);
    void semantic_analysis(ASTNode *node);
    char* get_expr_type(ASTNode *expr);

    ASTNode *root;

    int yydebug = 0;
%}

/* Ensure ASTNode is known in generated header */
%code requires {
    #include "ast.h"
}

%union {
    int ival;
    double dval;
    char *sval;
    ASTNode *node;
}

%token <ival>    NUMBER
%token <dval>    FLOAT_NUM
%token <sval>    IDENTIFIER
%token           IF ELSE
%token           INT FLOAT
%token           LBRACE RBRACE LPAREN RPAREN SEMICOLON ASSIGN GT PLUS
%token           END

%type <node> program stmt_list stmt declaration assignment expr condition if_stmt block

%%

program:
    stmt_list END {
        root = $1;
        printf("Parsing completed successfully\n");
    }
  | error {
        yyerror("syntax error");
        YYABORT;
    }
;

stmt_list:
    stmt_list stmt {
        ASTNode *t = $1;
        while (t->next) t = t->next;
        t->next = $2;
        $$ = $1;
    }
  | stmt {
        $$ = createNode("STMT_LIST", NULL, $1, NULL, NULL);
    }
  | /* empty */ {
        $$ = createNode("EMPTY_STMT", NULL, NULL, NULL, NULL);
    }
;

stmt:
    declaration
  | if_stmt
  | assignment
  | block
;

declaration:
    INT IDENTIFIER SEMICOLON {
        $$ = createNode("DECL", $2,
                          createNode("TYPE","int",NULL,NULL,NULL),
                          NULL, NULL);
    }
  | FLOAT IDENTIFIER SEMICOLON {
        $$ = createNode("DECL", $2,
                          createNode("TYPE","float",NULL,NULL,NULL),
                          NULL, NULL);
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
        char buf[32]; sprintf(buf, "%d", $1);
        $$ = createNode("NUM", buf, NULL, NULL, NULL);
        $$->dataType = strdup("int");
    }
  | FLOAT_NUM {
        char buf[32]; sprintf(buf, "%.2f", $1);
        $$ = createNode("FLOAT", buf, NULL, NULL, NULL);
        $$->dataType = strdup("float");
    }
  | IDENTIFIER {
        $$ = createNode("VAR", $1, NULL, NULL, NULL);
    }
  | expr PLUS expr {
        $$ = createNode("BIN_OP", "+", $1, $3, NULL);
    }
  | expr GT expr {
        $$ = createNode("BIN_OP", ">", $1, $3, NULL);
    }
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

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

void push_scope() {
    printf("Pushed new scope\n");
}

void pop_scope() {
    printf("Popped scope\n");
}

void semantic_analysis(ASTNode *node) {
    printf("Semantic analysis placeholder\n");
}

int main() {
    push_scope();
    yydebug = 1;
    if (yyparse() == 0) {
        printAST(root, 0);
        semantic_analysis(root);
        printf("Semantic analysis passed\n");

        init_codegen();
        generate_IC(root);
        printf("Intermediate Code:\n");
        print_IC();
    }
    pop_scope();
    return 0;
}