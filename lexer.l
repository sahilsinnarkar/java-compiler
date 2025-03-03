%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#ifndef strdup
#define strdup _strdup
#endif
%}

%option noyywrap
%option yylineno

%%

"if"           { printf("Token: IF\n"); return IF; }
"else"         { printf("Token: ELSE\n"); return ELSE; }
"switch"       { printf("Token: SWITCH\n"); return SWITCH; }
"case"         { printf("Token: CASE\n"); return CASE; }
"default"      { printf("Token: DEFAULT\n"); return DEFAULT; }
"for"          { printf("Token: FOR\n"); return FOR; }
"while"        { printf("Token: WHILE\n"); return WHILE; }
"do"           { printf("Token: DO\n"); return DO; }
"break"        { printf("Token: BREAK\n"); return BREAK; }
"continue"     { printf("Token: CONTINUE\n"); return CONTINUE; }
"{"            { printf("Token: LBRACE\n"); return LBRACE; }
"}"            { printf("Token: RBRACE\n"); return RBRACE; }
"("            { printf("Token: LPAREN\n"); return LPAREN; }
")"            { printf("Token: RPAREN\n"); return RPAREN; }
":"            { printf("Token: COLON\n"); return COLON; }
";"            { printf("Token: SEMICOLON\n"); return SEMICOLON; }
"="            { printf("Token: ASSIGN\n"); return ASSIGN; }
">"            { printf("Token: GT\n"); return GT; }
"<"            { printf("Token: LT\n"); return LT; }
[0-9]+         { printf("Token: NUMBER (%s)\n", yytext); yylval.ival = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Token: IDENTIFIER (%s)\n", yytext); yylval.sval = strdup(yytext); return IDENTIFIER; }
[ \t\r\n]+
.              { printf("Unexpected character: %s\n", yytext); }

%%
