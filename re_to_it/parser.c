/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"
#include "parser.h"
#include "lexer.h"

int yylex(YYSTYPE * yylval_param, YYLTYPE * yylloc_param, yyscan_t yyscanner);
void yyerror(YYLTYPE *locp, void *scanner, nodeType **pTree, char const *szInput, int *countGroups, char const *msg);

#line 78 "parser.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_OR = 258,
    T_PLUS = 259,
    T_STAR = 260,
    T_QUESTION = 261,
    T_RANGE = 262,
    T_LPAREN = 263,
    T_RPAREN = 264,
    T_BEGIN_NEG_SET = 265,
    T_BEGIN_POS_SET = 266,
    T_END_SET = 267,
    T_ANY = 268,
    T_UNICODE_ANY = 269,
    T_LBRACE = 270,
    T_RBRACE = 271,
    T_COMMA = 272,
    T_OPEN_POSITIVE_LOOKAHEAD = 273,
    T_OPEN_NEGATIVE_LOOKAHEAD = 274,
    T_OPEN_POSITIVE_LOOKBEHIND = 275,
    T_OPEN_NEGATIVE_LOOKBEHIND = 276,
    T_KAPPA = 277,
    T_UNICODE_START = 278,
    T_UNICODE_START_NEG = 279,
    T_POSIX_ALNUM = 280,
    T_POSIX_ALPHA = 281,
    T_POSIX_ASCII = 282,
    T_POSIX_BLANK = 283,
    T_POSIX_CNTRL = 284,
    T_POSIX_DIGIT = 285,
    T_POSIX_GRAPH = 286,
    T_POSIX_LOWER = 287,
    T_POSIX_PRINT = 288,
    T_POSIX_PUNCT = 289,
    T_POSIX_SPACE = 290,
    T_POSIX_UPPER = 291,
    T_POSIX_WORD = 292,
    T_POSIX_XDIGIT = 293,
    T_CHAR = 294,
    T_SPECIAL = 295,
    T_NUL = 296,
    T_INTEGER = 297,
    T_BACKREF = 298,
    T_UNICODE_PROP_ID = 299,
    T_UNICODE_SCRIPT = 300,
    T_UNICODE_SCRIPT_NEG = 301,
    T_UNICODE_BLOCK = 302,
    T_UNICODE_BLOCK_NEG = 303,
    T_OCTAL = 304,
    T_HEX = 305,
    T_UNICODE = 306,
    T_UNICODE_INVALID = 307,
    T_POSIX_UNKNOWN = 308,
    T_POSIX_OUT = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "parser.y" /* yacc.c:355  */

	char *strValue;
	char cValue;
    int iValue;
    nodeType *nPtr;

#line 180 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (void * scanner, nodeType **pTree, char const *szInput, int *countGroups);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    75,    76,    77,    84,    91,    92,    93,
      97,   104,   105,   106,   107,   108,   111,   115,   119,   123,
     130,   134,   138,   145,   149,   153,   160,   164,   168,   175,
     190,   205,   220,   235,   250,   265,   280,   295,   310,   325,
     340,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   372,   380,   389,   398,   404,   414,   424,
     435,   441,   451,   461,   472,   488,   494,   500,   506,   512,
     518,   524,   530,   536,   542,   548,   554,   560,   566,   572,
     578,   584,   592,   603,   612,   626,   640,   654,   655,   659,
     666,   673,   674,   678,   679,   680,   681,   682,   683,   687,
     691,   695,   699,   703,   707,   711
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_OR", "T_PLUS", "T_STAR", "T_QUESTION",
  "T_RANGE", "T_LPAREN", "T_RPAREN", "T_BEGIN_NEG_SET", "T_BEGIN_POS_SET",
  "T_END_SET", "T_ANY", "T_UNICODE_ANY", "T_LBRACE", "T_RBRACE", "T_COMMA",
  "T_OPEN_POSITIVE_LOOKAHEAD", "T_OPEN_NEGATIVE_LOOKAHEAD",
  "T_OPEN_POSITIVE_LOOKBEHIND", "T_OPEN_NEGATIVE_LOOKBEHIND", "T_KAPPA",
  "T_UNICODE_START", "T_UNICODE_START_NEG", "T_POSIX_ALNUM",
  "T_POSIX_ALPHA", "T_POSIX_ASCII", "T_POSIX_BLANK", "T_POSIX_CNTRL",
  "T_POSIX_DIGIT", "T_POSIX_GRAPH", "T_POSIX_LOWER", "T_POSIX_PRINT",
  "T_POSIX_PUNCT", "T_POSIX_SPACE", "T_POSIX_UPPER", "T_POSIX_WORD",
  "T_POSIX_XDIGIT", "T_CHAR", "T_SPECIAL", "T_NUL", "T_INTEGER",
  "T_BACKREF", "T_UNICODE_PROP_ID", "T_UNICODE_SCRIPT",
  "T_UNICODE_SCRIPT_NEG", "T_UNICODE_BLOCK", "T_UNICODE_BLOCK_NEG",
  "T_OCTAL", "T_HEX", "T_UNICODE", "T_UNICODE_INVALID", "T_POSIX_UNKNOWN",
  "T_POSIX_OUT", "$accept", "goal", "re", "union", "simple_re",
  "concatenation", "basic_re", "lookaround", "star", "plus", "question",
  "reprange", "elementary_re", "group", "any", "unicode_any",
  "unicode_prop", "unicode_prop_neg", "backref", "char", "nul", "octal",
  "hex", "unicode", "set", "positive_set", "negative_set", "set_items",
  "set_item", "range", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     185,   185,   249,   249,   -72,   -72,   214,   246,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    27,    14,   -72,   104,   -72,   -72,   -72,   -72,   -72,
     -72,     1,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,    15,   -72,   -72,    47,
      85,    87,     9,   -72,   -72,   217,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   185,   185,   185,   185,   185,
     185,   -72,   -72,    22,    74,   102,     8,   -72,   313,   344,
     281,   -72,   -72,   -72,   151,    48,    49,    50,    88,   151,
     185,   185,   185,   185,   185,   185,    13,    -6,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,    40,   115,   -13,   142,   185,
     185,   145,    65,   185,   185,   -72,   -72,   185,   185,   146,
     -72,   -72,   -72,   -72,   185,   185,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    54,    55,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    65,    66,    83,    64,    84,    85,    86,    81,
      82,     0,     2,     3,     4,     7,     8,    11,    12,    13,
      14,    15,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    87,    88,     0,    95,    96,    97,
      98,    94,     0,    91,    93,     0,    56,    57,    58,    59,
      60,    61,    62,    63,     1,     0,     0,     0,     0,     0,
       0,    10,     9,    23,    20,    26,     0,    53,     0,     0,
       0,    90,    92,    89,     6,     0,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     103,   104,   102,   105,    99,    16,    17,    18,    19,    25,
      24,    22,    21,    28,    27,     0,    32,     0,    35,     0,
       0,    38,     0,     0,     0,    34,    33,     0,     0,    29,
      37,    36,    40,    39,     0,     0,    31,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,     7,   -72,   -71,   -72,   -34,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,    10,    28,    17,    12,   -72,    -1,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    95,    11,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    31,    32,    33,    34,    35,    36,    82,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    62,    63,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      81,    61,    61,   131,    94,    83,    84,    85,    56,    99,
     126,   127,    57,    57,    60,    60,    86,    75,    75,    59,
      59,    91,     4,     5,    87,   106,   100,    74,   101,   132,
      58,    58,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     107,    75,    75,    75,    88,   125,   128,   115,   116,   117,
      81,    61,    29,    30,    61,    81,   119,   120,   121,   122,
     123,   124,    57,    92,    60,    57,    92,    60,   102,    59,
     103,   139,    59,    95,    96,    97,    98,   109,   111,   114,
      58,    75,    89,    58,    90,   135,   136,   118,    65,   140,
     141,   110,   113,   142,   143,   108,   104,   112,   105,     0,
     146,   147,     1,     0,     2,     3,     0,     4,     5,   129,
       0,   130,    76,    77,    78,    79,    80,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   133,    25,   134,   137,
     144,   138,   145,    26,    27,    28,     0,    29,    30,     1,
       0,     2,     3,     0,     4,     5,     0,     0,     0,    76,
      77,    78,    79,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     1,    25,     2,     3,     0,     4,     5,
      26,    27,    28,     0,    29,    30,     0,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    93,
       4,     5,     0,     0,    26,    27,    28,     0,    29,    30,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    66,    67,
       0,    68,     4,     5,     0,     0,    69,     0,     0,     0,
      29,    30,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      70,     0,    71,     0,    72,     0,     0,     0,    73,     0,
       0,     0,    29,    30,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,     6,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30
};

static const yytype_int16 yycheck[] =
{
      34,     2,     3,    16,    75,     4,     5,     6,     1,    80,
      16,    17,     2,     3,     2,     3,    15,     3,     3,     2,
       3,    12,    13,    14,     9,    17,     4,     0,     6,    42,
       2,     3,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      42,     3,     3,     3,     7,    42,    16,     9,     9,     9,
      94,    62,    53,    54,    65,    99,   100,   101,   102,   103,
     104,   105,    62,    62,    62,    65,    65,    65,     4,    62,
       6,    16,    65,    76,    77,    78,    79,    88,    89,    90,
      62,     3,     7,    65,     7,   129,   130,     9,     3,   133,
     134,    89,    90,   137,   138,    88,     4,    90,     6,    -1,
     144,   145,     8,    -1,    10,    11,    -1,    13,    14,     4,
      -1,     6,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     4,    43,     6,     4,
       4,     6,     6,    49,    50,    51,    -1,    53,    54,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     8,    43,    10,    11,    -1,    13,    14,
      49,    50,    51,    -1,    53,    54,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    43,    12,
      13,    14,    -1,    -1,    49,    50,    51,    -1,    53,    54,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    44,    45,
      -1,    47,    13,    14,    -1,    -1,    52,    -1,    -1,    -1,
      53,    54,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      44,    -1,    46,    -1,    48,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    53,    54,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    10,    11,    13,    14,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    43,    49,    50,    51,    53,
      54,    56,    57,    58,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    57,    69,    70,    71,
      72,    74,    82,    83,    84,    82,    44,    45,    47,    52,
      44,    46,    48,    52,     0,     3,    18,    19,    20,    21,
      22,    61,    62,     4,     5,     6,    15,     9,     7,     7,
       7,    12,    83,    12,    59,    57,    57,    57,    57,    59,
       4,     6,     4,     6,     4,     6,    17,    42,    71,    74,
      72,    74,    71,    72,    74,     9,     9,     9,     9,    61,
      61,    61,    61,    61,    61,    42,    16,    17,    16,     4,
       6,    16,    42,     4,     6,    61,    61,     4,     6,    16,
      61,    61,    61,    61,     4,     6,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    58,    59,    59,    59,
      60,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    64,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    70,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    77,    78,    79,    79,    80,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       2,     4,     4,     2,     4,     4,     2,     4,     4,     6,
       8,     8,     4,     6,     6,     5,     7,     7,     5,     7,
       7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, scanner, pTree, szInput, countGroups, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, scanner, pTree, szInput, countGroups); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * scanner, nodeType **pTree, char const *szInput, int *countGroups)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pTree);
  YYUSE (szInput);
  YYUSE (countGroups);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void * scanner, nodeType **pTree, char const *szInput, int *countGroups)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner, pTree, szInput, countGroups);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void * scanner, nodeType **pTree, char const *szInput, int *countGroups)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, pTree, szInput, countGroups);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, pTree, szInput, countGroups); \
} while (0)

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
#ifndef YYINITDEPTH
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void * scanner, nodeType **pTree, char const *szInput, int *countGroups)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (pTree);
  YYUSE (szInput);
  YYUSE (countGroups);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void * scanner, nodeType **pTree, char const *szInput, int *countGroups)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 71 "parser.y" /* yacc.c:1646  */
    { *pTree = (yyvsp[0].nPtr); }
#line 1777 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 75 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1783 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1789 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 78 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_KAPPA, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 1797 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 1805 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1811 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1817 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(AST_LOOKAROUND, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1823 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_CONCATENATION, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));
				}
#line 1831 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1837 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1843 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1849 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1855 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1861 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 112 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_LOOKAHEAD, 1, (yyvsp[-1].nPtr));
				}
#line 1869 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_LOOKAHEAD, 1, (yyvsp[-1].nPtr));
				}
#line 1877 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_LOOKBEHIND, 1, (yyvsp[-1].nPtr));
				}
#line 1885 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 124 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_LOOKBEHIND, 1, (yyvsp[-1].nPtr));
				}
#line 1893 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_STAR, 1, (yyvsp[-1].nPtr));
				}
#line 1901 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 135 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_STAR, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1909 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_STAR, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1917 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 146 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_PLUS, 1, (yyvsp[-1].nPtr));
				}
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 150 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_PLUS, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1933 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_PLUS, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1941 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_QUESTION, 1, (yyvsp[-1].nPtr));
				}
#line 1949 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_QUESTION, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1957 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_QUESTION, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 1965 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-3].iValue);
					val2.iVal = (yyvsp[-1].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[-5].nPtr));
				}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 191 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-7].nPtr), (yyvsp[0].nPtr));
				}
#line 2003 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 206 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-7].nPtr), (yyvsp[0].nPtr));
				}
#line 2022 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-1].iValue);
					val2.iVal = (yyvsp[-1].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[-3].nPtr));
				}
#line 2041 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 236 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-3].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-5].nPtr), (yyvsp[0].nPtr));
				}
#line 2060 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 251 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-3].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-5].nPtr), (yyvsp[0].nPtr));
				}
#line 2079 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 266 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = (yyvsp[-1].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[-4].nPtr));
				}
#line 2098 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 281 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-6].nPtr), (yyvsp[0].nPtr));
				}
#line 2117 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 296 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-6].nPtr), (yyvsp[0].nPtr));
				}
#line 2136 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 311 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-2].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[-4].nPtr));
				}
#line 2155 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 326 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-4].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-6].nPtr), (yyvsp[0].nPtr));
				}
#line 2174 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 341 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-4].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-6].nPtr), (yyvsp[0].nPtr));
				}
#line 2193 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 358 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2199 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 359 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2205 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 360 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2211 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 361 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2217 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2223 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2229 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2235 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2241 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2247 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2253 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2259 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2265 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 373 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_GROUP, 1, (yyvsp[-1].nPtr));
					(*countGroups)++;
				}
#line 2274 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 381 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_ANY, val);
				}
#line 2284 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 390 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_UNICODE_ANY, val);
				}
#line 2294 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 399 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = (yyvsp[0].iValue);
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2304 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 405 "parser.y" /* yacc.c:1646  */
    {					
					Valore val;
					int len;					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE_SCRIPT, val);					
				}
#line 2318 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 415 "parser.y" /* yacc.c:1646  */
    {					
					Valore val;
					int len;					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE_BLOCK, val);					
				}
#line 2332 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 425 "parser.y" /* yacc.c:1646  */
    {
					char szError[1024];
					sprintf(szError, "riferimento a carattere unicode '%s' non valido.\n", (yyvsp[0].strValue));
					yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
					free((yyvsp[0].strValue));
					return 1;
				}
#line 2344 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 436 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = (yyvsp[0].iValue);
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2354 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 442 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE_SCRIPT_NEG, val);
				}
#line 2368 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 452 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE_BLOCK_NEG, val);
				}
#line 2382 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 462 "parser.y" /* yacc.c:1646  */
    {
					char szError[1024];
					sprintf(szError, "riferimento a carattere unicode '%s' non valido.\n", (yyvsp[0].strValue));
					yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
					free((yyvsp[0].strValue));
					return 1;
				}
#line 2394 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 473 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = (yyvsp[0].iValue);
					if ((yyvsp[0].iValue) > *countGroups )
					{
						char szError[1024];
						sprintf(szError, "backreference: riferimento a gruppo %d non valido. Ci sono soltanto %d gruppi.\n", (yyvsp[0].iValue), *countGroups);
						yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
						return 1;
					}
					(yyval.nPtr) = con(AST_BACKREF, val);
				}
#line 2411 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 489 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_CHAR, val);					
				}
#line 2421 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 495 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 2431 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 501 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_ALNUM, val);				
				}
#line 2441 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_ALPHA, val);				
				}
#line 2451 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 513 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_ASCII, val);				
				}
#line 2461 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 519 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_BLANK, val);				
				}
#line 2471 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 525 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_CNTRL, val);				
				}
#line 2481 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 531 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_DIGIT, val);				
				}
#line 2491 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 537 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_GRAPH, val);				
				}
#line 2501 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 543 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_LOWER, val);				
				}
#line 2511 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 549 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_PRINT, val);				
				}
#line 2521 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 555 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_PUNCT, val);				
				}
#line 2531 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 561 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_SPACE, val);				
				}
#line 2541 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 567 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_UPPER, val);				
				}
#line 2551 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 573 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_WORD, val);				
				}
#line 2561 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 579 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_POSIX_XDIGIT, val);
				}
#line 2571 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 585 "parser.y" /* yacc.c:1646  */
    {					
					char szError[1024];
					sprintf(szError, "classe di caratteri posix '%s' non valida.\n", (yyvsp[0].strValue));
					yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
					free((yyvsp[0].strValue));
					return 1;
				}
#line 2583 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 593 "parser.y" /* yacc.c:1646  */
    {					
					char szError[1024];
					sprintf(szError, "classe di caratteri posix '%s' non valida al di fuori di [].\n", (yyvsp[0].strValue));
					yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
					free((yyvsp[0].strValue));
					return 1;
				}
#line 2595 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 604 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_NUL, val);
				}
#line 2605 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 613 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;
					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_OCTAL, val);
				}
#line 2620 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 627 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;
					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_HEX, val);
				}
#line 2635 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 641 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;
					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE, val);
				}
#line 2650 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 654 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2656 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 655 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2662 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 660 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_SET, 1, (yyvsp[-1].nPtr));
				}
#line 2670 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 667 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_SET, 1, (yyvsp[-1].nPtr));
				}
#line 2678 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 673 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 2684 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 674 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AST_SET_ITEMS, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr)); }
#line 2690 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 678 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2696 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 679 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2702 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 680 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2708 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 681 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2714 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 682 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2720 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 683 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2726 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 688 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2734 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 692 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2742 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 696 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2750 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 700 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2758 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 704 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2766 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 708 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2774 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 712 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2782 "parser.c" /* yacc.c:1646  */
    break;


#line 2786 "parser.c" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, pTree, szInput, countGroups, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, pTree, szInput, countGroups, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, scanner, pTree, szInput, countGroups);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, scanner, pTree, szInput, countGroups);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, pTree, szInput, countGroups, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, pTree, szInput, countGroups);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, scanner, pTree, szInput, countGroups);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 717 "parser.y" /* yacc.c:1906  */


void yyerror(YYLTYPE *locp, void *scanner, nodeType **pTree, char const *szInput, int *countGroups, char const *msg)
{
	int i;
	
	UNUSED(pTree);
	UNUSED(countGroups);
	
	if ( yyget_extra(scanner)->bBegin )
	{
		locp->first_column++;
		locp->last_column++;
	}
	
    fprintf(stdout, "Errore colonne %d:%d -> %s\n", locp->first_column, locp->last_column, msg);
    fprintf(stdout, "%s\n", szInput);
    for(i = 0; i < locp->first_column; i++)
		fprintf(stdout, " ");
	for(i = 0; i <= (locp->last_column - locp->first_column); i++)
		fprintf(stdout, "^");
	fprintf(stdout, "\n");
}
