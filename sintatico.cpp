/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTCONST = 258,
     ID = 259,
     CARCONST = 260,
     CADEIACAR = 261,
     PROGRAMA = 262,
     RETORNE = 263,
     INT = 264,
     CAR = 265,
     LEIA = 266,
     ESCREVA = 267,
     SE = 268,
     ENTAO = 269,
     SENAO = 270,
     ENQUANTO = 271,
     OU_OP = 272,
     E_OP = 273,
     EQ_OP = 274,
     NE_OP = 275,
     GE_OP = 276,
     LE_OP = 277,
     NOVALINHA = 278,
     EXECUTE = 279
   };
#endif
/* Tokens.  */
#define INTCONST 258
#define ID 259
#define CARCONST 260
#define CADEIACAR 261
#define PROGRAMA 262
#define RETORNE 263
#define INT 264
#define CAR 265
#define LEIA 266
#define ESCREVA 267
#define SE 268
#define ENTAO 269
#define SENAO 270
#define ENQUANTO 271
#define OU_OP 272
#define E_OP 273
#define EQ_OP 274
#define NE_OP 275
#define GE_OP 276
#define LE_OP 277
#define NOVALINHA 278
#define EXECUTE 279




/* Copy the first part of user declarations.  */
#line 1 "cafezinho.yac"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "./tipos.h"
    
int yylex(void);
void yyerror(const char *s);

extern int yylineno;

Node * createNode(NodeType nodeType){
    Node * aux = (Node*) malloc(sizeof(Node));
    
    if(aux){
        aux->nodeType = nodeType;

        aux->data1 = NULL;
        aux->data2 = NULL;
        aux->data3 = NULL;
        aux->data4 = NULL;

        return aux;
    }

    return NULL;
}

void GenerateTree();

Node * root;



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "cafezinho.yac"
{
    int integer;
    Node * node;
    char * str;
}
/* Line 193 of yacc.c.  */
#line 184 "sintatico.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 197 "sintatico.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    42,     2,     2,
      29,    30,    40,    38,    28,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    25,
      36,    33,    37,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    12,    21,    26,    27,    30,    34,
      41,    42,    47,    49,    50,    53,    58,    63,    70,    75,
      79,    85,    94,    95,    97,    99,   101,   104,   106,   109,
     113,   117,   121,   125,   127,   134,   143,   150,   152,   154,
     156,   160,   162,   168,   172,   174,   178,   180,   184,   188,
     190,   194,   198,   202,   206,   208,   212,   216,   218,   222,
     226,   230,   232,   235,   238,   240,   245,   247,   252,   256,
     261,   263,   265,   267,   271,   273
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    47,    -1,    54,     4,    48,    25,
      46,    -1,    54,     4,    26,     3,    27,    48,    25,    46,
      -1,    54,     4,    49,    46,    -1,    -1,     7,    52,    -1,
      28,     4,    48,    -1,    28,     4,    26,     3,    27,    48,
      -1,    -1,    29,    50,    30,    52,    -1,    51,    -1,    -1,
      54,     4,    -1,    54,     4,    26,    27,    -1,    54,     4,
      28,    51,    -1,    54,     4,    26,    27,    28,    51,    -1,
      31,    53,    55,    32,    -1,    31,    53,    32,    -1,    54,
       4,    48,    25,    53,    -1,    54,     4,    26,     3,    27,
      48,    25,    53,    -1,    -1,     9,    -1,    10,    -1,    56,
      -1,    56,    55,    -1,    25,    -1,    57,    25,    -1,     8,
      57,    25,    -1,    11,    67,    25,    -1,    12,     6,    25,
      -1,    12,    57,    25,    -1,    23,    -1,    13,    29,    57,
      30,    14,    56,    -1,    13,    29,    57,    30,    14,    56,
      15,    56,    -1,    16,    29,    57,    30,    24,    56,    -1,
      52,    -1,    58,    -1,    59,    -1,    67,    33,    58,    -1,
      60,    -1,    60,    34,    57,    35,    59,    -1,    60,    17,
      61,    -1,    61,    -1,    61,    18,    62,    -1,    62,    -1,
      62,    19,    63,    -1,    62,    20,    63,    -1,    63,    -1,
      63,    36,    64,    -1,    63,    37,    64,    -1,    63,    21,
      64,    -1,    63,    22,    64,    -1,    64,    -1,    64,    38,
      65,    -1,    64,    39,    65,    -1,    65,    -1,    65,    40,
      66,    -1,    65,    41,    66,    -1,    65,    42,    66,    -1,
      66,    -1,    39,    68,    -1,    43,    68,    -1,    68,    -1,
       4,    26,    57,    27,    -1,     4,    -1,     4,    29,    69,
      30,    -1,     4,    29,    30,    -1,     4,    26,    57,    27,
      -1,     4,    -1,     5,    -1,     3,    -1,    29,    57,    30,
      -1,    58,    -1,    69,    28,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    73,    80,    84,    86,    91,    96,   100,
     102,   107,   112,   114,   117,   120,   123,   126,   131,   134,
     139,   142,   144,   149,   152,   157,   160,   165,   168,   171,
     174,   177,   180,   183,   186,   189,   192,   195,   200,   205,
     208,   213,   216,   221,   224,   229,   232,   237,   240,   243,
     248,   251,   254,   257,   260,   265,   268,   271,   276,   279,
     282,   285,   290,   293,   296,   301,   304,   309,   312,   315,
     318,   321,   324,   327,   332,   335
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTCONST", "ID", "CARCONST",
  "CADEIACAR", "PROGRAMA", "RETORNE", "INT", "CAR", "LEIA", "ESCREVA",
  "SE", "ENTAO", "SENAO", "ENQUANTO", "OU_OP", "E_OP", "EQ_OP", "NE_OP",
  "GE_OP", "LE_OP", "NOVALINHA", "EXECUTE", "';'", "'['", "']'", "','",
  "'('", "')'", "'{'", "'}'", "'='", "'?'", "':'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "$accept", "Programa", "DeclFuncVar",
  "DeclProg", "DeclVar", "DeclFunc", "ListaParametros",
  "ListaParametrosCont", "Bloco", "ListaDeclVar", "Tipo", "ListaComando",
  "Comando", "Expr", "AssignExpr", "CondExpr", "OrExpr", "AndExpr",
  "EqExpr", "DesigExpr", "AddExpr", "MulExpr", "UnExpr", "LValueExpr",
  "PrimExpr", "ListExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    91,    93,    44,    40,
      41,   123,   125,    61,    63,    58,    60,    62,    43,    45,
      42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    46,    47,    48,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     8,     4,     0,     2,     3,     6,
       0,     4,     1,     0,     2,     4,     4,     6,     4,     3,
       5,     8,     0,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     3,     1,     6,     8,     6,     1,     1,     1,
       3,     1,     5,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     4,     1,     4,     3,     4,
       1,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    23,    24,     0,     0,     0,     1,     0,     2,    10,
      22,     7,     0,     0,    13,     0,     6,     0,     0,     0,
      10,     0,    12,     0,     6,     5,    72,    70,    71,     0,
       0,     0,     0,     0,    33,    27,     0,    19,     0,     0,
      37,     0,    25,     0,    38,    39,    41,    44,    46,    49,
      54,    57,    61,     0,    64,    10,    10,     0,     8,     0,
      14,     3,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,    70,    62,    63,    18,    26,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    68,    74,     0,    29,     0,    30,    31,    32,     0,
       0,    73,     0,    43,     0,    45,    47,    48,    52,    53,
      50,    51,    55,    56,    58,    59,    60,    40,     0,    22,
       6,    10,    15,    16,    69,     0,    67,     0,     0,     0,
       0,     0,    10,    20,     4,     9,     0,    75,    65,     0,
       0,    69,    42,     0,    17,    34,    36,    22,     0,    21,
      35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,    15,    16,    21,    22,    40,    17,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
     112,  -114,  -114,    11,    13,    30,  -114,    16,  -114,    22,
     112,  -114,    49,    53,   112,    38,   112,    10,    76,    60,
      50,    64,  -114,   101,   112,  -114,  -114,    -2,  -114,   103,
     113,    56,    97,   102,  -114,  -114,   103,  -114,    25,    25,
    -114,   108,    61,   118,  -114,  -114,    -9,   126,   105,    46,
      91,    73,  -114,   115,  -114,    65,   128,   154,  -114,    16,
      92,  -114,   103,    98,   133,   134,   136,   137,   138,   103,
     103,   129,    14,  -114,  -114,  -114,  -114,  -114,   106,   103,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   103,   161,   140,   141,   142,  -114,   143,   112,
     144,  -114,  -114,   -11,  -114,   103,  -114,  -114,  -114,   145,
     146,  -114,   103,   126,   132,   105,    46,    46,    91,    91,
      91,    91,    73,    73,  -114,  -114,  -114,  -114,   147,   112,
     112,   128,   149,  -114,   135,   103,  -114,   151,   158,   155,
     153,   106,   128,  -114,  -114,  -114,   112,  -114,  -114,    61,
      61,  -114,  -114,   148,  -114,   166,  -114,   112,    61,  -114,
    -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,   -14,  -114,   -19,  -114,  -114,   -90,    -1,  -113,
     -10,   150,   -79,   -24,   -60,    41,  -114,   107,   104,    52,
      67,    51,     7,   156,   116,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -67
static const yytype_int16 yytable[] =
{
      18,    58,    25,   102,    23,    64,    11,    68,    78,   133,
      61,     6,    71,    26,    27,    28,   143,   135,    29,   136,
       7,    30,    31,    32,    62,    79,    33,    63,    26,    72,
      28,   -66,   127,    34,     9,    35,    94,    95,   100,    36,
     112,    10,    37,    63,   159,   109,   110,    10,    12,    38,
      13,    14,    19,    39,    36,   114,   154,    20,    97,    26,
      27,    28,    67,    24,    26,    27,    28,    83,    84,    29,
     155,   156,    30,    31,    32,   147,    57,    33,    13,   160,
      55,   137,    85,    86,    34,    36,    35,    56,   140,    23,
      36,    93,    10,    13,    59,    38,   124,   125,   126,    39,
      38,    26,    27,    28,    39,    60,    26,    27,    28,    26,
      72,    28,   145,    89,    90,    91,   144,    65,    98,    18,
      99,     1,     2,   153,    81,    82,    69,    36,   101,    87,
      88,    70,    36,   116,   117,    36,    23,    38,   122,   123,
      75,    39,    38,    77,    80,    38,    39,    18,    92,    39,
     118,   119,   120,   121,    73,    74,    13,    96,   104,   111,
     105,   106,   107,   108,   128,   129,   130,   141,   -65,   131,
     132,   134,   149,   157,   142,   138,   139,   146,   148,   150,
     151,   158,   152,     0,   115,   113,    66,     0,     0,     0,
       0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      10,    20,    16,    63,    14,    29,     7,    31,    17,    99,
      24,     0,    36,     3,     4,     5,   129,    28,     8,    30,
       7,    11,    12,    13,    26,    34,    16,    29,     3,     4,
       5,    33,    92,    23,     4,    25,    55,    56,    62,    29,
      26,    31,    32,    29,   157,    69,    70,    31,    26,    39,
      28,    29,     3,    43,    29,    79,   146,     4,    59,     3,
       4,     5,     6,    25,     3,     4,     5,    21,    22,     8,
     149,   150,    11,    12,    13,   135,    26,    16,    28,   158,
       4,   105,    36,    37,    23,    29,    25,    27,   112,    99,
      29,    26,    31,    28,    30,    39,    89,    90,    91,    43,
      39,     3,     4,     5,    43,     4,     3,     4,     5,     3,
       4,     5,   131,    40,    41,    42,   130,     4,    26,   129,
      28,     9,    10,   142,    19,    20,    29,    29,    30,    38,
      39,    29,    29,    81,    82,    29,   146,    39,    87,    88,
      32,    43,    39,    25,    18,    39,    43,   157,    33,    43,
      83,    84,    85,    86,    38,    39,    28,     3,    25,    30,
      26,    25,    25,    25,     3,    25,    25,    35,    33,    27,
      27,    27,    14,    25,    27,    30,    30,    28,    27,    24,
      27,    15,   141,    -1,    80,    78,    30,    -1,    -1,    -1,
      -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    45,    46,    54,     0,     7,    47,     4,
      31,    52,    26,    28,    29,    48,    49,    53,    54,     3,
       4,    50,    51,    54,    25,    46,     3,     4,     5,     8,
      11,    12,    13,    16,    23,    25,    29,    32,    39,    43,
      52,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     4,    27,    26,    48,    30,
       4,    46,    26,    29,    57,     4,    67,     6,    57,    29,
      29,    57,     4,    68,    68,    32,    55,    25,    17,    34,
      18,    19,    20,    21,    22,    36,    37,    38,    39,    40,
      41,    42,    33,    26,    48,    48,     3,    52,    26,    28,
      57,    30,    58,    69,    25,    26,    25,    25,    25,    57,
      57,    30,    26,    61,    57,    62,    63,    63,    64,    64,
      64,    64,    65,    65,    66,    66,    66,    58,     3,    25,
      25,    27,    27,    51,    27,    28,    30,    57,    30,    30,
      57,    35,    27,    53,    46,    48,    28,    58,    27,    14,
      24,    27,    59,    48,    51,    56,    56,    25,    15,    53,
      56
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 64 "cafezinho.yac"
    {
        printf("LÉXICA E SINTÁTICAMENTE CORRETO\n"); 
        Node * aux = createNode(NO_PROGRAMA);
        aux->data1 = (yyvsp[(1) - (2)].node);
        aux->data2 = (yyvsp[(2) - (2)].node);
        root = (yyval.node);
    ;}
    break;

  case 3:
#line 73 "cafezinho.yac"
    {
        Node * aux = createNode(NO_ID);
        aux->data1 = (yyvsp[(2) - (5)].node);
        (yyval.node) = aux;
        
    ;}
    break;

  case 4:
#line 80 "cafezinho.yac"
    {
        
    ;}
    break;

  case 5:
#line 84 "cafezinho.yac"
    {
        
    ;}
    break;

  case 6:
#line 86 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 7:
#line 91 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 8:
#line 96 "cafezinho.yac"
    {
       (yyval.node) = NULL; 
    ;}
    break;

  case 9:
#line 100 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 10:
#line 102 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 11:
#line 107 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 12:
#line 112 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 14:
#line 117 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 15:
#line 120 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 16:
#line 123 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 17:
#line 126 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 18:
#line 131 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 19:
#line 134 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 20:
#line 139 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 21:
#line 142 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 22:
#line 144 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 23:
#line 149 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 24:
#line 152 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 25:
#line 157 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 26:
#line 160 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 27:
#line 165 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 28:
#line 168 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 29:
#line 171 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 30:
#line 174 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 31:
#line 177 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 32:
#line 180 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 33:
#line 183 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 34:
#line 186 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 35:
#line 189 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 36:
#line 192 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 37:
#line 195 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 38:
#line 200 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 39:
#line 205 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 40:
#line 208 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 41:
#line 213 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 42:
#line 216 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 43:
#line 221 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 44:
#line 224 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 45:
#line 229 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 46:
#line 232 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 47:
#line 237 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 48:
#line 240 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 49:
#line 243 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 50:
#line 248 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 51:
#line 251 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 52:
#line 254 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 53:
#line 257 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 54:
#line 260 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 55:
#line 265 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 56:
#line 268 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 57:
#line 271 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 58:
#line 276 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 59:
#line 279 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 60:
#line 282 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 61:
#line 285 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 62:
#line 290 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 63:
#line 293 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 64:
#line 296 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 65:
#line 301 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 66:
#line 304 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 67:
#line 309 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 68:
#line 312 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 69:
#line 315 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 70:
#line 318 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 71:
#line 321 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 72:
#line 324 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 73:
#line 327 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 74:
#line 332 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;

  case 75:
#line 335 "cafezinho.yac"
    {
        (yyval.node) = NULL;
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2054 "sintatico.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 339 "cafezinho.yac"


void yyerror(const char *s) {
    printf("ERRO: %s in line %d\n", s, yylineno);
    exit(-1);
}

/**
 * main function
 */
int main(int argc, char* argv[]) {
    yyparse();
}

void generateTree(){

}

