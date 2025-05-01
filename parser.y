%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "codegen.h"
    #include "symbol_table.h"

    extern int yylineno;
    extern char *yytext;
    void yyerror(const char *s);
    int yylex();

    static char *current_decl_type;
    ASTNode *root;

    int yydebug = 1;  // Parser debugging enabled
%}

%code requires {
    #include "ast.h"
}

%union {
    int ival;
    double dval;
    char *sval;
    ASTNode *node;
    char *type;
}

%token <ival>    NUMBER
%token <dval>    FLOAT_NUM
%token <sval>    IDENTIFIER
%token           IF ELSE WHILE RETURN
%token           INT FLOAT
%token           LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA ASSIGN GT LT PLUS MINUS

%nonassoc GT LT
%left PLUS MINUS

%type <node> program stmt_list stmt declaration assignment expr condition if_stmt block while_stmt return_stmt
%type <type> type_specifier
%type <node> ids

%%

program:
    stmt_list {
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
  | while_stmt
  | assignment
  | block
  | return_stmt
;

type_specifier:
    INT { current_decl_type = "int"; $$ = current_decl_type; }
  | FLOAT { current_decl_type = "float"; $$ = current_decl_type; }
;

declaration:
    type_specifier ids SEMICOLON {
        $$ = $2;
    }
;

ids:
    IDENTIFIER {
        add_symbol($1, current_decl_type);
        $$ = createNode("DECL", $1, createNode("TYPE", current_decl_type, NULL, NULL, NULL), NULL, NULL);
    }
  | ids COMMA IDENTIFIER {
        add_symbol($3, current_decl_type);
        ASTNode *decl = createNode("DECL", $3, createNode("TYPE", current_decl_type, NULL, NULL, NULL), NULL, NULL);
        $1->next = decl;
        $$ = $1;
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
    expr GT expr         { $$ = createNode("BIN_OP", ">", $1, $3, NULL); }
  | expr LT expr         { $$ = createNode("BIN_OP", "<", $1, $3, NULL); }
  | expr PLUS expr       { $$ = createNode("BIN_OP", "+", $1, $3, NULL); }
  | expr MINUS expr      { $$ = createNode("BIN_OP", "-", $1, $3, NULL); }
  | LPAREN expr RPAREN   { $$ = $2; }
  | NUMBER {
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
        if (!find_symbol($1)) {
            yyerror("Undeclared variable used");
            YYERROR;
        }
        $$ = createNode("VAR", $1, NULL, NULL, NULL);
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

while_stmt:
    WHILE LPAREN condition RPAREN block {
        $$ = createNode("WHILE", NULL, $3, $5, NULL);
    }
;

return_stmt:
    RETURN expr SEMICOLON {
        $$ = createNode("RETURN", NULL, $2, NULL, NULL);
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

int main() {
    extern FILE *yyin;
    yyin = stdin;
    
    fprintf(stderr, "Starting parser\n");
    push_scope();
    yydebug = 1;  // Ensure debug is enabled
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
    fprintf(stderr, "Parser completed\n");
    return 0;
}