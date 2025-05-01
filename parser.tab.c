
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

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


/* Line 189 of yacc.c  */
#line 94 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 21 "parser.y"

    int ival;
    double dval;
    char *sval;
    char cval;
    struct ASTNode *node;
    char *type;



/* Line 214 of yacc.c  */
#line 175 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 187 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    16,    18,
      20,    22,    24,    26,    28,    31,    33,    35,    37,    39,
      41,    43,    45,    49,    51,    55,    60,    64,    68,    72,
      76,    80,    82,    84,    86,    88,    90,    92,    94,   100,
     108,   114,   123,   132,   135,   137,   142,   146,   147,   154,
     158,   160,   161,   164,   169,   173,   175,   176,   180,   183,
     187
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    52,    36,    -1,     1,    -1,
      37,    38,    -1,    38,    -1,    -1,    40,    -1,    45,    -1,
      46,    -1,    47,    -1,    48,    -1,    42,    -1,    55,    26,
      -1,    58,    -1,    57,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    21,    -1,    39,    41,    26,    -1,     6,
      -1,    41,    27,     6,    -1,     6,    28,    43,    26,    -1,
      43,    29,    43,    -1,    43,    30,    43,    -1,    43,    31,
      43,    -1,    43,    32,    43,    -1,    24,    43,    25,    -1,
      44,    -1,     6,    -1,    55,    -1,     3,    -1,     5,    -1,
       7,    -1,     4,    -1,     8,    24,    59,    25,    58,    -1,
       8,    24,    59,    25,    58,     9,    58,    -1,    10,    24,
      59,    25,    58,    -1,    12,    24,    40,    59,    26,    42,
      25,    58,    -1,    13,    24,    43,    25,    22,    49,    51,
      23,    -1,    49,    50,    -1,    50,    -1,    14,    44,    33,
      37,    -1,    15,    33,    37,    -1,    -1,    39,     6,    24,
      53,    25,    58,    -1,    53,    27,    54,    -1,    54,    -1,
      -1,    39,     6,    -1,     6,    24,    56,    25,    -1,    56,
      27,    43,    -1,    43,    -1,    -1,    11,    43,    26,    -1,
      11,    26,    -1,    22,    37,    23,    -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    59,    62,    69,    75,    78,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    96,    97,    98,
      99,   100,   104,   110,   118,   131,   139,   140,   141,   142,
     143,   144,   145,   152,   156,   161,   166,   171,   179,   182,
     188,   194,   204,   212,   213,   217,   223,   226,   232,   242,
     243,   244,   248,   257,   263,   264,   265,   269,   272,   278,
     284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "BOOL_LIT", "FLOAT_NUM",
  "IDENTIFIER", "CHAR_LIT", "IF", "ELSE", "WHILE", "RETURN", "FOR",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "INT", "FLOAT", "CHAR", "BOOL",
  "VOID", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "COMMA",
  "ASSIGN", "GT", "LT", "PLUS", "MINUS", "COLON", "arg", "$accept",
  "program", "stmt_list", "stmt", "type_specifier", "declaration", "ids",
  "assignment", "expr", "literal", "if_stmt", "while_stmt", "for_stmt",
  "switch_stmt", "case_list", "case_stmt", "default_case", "function_decl",
  "param_list", "param", "function_call", "arg_list", "return_stmt",
  "block", "condition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    36,    37,    37,    37,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    39,    39,    39,
      39,    39,    40,    41,    41,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    44,    44,    45,    45,
      46,    47,    48,    49,    49,    50,    51,    51,    52,    53,
      53,    53,    54,    55,    56,    56,    56,    57,    57,    58,
      59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     0,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     4,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       5,     8,     8,     2,     1,     4,     3,     0,     6,     3,
       1,     0,     2,     4,     3,     1,     0,     3,     2,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,     7,     0,     2,     6,     0,     8,    13,
       9,    10,    11,    12,     0,     0,    16,    15,    56,     0,
       0,     0,    34,    37,    35,    32,    36,     0,    58,     0,
      31,    33,     0,     0,     0,     0,     1,     5,    23,     0,
       3,    14,    55,     0,     0,    60,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,    59,    23,    51,    22,
       0,    53,     0,    25,     0,     0,    30,    26,    27,    28,
      29,     0,     0,     0,     0,    50,    24,    54,    38,    40,
       0,     0,    52,     0,     0,     0,     0,     0,     0,    47,
      44,    48,    49,    39,     0,     0,     0,    43,     0,    41,
       7,     7,    42,    45,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    14,    15,    16,    45,    18,    49,    19,    55,    40,
      20,    21,    22,    23,    99,   100,   108,    24,    84,    85,
      41,    53,    26,    27,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
      68,   -57,    -8,   -18,   -17,    47,   -10,    -7,   -57,   -57,
     -57,   -57,   -57,   127,    29,   127,   -57,    28,   -57,   -57,
     -57,   -57,   -57,   -57,    68,    12,   -57,   -57,    53,    53,
      53,    53,   -57,   -57,   -57,    21,   -57,    53,   -57,    77,
     -57,   -57,    74,    53,   109,    36,   -57,   -57,    23,     1,
     -57,   -57,   136,     8,   132,   136,    24,    30,   -20,   -57,
      53,    53,    53,    53,    53,   125,   -57,   -57,    74,   -57,
      55,   -57,    53,   -57,    40,    40,   -57,   140,   140,   -57,
     -57,    41,    50,    76,    16,   -57,   -57,   136,    88,   -57,
      92,    90,   -57,    40,    74,    40,    84,    80,    18,    69,
     -57,   -57,   -57,   -57,    40,    83,    85,   -57,   100,   -57,
     127,   127,   -57,   127,   127
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   101,    -9,   -14,     2,    82,   -57,    44,     3,    38,
     -57,   -57,   -57,   -57,   -57,    42,   -57,   -57,   -57,    48,
       0,   -57,   -57,   -56,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int8 yytable[] =
{
      25,    47,    17,    57,    44,    76,    30,    31,    39,    60,
      61,    62,    63,    25,    42,    25,    28,    43,    88,    89,
      29,    32,    33,    34,    25,    36,    17,    69,    70,    46,
      47,    52,    54,    71,    48,    72,    81,   101,    51,   103,
      58,    93,    67,    94,    25,    28,    65,    68,   109,    74,
      32,    33,    34,    35,    36,    75,    32,    33,    34,    35,
      36,    86,    13,    77,    78,    79,    80,    90,    -7,     1,
      83,    37,    91,    38,     2,    87,     3,    37,     4,     5,
       6,     7,    92,    98,   106,     8,     9,    10,    11,    12,
      13,     8,     9,    10,    11,    12,    83,    95,    96,    47,
      47,   113,   114,    59,    98,   104,    60,    61,    62,    63,
      25,    25,    29,    25,    25,     2,   110,     3,   111,     4,
       5,     6,     7,   112,    64,    50,     8,     9,    10,    11,
      12,    13,    66,     2,    97,     3,   105,     4,     5,     6,
       7,   107,   102,     0,     8,     9,    10,    11,    12,    13,
      82,     0,     0,     0,    60,    61,    62,    63,    73,     0,
       0,    60,    61,    62,    63,    60,    61,    62,    63,    -8,
      -8,    62,    63
};

static const yytype_int8 yycheck[] =
{
       0,    15,     0,    31,    13,    25,    24,    24,     5,    29,
      30,    31,    32,    13,    24,    15,    24,    24,    74,    75,
      28,     3,     4,     5,    24,     7,    24,    26,    27,     0,
      44,    28,    29,    25,     6,    27,    64,    93,    26,    95,
      37,    25,     6,    27,    44,    24,    43,    24,   104,    25,
       3,     4,     5,     6,     7,    25,     3,     4,     5,     6,
       7,     6,    22,    60,    61,    62,    63,    26,     0,     1,
      68,    24,    22,    26,     6,    72,     8,    24,    10,    11,
      12,    13,     6,    14,    15,    17,    18,    19,    20,    21,
      22,    17,    18,    19,    20,    21,    94,     9,     6,   113,
     114,   110,   111,    26,    14,    25,    29,    30,    31,    32,
     110,   111,    28,   113,   114,     6,    33,     8,    33,    10,
      11,    12,    13,    23,    42,    24,    17,    18,    19,    20,
      21,    22,    23,     6,    90,     8,    98,    10,    11,    12,
      13,    99,    94,    -1,    17,    18,    19,    20,    21,    22,
      25,    -1,    -1,    -1,    29,    30,    31,    32,    26,    -1,
      -1,    29,    30,    31,    32,    29,    30,    31,    32,    29,
      30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,     8,    10,    11,    12,    13,    17,    18,
      19,    20,    21,    22,    36,    37,    38,    39,    40,    42,
      45,    46,    47,    48,    52,    55,    57,    58,    24,    28,
      24,    24,     3,     4,     5,     6,     7,    24,    26,    43,
      44,    55,    24,    24,    37,    39,     0,    38,     6,    41,
      36,    26,    43,    56,    43,    43,    59,    59,    43,    26,
      29,    30,    31,    32,    40,    43,    23,     6,    24,    26,
      27,    25,    27,    26,    25,    25,    25,    43,    43,    43,
      43,    59,    25,    39,    53,    54,     6,    43,    58,    58,
      26,    22,     6,    25,    27,     9,     6,    42,    14,    49,
      50,    58,    54,    58,    25,    44,    15,    50,    51,    58,
      33,    33,    23,    37,    37
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 55 "parser.y"
    {
        root = (yyvsp[(1) - (1)].node);
        printf("Parsing completed successfully\n");
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 59 "parser.y"
    {
        (yyval.node) = createNode("PROGRAM", NULL, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), NULL);
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    {
        yyerror("syntax error");
        YYABORT;
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    {
        ASTNode *t = (yyvsp[(1) - (2)].node);
        while (t->next) t = t->next;
        t->next = (yyvsp[(2) - (2)].node);
        (yyval.node) = (yyvsp[(1) - (2)].node);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {
        (yyval.node) = createNode("STMT_LIST", NULL, (yyvsp[(1) - (1)].node), NULL, NULL);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {
        (yyval.node) = createNode("EMPTY_STMT", NULL, NULL, NULL, NULL);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    { current_decl_type = "int"; (yyval.type) = current_decl_type; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { current_decl_type = "float"; (yyval.type) = current_decl_type; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { current_decl_type = "char"; (yyval.type) = current_decl_type; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { current_decl_type = "bool"; (yyval.type) = current_decl_type; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { current_decl_type = "void"; (yyval.type) = current_decl_type; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {
        if (find_symbol((yyvsp[(1) - (1)].sval))) {
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        add_symbol((yyvsp[(1) - (1)].sval), current_decl_type);
        (yyval.node) = createNode("DECL", (yyvsp[(1) - (1)].sval), createNode("TYPE", current_decl_type, NULL, NULL, NULL), NULL, NULL);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {
        if (find_symbol((yyvsp[(3) - (3)].sval))) {
            yyerror("Redeclaration of variable");
            YYERROR;
        }
        add_symbol((yyvsp[(3) - (3)].sval), current_decl_type);
        ASTNode *decl = createNode("DECL", (yyvsp[(3) - (3)].sval), createNode("TYPE", current_decl_type, NULL, NULL, NULL), NULL, NULL);
        (yyvsp[(1) - (3)].node)->next = decl;
        (yyval.node) = (yyvsp[(1) - (3)].node);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {
        (yyval.node) = createNode("ASSIGN", NULL,
                       createNode("VAR", (yyvsp[(1) - (4)].sval), NULL, NULL, NULL),
                       (yyvsp[(3) - (4)].node), NULL);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { (yyval.node) = createNode("BIN_OP", ">", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    { (yyval.node) = createNode("BIN_OP", "<", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    { (yyval.node) = createNode("BIN_OP", "+", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    { (yyval.node) = createNode("BIN_OP", "-", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), NULL); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {
        if (!find_symbol((yyvsp[(1) - (1)].sval))) {
            yyerror("Undeclared variable used");
            YYERROR;
        }
        (yyval.node) = createNode("VAR", (yyvsp[(1) - (1)].sval), NULL, NULL, NULL);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {
        char buf[32]; sprintf(buf, "%d", (yyvsp[(1) - (1)].ival));
        (yyval.node) = createNode("NUM", buf, NULL, NULL, NULL);
        (yyval.node)->dataType = strdup("int");
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {
        char buf[32]; sprintf(buf, "%.2f", (yyvsp[(1) - (1)].dval));
        (yyval.node) = createNode("FLOAT", buf, NULL, NULL, NULL);
        (yyval.node)->dataType = strdup("float");
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {
        char buf[32]; sprintf(buf, "'%c'", (yyvsp[(1) - (1)].cval));
        (yyval.node) = createNode("CHAR", buf, NULL, NULL, NULL);
        (yyval.node)->dataType = strdup("char");
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {
        char *val = (yyvsp[(1) - (1)].ival) ? "true" : "false";
        (yyval.node) = createNode("BOOL", val, NULL, NULL, NULL);
        (yyval.node)->dataType = strdup("bool");
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
        (yyval.node) = createNode("IF", NULL, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
        (yyval.node) = createNode("IF_ELSE", NULL, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), (yyvsp[(7) - (7)].node));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {
        (yyval.node) = createNode("WHILE", NULL, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), NULL);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {
        (yyval.node) = createNode("FOR", NULL, (yyvsp[(3) - (8)].node), 
                       createNode("FOR_COND", NULL, (yyvsp[(4) - (8)].node), 
                                createNode("FOR_INC", NULL, (yyvsp[(6) - (8)].node), NULL, NULL), 
                                NULL), 
                       (yyvsp[(8) - (8)].node));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {
        (yyval.node) = createNode("SWITCH", NULL, (yyvsp[(3) - (8)].node), 
                       createNode("CASE_LIST", NULL, (yyvsp[(6) - (8)].node), (yyvsp[(7) - (8)].node), NULL), 
                       NULL);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyvsp[(1) - (2)].node)->next = (yyvsp[(2) - (2)].node); (yyval.node) = (yyvsp[(1) - (2)].node); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {
        (yyval.node) = createNode("CASE", NULL, (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node), NULL);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {
        (yyval.node) = createNode("DEFAULT", NULL, (yyvsp[(3) - (3)].node), NULL, NULL);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    {
        (yyval.node) = createNode("EMPTY", NULL, NULL, NULL, NULL);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {
        current_return_type = strdup((yyvsp[(1) - (6)].type));
        (yyval.node) = createNode("FUNCTION", (yyvsp[(2) - (6)].sval), 
                       createNode("RETURN_TYPE", (yyvsp[(1) - (6)].type), NULL, NULL, NULL),
                       (yyvsp[(4) - (6)].node), (yyvsp[(6) - (6)].node));
        current_return_type = NULL;
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyvsp[(1) - (3)].node)->next = (yyvsp[(3) - (3)].node); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.node) = NULL; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {
        add_symbol((yyvsp[(2) - (2)].sval), (yyvsp[(1) - (2)].type));
        (yyval.node) = createNode("PARAM", (yyvsp[(2) - (2)].sval), 
                       createNode("TYPE", (yyvsp[(1) - (2)].type), NULL, NULL, NULL), 
                       NULL, NULL);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {
        (yyval.node) = createNode("FUNC_CALL", (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].node), NULL, NULL);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { (yyvsp[(1) - (3)].node)->next = (yyvsp[(3) - (3)].node); (yyval.node) = (yyvsp[(1) - (3)].node); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    { (yyval.node) = NULL; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {
        (yyval.node) = createNode("RETURN", NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
        (yyval.node) = createNode("RETURN", NULL, NULL, NULL, NULL);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {
        (yyval.node) = createNode("BLOCK", NULL, (yyvsp[(2) - (3)].node), NULL, NULL);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1943 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 287 "parser.y"


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
