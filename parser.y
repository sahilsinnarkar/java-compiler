%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "codegen.h"
#include "symbol_table.h"

extern int yylineno;
extern char *yytext;
void yyerror(const char *s);
int yylex();

static char *current_decl_type;
static char *current_return_type;
ASTNode *root;

int yydebug = 1;
%}

%union {
    int ival;
    double dval;
    char *sval;
    char cval;
    struct ASTNode *node;
    char *type;
}

%token <ival> NUMBER BOOL_LIT
%token <dval> FLOAT_NUM
%token <sval> IDENTIFIER
%token <cval> CHAR_LIT
%token IF ELSE WHILE RETURN FOR SWITCH CASE DEFAULT BREAK
%token INT FLOAT CHAR BOOL VOID
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA ASSIGN 
%token GT LT PLUS MINUS COLON

// Add missing token declarations
%token <node> arg
%type <node> default_case

%nonassoc GT LT
%left PLUS MINUS

%type <node> program stmt_list stmt declaration assignment expr condition 
%type <node> if_stmt block while_stmt return_stmt for_stmt switch_stmt case_list case_stmt
%type <node> function_decl function_call param_list param arg_list literal
%type <type> type_specifier
%type <node> ids

%%

program:
    stmt_list {
        root = $1;
        printf("Parsing completed successfully\n");
    }
    | function_decl program {
        $$ = createNode("PROGRAM", NULL, $1, $2, NULL);
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
    | for_stmt
    | switch_stmt
    | assignment
    | function_call SEMICOLON
    | block
    | return_stmt
;

type_specifier:
    INT { current_decl_type = "int"; $$ = current_decl_type; }
    | FLOAT { current_decl_type = "float"; $$ = current_decl_type; }
    | CHAR { current_decl_type = "char"; $$ = current_decl_type; }
    | BOOL { current_decl_type = "bool"; $$ = current_decl_type; }
    | VOID { current_decl_type = "void"; $$ = current_decl_type; }
;

declaration:
    type_specifier ids SEMICOLON {
        $$ = $2;
    }
;

ids:
    IDENTIFIER {
        if (find_symbol($1)) {
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        add_symbol($1, current_decl_type);
        $$ = createNode("DECL", $1, createNode("TYPE", current_decl_type, NULL, NULL, NULL), NULL, NULL);
    }
    | ids COMMA IDENTIFIER {
        if (find_symbol($3)) {
            yyerror("Redeclaration of variable");
            YYERROR;
        }
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
    | expr LT expr       { $$ = createNode("BIN_OP", "<", $1, $3, NULL); }
    | expr PLUS expr     { $$ = createNode("BIN_OP", "+", $1, $3, NULL); }
    | expr MINUS expr    { $$ = createNode("BIN_OP", "-", $1, $3, NULL); }
    | LPAREN expr RPAREN { $$ = $2; }
    | literal            { $$ = $1; }
    | IDENTIFIER {
        if (!find_symbol($1)) {
            yyerror("Undeclared variable used");
            YYERROR;
        }
        $$ = createNode("VAR", $1, NULL, NULL, NULL);
    }
    | function_call      { $$ = $1; }
;

literal:
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
    | CHAR_LIT {
        char buf[32]; sprintf(buf, "'%c'", $1);
        $$ = createNode("CHAR", buf, NULL, NULL, NULL);
        $$->dataType = strdup("char");
    }
    | BOOL_LIT {
        char *val = $1 ? "true" : "false";
        $$ = createNode("BOOL", val, NULL, NULL, NULL);
        $$->dataType = strdup("bool");
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

for_stmt:
    FOR LPAREN declaration condition SEMICOLON assignment RPAREN block {
        $$ = createNode("FOR", NULL, $3, 
                       createNode("FOR_COND", NULL, $4, 
                                createNode("FOR_INC", NULL, $6, NULL, NULL), 
                                NULL), 
                       $8);
    }
;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list default_case RBRACE {
        $$ = createNode("SWITCH", NULL, $3, 
                       createNode("CASE_LIST", NULL, $6, $7, NULL), 
                       NULL);
    }
;

case_list:
    case_list case_stmt { $1->next = $2; $$ = $1; }
    | case_stmt         { $$ = $1; }
;

case_stmt:
    CASE literal COLON stmt_list {
        $$ = createNode("CASE", NULL, $2, $4, NULL);
    }
;

default_case:
    DEFAULT COLON stmt_list {
        $$ = createNode("DEFAULT", NULL, $3, NULL, NULL);
    }
    | /* empty */ {
        $$ = createNode("EMPTY", NULL, NULL, NULL, NULL);
    }
;

function_decl:
    type_specifier IDENTIFIER LPAREN param_list RPAREN block {
        current_return_type = strdup($1);
        $$ = createNode("FUNCTION", $2, 
                       createNode("RETURN_TYPE", $1, NULL, NULL, NULL),
                       $4, $6);
        current_return_type = NULL;
    }
;

param_list:
    param_list COMMA param { $1->next = $3; $$ = $1; }
    | param               { $$ = $1; }
    | /* empty */         { $$ = NULL; }
;

param:
    type_specifier IDENTIFIER {
        add_symbol($2, $1);
        $$ = createNode("PARAM", $2, 
                       createNode("TYPE", $1, NULL, NULL, NULL), 
                       NULL, NULL);
    }
;

function_call:
    IDENTIFIER LPAREN arg_list RPAREN {
        $$ = createNode("FUNC_CALL", $1, $3, NULL, NULL);
    }
;

arg_list:
    arg_list COMMA expr { $1->next = $3; $$ = $1; }
    | expr             { $$ = $1; }
    | /* empty */      { $$ = NULL; }
;

return_stmt:
    RETURN expr SEMICOLON {
        $$ = createNode("RETURN", NULL, $2, NULL, NULL);
    }
    | RETURN SEMICOLON {
        $$ = createNode("RETURN", NULL, NULL, NULL, NULL);
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
    fprintf(stderr, "Near token: %s\n", yytext);
}

int main() {
    extern FILE *yyin;
    yyin = stdin;
    
    fprintf(stderr, "Starting parser\n");
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
    fprintf(stderr, "Parser completed\n");
    return 0;
}