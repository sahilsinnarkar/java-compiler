%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *type;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
} ASTNode;

ASTNode* createNode(char *type, char *value, ASTNode *left, ASTNode *right, ASTNode *next) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->left = left;
    node->right = right;
    node->next = next;
    printf("Created Node: %s (%s)\n", type, value ? value : "NULL");
    return node;
}

void printAST(ASTNode *node, int level) {
    if (node == NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s", node->type);
    if (node->value) printf(" (%s)", node->value);
    printf("\n");
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
    if (node->next) printAST(node->next, level);
}

extern int yylineno;
extern char *yytext;
void yyerror(const char *s);
int yylex();
%}

%union {
    int ival;
    char *sval;
    struct ASTNode *node;
}

%token IF ELSE SWITCH CASE DEFAULT FOR WHILE DO BREAK CONTINUE
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON ASSIGN COLON
%token <ival> NUMBER
%token <sval> IDENTIFIER
%token GT LT

%type <node> program statement statement_list if_statement assignment_statement condition loop_statement switch_statement case_list

%%

program:
    statement_list {
        printf("\nAbstract Syntax Tree:\n");
        printAST($1, 0);
        $$ = $1;
    }
    ;

statement_list:
    statement statement_list { $$ = createNode("STATEMENT_LIST", NULL, $1, NULL, $2); }
    | statement { $$ = $1; }
    ;

statement:
    if_statement { $$ = $1; }
    | loop_statement { $$ = $1; }
    | assignment_statement { $$ = $1; }
    | switch_statement { $$ = $1; }
    ;

if_statement:
    IF LPAREN condition RPAREN LBRACE statement_list RBRACE {
        $$ = createNode("IF", NULL, $3, $6, NULL);
    }
    | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE {
        ASTNode *elseNode = createNode("ELSE", NULL, NULL, $10, NULL);
        $$ = createNode("IF", NULL, $3, $6, elseNode);
    }
    ;

assignment_statement:
    IDENTIFIER ASSIGN NUMBER SEMICOLON {
        char numStr[20];
        sprintf(numStr, "%d", $3);
        $$ = createNode("ASSIGN", NULL, 
               createNode("VAR", $1, NULL, NULL, NULL), 
               createNode("NUM", numStr, NULL, NULL, NULL), NULL);
    }
    ;

condition:
    IDENTIFIER GT NUMBER {
        char numStr[20];
        sprintf(numStr, "%d", $3);
        $$ = createNode("CONDITION", ">", createNode("VAR", $1, NULL, NULL, NULL), createNode("NUM", numStr, NULL, NULL, NULL), NULL);
    }
    | IDENTIFIER LT NUMBER {
        char numStr[20];
        sprintf(numStr, "%d", $3);
        $$ = createNode("CONDITION", "<", createNode("VAR", $1, NULL, NULL, NULL), createNode("NUM", numStr, NULL, NULL, NULL), NULL);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d, near '%s'\n", s, yylineno, yytext);
}

int main() {
    printf("Enter Java decision-making code:\n");
    if (yyparse() == 0) {
        printf("\nParsing completed successfully.\n");
    } else {
        printf("\nParsing failed.\n");
    }
    return 0;
}
