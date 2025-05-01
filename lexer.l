%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

void yyerror(const char *s);
extern int yydebug;
%}

%option noyywrap
%option yylineno

%%

"if"            { printf("TOKEN: IF\n"); return IF; }
"else"          { printf("TOKEN: ELSE\n"); return ELSE; }
"while"         { printf("TOKEN: WHILE\n"); return WHILE; }
"return"        { printf("TOKEN: RETURN\n"); return RETURN; }
"int"           { printf("TOKEN: INT\n"); return INT; }
"float"         { printf("TOKEN: FLOAT\n"); return FLOAT; }
"char"          { return CHAR; }
"bool"          { return BOOL; }
"true"          { yylval.ival = 1; return BOOL_LIT; }
"false"         { yylval.ival = 0; return BOOL_LIT; }
'.'             { yylval.ival = yytext[1]; return CHAR_LIT; }
"for"           { return FOR; }
"break"         { return BREAK; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"switch"        { return SWITCH; }
"{"             { printf("TOKEN: LBRACE\n"); return LBRACE; }
"}"             { printf("TOKEN: RBRACE\n"); return RBRACE; }
"("             { printf("TOKEN: LPAREN\n"); return LPAREN; }
")"             { printf("TOKEN: RPAREN\n"); return RPAREN; }
";"             { printf("TOKEN: SEMICOLON\n"); return SEMICOLON; }
","             { printf("TOKEN: COMMA\n"); return COMMA; }
"="             { printf("TOKEN: ASSIGN\n"); return ASSIGN; }
">"             { printf("TOKEN: GT\n"); return GT; }
"<"             { printf("TOKEN: LT\n"); return LT; }
"+"             { printf("TOKEN: PLUS\n"); return PLUS; }
"-"             { printf("TOKEN: MINUS\n"); return MINUS; }

([0-9]+\.?[0-9]*)|([0-9]*\.[0-9]+)  { 
    printf("TOKEN: FLOAT_NUM (%s)\n", yytext);
    yylval.dval = atof(yytext); 
    return FLOAT_NUM; 
}
[0-9]+          { 
    printf("TOKEN: NUMBER (%s)\n", yytext);
    yylval.ival = atoi(yytext); 
    return NUMBER; 
}

\r?\n           { yylineno++; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

[ \t]+          { /* skip whitespace */ }

<<EOF>>         { printf("TOKEN: EOF\n"); return 0; }

. {
    fprintf(stderr, "LEXER ERROR: Unexpected char '%s' at line %d\n", yytext, yylineno);
    exit(1);
}

%%