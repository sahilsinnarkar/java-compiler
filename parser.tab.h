
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     BOOL_LIT = 259,
     FLOAT_NUM = 260,
     IDENTIFIER = 261,
     CHAR_LIT = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     RETURN = 266,
     FOR = 267,
     SWITCH = 268,
     CASE = 269,
     DEFAULT = 270,
     BREAK = 271,
     INT = 272,
     FLOAT = 273,
     CHAR = 274,
     BOOL = 275,
     VOID = 276,
     LBRACE = 277,
     RBRACE = 278,
     LPAREN = 279,
     RPAREN = 280,
     SEMICOLON = 281,
     COMMA = 282,
     ASSIGN = 283,
     GT = 284,
     LT = 285,
     PLUS = 286,
     MINUS = 287,
     COLON = 288,
     arg = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 21 "parser.y"

    int ival;
    double dval;
    char *sval;
    char cval;
    struct ASTNode *node;
    char *type;



/* Line 1676 of yacc.c  */
#line 97 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


