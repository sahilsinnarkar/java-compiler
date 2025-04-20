%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

void yyerror(const char *s);
%}

%option noyywrap
%option yylineno

%%

"if"            { return IF; }
"else"          { return ELSE; }
"int"           { return INT; }
"float"         { return FLOAT; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
";"             { return SEMICOLON; }
"="             { return ASSIGN; }
">"             { return GT; }
"+"             { return PLUS; }
[0-9]+          { yylval.ival = atoi(yytext); return NUMBER; }
[0-9]*\.[0-9]+  { yylval.dval = atof(yytext); return FLOAT_NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }
[ \t\n]         { /* ignore whitespace */ }
.               { 
                 fprintf(stderr, "Lexical error at line %d: Unexpected character '%s'\n", 
                         yylineno, yytext); 
                 exit(1);
               }
<<EOF>> {
    printf("End of input reached\n");
    return 0;
}

%%