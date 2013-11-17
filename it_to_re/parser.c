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
    T_KW_OPPURE = 258,
    T_KW_SEGUITO = 259,
    T_KW_PRECEDUTO = 260,
    T_KW_DA = 261,
    T_KW_DEL = 262,
    T_KW_A = 263,
    T_KW_AL = 264,
    T_KW_DI = 265,
    T_KW_ZERO = 266,
    T_KW_O = 267,
    T_KW_PIU = 268,
    T_KW_UNO = 269,
    T_KW_UNA = 270,
    T_KW_UN = 271,
    T_KW_SE = 272,
    T_KW_E = 273,
    T_KW_SOLO = 274,
    T_KW_NON = 275,
    T_KW_BACKSPACE = 276,
    T_KW_RIPETIZIONI = 277,
    T_KW_ALMENO = 278,
    T_KW_RILUTTANTE = 279,
    T_KW_POSSESSIVO = 280,
    T_KW_UNKNOWN = 281,
    T_KW_CARATTERE = 282,
    T_KW_CARATTERI = 283,
    T_KW_MA = 284,
    T_KW_IL = 285,
    T_KW_MATCH = 286,
    T_KW_RESTITUITO = 287,
    T_KW_SARA = 288,
    T_KW_QUALUNQUE = 289,
    T_KW_COMPRESO = 290,
    T_KW_COMPRESA = 291,
    T_KW_NEL = 292,
    T_KW_INSIEME = 293,
    T_KW_TRA = 294,
    T_KW_NE = 295,
    T_KW_TABULAZIONE = 296,
    T_KW_VERTICALE = 297,
    T_KW_RITORNO = 298,
    T_KW_CAPO = 299,
    T_KW_NUOVA = 300,
    T_KW_LINEA = 301,
    T_KW_AVANZAMENTO = 302,
    T_KW_MODULO = 303,
    T_KW_ALERT = 304,
    T_KW_ESCAPE = 305,
    T_KW_NUMERICO = 306,
    T_KW_QUALSIASI = 307,
    T_KW_SPAZIO = 308,
    T_KW_BIANCO = 309,
    T_KW_CHE = 310,
    T_KW_SIA = 311,
    T_KW_SPAZI = 312,
    T_KW_BIANCHI = 313,
    T_KW_SOTTOLINEATURA = 314,
    T_KW_ALFANUMERICO = 315,
    T_KW_DELIMITATORE = 316,
    T_KW_PAROLA = 317,
    T_KW_TRANNE = 318,
    T_KW_UNICODE = 319,
    T_KW_NULLO = 320,
    T_KW_NELL = 321,
    T_APICE = 322,
    T_KW_OTTALE = 323,
    T_KW_ESADECIMALE = 324,
    T_KW_CORRISPONDENTE = 325,
    T_KW_CODICE = 326,
    T_KW_GRUPPO = 327,
    T_KW_ALFABETICO = 328,
    T_KW_ASCII = 329,
    T_KW_CONTROLLO = 330,
    T_KW_VISIBILE = 331,
    T_KW_MINUSCOLA = 332,
    T_KW_MAIUSCOLA = 333,
    T_KW_MINUSCOLO = 334,
    T_KW_MAIUSCOLO = 335,
    T_KW_STAMPABILE = 336,
    T_KW_PUNTEGGIATURA = 337,
    T_KW_DIVERSO = 338,
    T_KW_LETTERA = 339,
    T_KW_POSIX = 340,
    T_KW_TIPO = 341,
    T_KW_LINGUA = 342,
    T_KW_HA = 343,
    T_KW_VARIANTE = 344,
    T_KW_IN = 345,
    T_KW_ALL = 346,
    T_KW_INIZIO = 347,
    T_KW_ENTRAMBE = 348,
    T_KW_LE = 349,
    T_KW_VARIANTI = 350,
    T_KW_ESISTE = 351,
    T_KW_SPECIALE = 352,
    T_KW_USATO = 353,
    T_KW_COME = 354,
    T_KW_IDEOGRAMMA = 355,
    T_KW_DESTINATO = 356,
    T_KW_AD = 357,
    T_KW_ESSERE = 358,
    T_KW_COMBINATO = 359,
    T_KW_CON = 360,
    T_KW_ALTRO = 361,
    T_KW_SENZA = 362,
    T_KW_OCCUPARE = 363,
    T_KW_OCCUPA = 364,
    T_KW_ULTERIORE = 365,
    T_KW_RACCHIUDE = 366,
    T_KW_VIENE = 367,
    T_KW_SEPARATORE = 368,
    T_KW_PARAGRAFO = 369,
    T_KW_SIMBOLO = 370,
    T_KW_SIMBOLI = 371,
    T_KW_MATEMATICO = 372,
    T_KW_MATEMATICI = 373,
    T_KW_VALUTA = 374,
    T_KW_COMBINAZIONE = 375,
    T_KW_SONO = 376,
    T_KW_SIANO = 377,
    T_KW_VARIE = 378,
    T_KW_VARI = 379,
    T_KW_SCRIPT = 380,
    T_KW_IDEOGRAFICI = 381,
    T_KW_NOVE = 382,
    T_KW_CIFRA = 383,
    T_KW_NUMERO = 384,
    T_KW_SIMILE = 385,
    T_KW_APICE = 386,
    T_KW_PEDICE = 387,
    T_KW_LINEETTA = 388,
    T_KW_TRATTINO = 389,
    T_KW_PARENTESI = 390,
    T_KW_VIRGOLETTE = 391,
    T_KW_APERTA = 392,
    T_KW_CHIUSA = 393,
    T_KW_APERTE = 394,
    T_KW_CHIUSE = 395,
    T_KW_CONNESSIONE = 396,
    T_KW_CITAZIONE = 397,
    T_KW_INVISIBILI = 398,
    T_KW_CODE = 399,
    T_KW_POINT = 400,
    T_KW_UTILIZZATI = 401,
    T_KW_LATIN1 = 402,
    T_KW_INDICATORE = 403,
    T_KW_FORMATTAZIONE = 404,
    T_KW_RISERVATO = 405,
    T_KW_USO = 406,
    T_KW_PRIVATO = 407,
    T_KW_PER = 408,
    T_KW_SURROGATI = 409,
    T_KW_CODIFICA = 410,
    T_KW_UTF16 = 411,
    T_KW_CUI = 412,
    T_KW_E_VERBO = 413,
    T_KW_STATO = 414,
    T_KW_ASSEGNATO = 415,
    T_KW_NESSUN = 416,
    T_LPAREN = 417,
    T_RPAREN = 418,
    T_BEGIN_NEG_SET = 419,
    T_BEGIN_POS_SET = 420,
    T_END_SET = 421,
    T_COMMA = 422,
    T_COLON = 423,
    T_DIV = 424,
    T_CHAR = 425,
    T_INTEGER = 426,
    T_STRING = 427,
    T_HEX = 428
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

#line 299 "parser.c" /* yacc.c:355  */
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

#line 327 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   860

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  174
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  705

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   428

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    94,    95,    96,   103,   110,   111,   112,
     116,   120,   126,   127,   128,   129,   130,   133,   137,   141,
     145,   152,   156,   160,   167,   171,   175,   182,   186,   190,
     197,   212,   227,   242,   257,   272,   287,   302,   317,   334,
     335,   336,   337,   338,   340,   341,   342,   343,   344,   345,
     346,   350,   357,   370,   379,   388,   394,   400,   406,   412,
     418,   424,   430,   436,   442,   448,   454,   460,   466,   472,
     478,   484,   490,   496,   502,   508,   514,   520,   526,   532,
     538,   544,   550,   556,   562,   568,   574,   580,   586,   592,
     598,   604,   610,   616,   622,   628,   634,   640,   646,   652,
     658,   664,   670,   676,   682,   688,   694,   700,   706,   712,
     718,   724,   730,   736,   742,   748,   754,   760,   766,   772,
     778,   784,   790,   796,   802,   808,   814,   820,   826,   832,
     838,   917,   933,   939,   945,   951,   957,   963,   969,   975,
     981,   987,   993,   999,  1005,  1011,  1017,  1023,  1029,  1035,
    1044,  1050,  1056,  1062,  1068,  1074,  1080,  1086,  1092,  1098,
    1104,  1110,  1116,  1122,  1128,  1134,  1140,  1146,  1152,  1158,
    1164,  1170,  1176,  1182,  1188,  1194,  1200,  1206,  1233,  1242,
    1260,  1274,  1296,  1297,  1301,  1309,  1316,  1317,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1336,  1340,  1344,  1348
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_KW_OPPURE", "T_KW_SEGUITO",
  "T_KW_PRECEDUTO", "T_KW_DA", "T_KW_DEL", "T_KW_A", "T_KW_AL", "T_KW_DI",
  "T_KW_ZERO", "T_KW_O", "T_KW_PIU", "T_KW_UNO", "T_KW_UNA", "T_KW_UN",
  "T_KW_SE", "T_KW_E", "T_KW_SOLO", "T_KW_NON", "T_KW_BACKSPACE",
  "T_KW_RIPETIZIONI", "T_KW_ALMENO", "T_KW_RILUTTANTE", "T_KW_POSSESSIVO",
  "T_KW_UNKNOWN", "T_KW_CARATTERE", "T_KW_CARATTERI", "T_KW_MA", "T_KW_IL",
  "T_KW_MATCH", "T_KW_RESTITUITO", "T_KW_SARA", "T_KW_QUALUNQUE",
  "T_KW_COMPRESO", "T_KW_COMPRESA", "T_KW_NEL", "T_KW_INSIEME", "T_KW_TRA",
  "T_KW_NE", "T_KW_TABULAZIONE", "T_KW_VERTICALE", "T_KW_RITORNO",
  "T_KW_CAPO", "T_KW_NUOVA", "T_KW_LINEA", "T_KW_AVANZAMENTO",
  "T_KW_MODULO", "T_KW_ALERT", "T_KW_ESCAPE", "T_KW_NUMERICO",
  "T_KW_QUALSIASI", "T_KW_SPAZIO", "T_KW_BIANCO", "T_KW_CHE", "T_KW_SIA",
  "T_KW_SPAZI", "T_KW_BIANCHI", "T_KW_SOTTOLINEATURA", "T_KW_ALFANUMERICO",
  "T_KW_DELIMITATORE", "T_KW_PAROLA", "T_KW_TRANNE", "T_KW_UNICODE",
  "T_KW_NULLO", "T_KW_NELL", "T_APICE", "T_KW_OTTALE", "T_KW_ESADECIMALE",
  "T_KW_CORRISPONDENTE", "T_KW_CODICE", "T_KW_GRUPPO", "T_KW_ALFABETICO",
  "T_KW_ASCII", "T_KW_CONTROLLO", "T_KW_VISIBILE", "T_KW_MINUSCOLA",
  "T_KW_MAIUSCOLA", "T_KW_MINUSCOLO", "T_KW_MAIUSCOLO", "T_KW_STAMPABILE",
  "T_KW_PUNTEGGIATURA", "T_KW_DIVERSO", "T_KW_LETTERA", "T_KW_POSIX",
  "T_KW_TIPO", "T_KW_LINGUA", "T_KW_HA", "T_KW_VARIANTE", "T_KW_IN",
  "T_KW_ALL", "T_KW_INIZIO", "T_KW_ENTRAMBE", "T_KW_LE", "T_KW_VARIANTI",
  "T_KW_ESISTE", "T_KW_SPECIALE", "T_KW_USATO", "T_KW_COME",
  "T_KW_IDEOGRAMMA", "T_KW_DESTINATO", "T_KW_AD", "T_KW_ESSERE",
  "T_KW_COMBINATO", "T_KW_CON", "T_KW_ALTRO", "T_KW_SENZA",
  "T_KW_OCCUPARE", "T_KW_OCCUPA", "T_KW_ULTERIORE", "T_KW_RACCHIUDE",
  "T_KW_VIENE", "T_KW_SEPARATORE", "T_KW_PARAGRAFO", "T_KW_SIMBOLO",
  "T_KW_SIMBOLI", "T_KW_MATEMATICO", "T_KW_MATEMATICI", "T_KW_VALUTA",
  "T_KW_COMBINAZIONE", "T_KW_SONO", "T_KW_SIANO", "T_KW_VARIE",
  "T_KW_VARI", "T_KW_SCRIPT", "T_KW_IDEOGRAFICI", "T_KW_NOVE",
  "T_KW_CIFRA", "T_KW_NUMERO", "T_KW_SIMILE", "T_KW_APICE", "T_KW_PEDICE",
  "T_KW_LINEETTA", "T_KW_TRATTINO", "T_KW_PARENTESI", "T_KW_VIRGOLETTE",
  "T_KW_APERTA", "T_KW_CHIUSA", "T_KW_APERTE", "T_KW_CHIUSE",
  "T_KW_CONNESSIONE", "T_KW_CITAZIONE", "T_KW_INVISIBILI", "T_KW_CODE",
  "T_KW_POINT", "T_KW_UTILIZZATI", "T_KW_LATIN1", "T_KW_INDICATORE",
  "T_KW_FORMATTAZIONE", "T_KW_RISERVATO", "T_KW_USO", "T_KW_PRIVATO",
  "T_KW_PER", "T_KW_SURROGATI", "T_KW_CODIFICA", "T_KW_UTF16", "T_KW_CUI",
  "T_KW_E_VERBO", "T_KW_STATO", "T_KW_ASSEGNATO", "T_KW_NESSUN",
  "T_LPAREN", "T_RPAREN", "T_BEGIN_NEG_SET", "T_BEGIN_POS_SET",
  "T_END_SET", "T_COMMA", "T_COLON", "T_DIV", "T_CHAR", "T_INTEGER",
  "T_STRING", "T_HEX", "$accept", "goal", "re", "union", "simple_re",
  "concatenation", "basic_re", "lookaround", "star", "plus", "question",
  "reprange", "elementary_re", "group", "string", "any", "unicode_any",
  "unicode_prop", "backref", "char", "posix_char", "nul", "octal", "hex",
  "unicode", "set", "positive_set", "negative_set", "set_items",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428
};
# endif

#define YYPACT_NINF -394

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-394)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    21,    99,   -16,   -93,   106,   105,     8,    18,  -394,
      66,  -394,   199,   178,  -394,     1,  -394,  -394,  -394,  -394,
    -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,  -394,
    -394,  -394,  -394,  -394,  -394,  -394,  -394,   223,   188,   295,
     171,   180,   157,  -394,     3,    67,   238,  -394,    18,   234,
     255,   222,  -394,  -394,    30,    30,    30,   323,    25,  -394,
     207,   236,   266,   272,   -52,  -394,   219,   280,   286,   253,
    -394,  -394,  -394,   282,    30,     5,    18,   291,   283,   235,
     239,   243,  -394,   279,   318,   294,   331,  -394,  -394,  -394,
     290,   301,   287,   352,   307,   357,    71,   333,   304,    30,
     330,   367,   252,  -394,   361,   347,  -394,  -394,  -394,  -394,
    -394,  -394,  -394,   336,  -394,   334,   343,   325,    82,   326,
    -394,    85,   -34,    45,    41,   374,    11,   376,   271,   378,
     237,   299,   226,   162,   256,  -394,    30,    18,    18,   203,
     359,  -394,  -394,   228,  -394,   335,   384,  -394,   -18,    53,
     109,   386,    17,   387,   284,   388,   246,   311,    63,    31,
     392,   353,   277,   337,   297,   308,   309,   389,   338,   400,
     404,    -2,   270,   -33,   362,   269,   265,   264,    27,   247,
     250,   249,    18,    18,   267,  -394,  -394,   417,   418,   289,
      18,    27,   385,   364,   230,    59,   419,   375,   298,   355,
     320,   339,   332,   412,   358,   425,   426,     0,   293,   -10,
     390,   300,   288,   285,   427,   345,   391,     4,   431,   313,
     -27,  -394,   439,   377,   420,   349,   350,   379,   314,   370,
      78,   340,  -394,   446,  -394,  -394,   436,   438,   310,   305,
     380,   433,    56,  -394,  -394,  -394,  -394,  -394,  -394,  -394,
     134,  -394,  -394,  -394,  -394,  -394,  -394,  -394,    18,    18,
     303,   306,   457,   460,     5,   150,   129,  -394,   451,   373,
     415,    29,   461,   342,    37,  -394,   463,   401,   444,   381,
     382,   402,   341,   394,    81,   360,  -394,   469,  -394,  -394,
     462,   466,   329,   327,   393,   397,   403,   406,   421,   481,
     478,  -394,  -394,   477,   483,   470,   414,   395,   441,   482,
    -394,    79,   447,   492,   491,   191,   179,  -394,   348,   383,
     430,  -394,  -394,    51,   214,   453,  -394,    27,  -394,  -394,
      18,    18,   346,   351,  -394,   450,   484,   410,   422,   428,
     429,   448,   506,   507,  -394,  -394,   503,   508,   494,   440,
     423,   467,   505,  -394,    97,   471,   516,   517,   193,   209,
    -394,   371,   409,   455,  -394,  -394,   479,   442,   518,   521,
     445,   405,   407,   454,   396,   432,  -394,   435,   522,   408,
     459,   456,   533,   495,   416,  -394,  -394,  -394,  -394,   528,
     434,  -394,   276,  -394,  -394,   292,   181,    33,   266,  -394,
     542,  -394,  -394,  -394,  -394,   547,   198,  -394,  -394,    20,
      22,    18,    18,  -394,   544,   500,   464,   541,   543,   468,
     437,   443,   475,   424,   449,  -394,   458,   545,   452,   480,
     476,   555,   520,   465,  -394,  -394,  -394,  -394,   548,   472,
    -394,   549,   485,   487,   488,   560,   490,   561,  -394,  -394,
     474,   558,   473,   486,   526,   531,   489,   497,  -394,   493,
     496,  -394,  -394,   573,  -394,  -394,    69,  -394,  -394,  -394,
    -394,  -394,  -394,   559,   534,   571,   572,   523,    93,   540,
    -394,   580,  -394,  -394,    23,    24,   536,   577,   499,   510,
     511,   591,   513,   592,  -394,  -394,   501,   590,   498,   502,
     553,   557,   504,   524,  -394,   509,   512,   525,   515,   529,
     530,   597,   563,   600,   519,   527,   565,   601,   602,   514,
     603,  -394,   532,   613,   585,  -394,  -394,   251,    33,    33,
      83,   574,   610,   611,  -394,   622,  -394,  -394,  -394,   546,
     550,   551,   552,   620,   584,   621,   535,   537,   593,   618,
     624,   538,   628,  -394,   539,   637,   562,   575,   570,   576,
     594,   554,   556,  -394,   -15,  -394,   564,   596,  -394,   582,
     566,   643,  -394,  -394,  -394,  -394,  -394,   605,   619,   606,
     607,   567,   589,   581,   595,   608,   568,   578,  -394,    -1,
    -394,   569,   615,  -394,   588,   579,   659,   598,   583,  -394,
    -394,  -394,   609,   623,   586,   604,  -394,   657,  -394,   587,
     599,  -394,  -394,  -394,  -394,   617,   612,  -394,  -394,  -394,
     625,   626,   614,   616,  -394,   660,  -394,   627,   630,   629,
     631,   632,   655,   633,   634,   635,   653,   670,   636,   639,
     638,   663,   640,   641,   642,   662,   672,   645,  -394,   644,
     646,   647,   648,   674,  -394,   677,   649,  -394,   651,   650,
     652,   656,   678,  -394,   682,  -394,  -394,   679,  -394,  -394,
     654,   658,  -394,  -394,   684,  -394,  -394,   661,   664,   665,
     685,  -394,   666,   691,  -394,   698,   667,   702,   668,   703,
     701,   705,   708,   709,   711,   714,   717,   673,   671,   675,
     676,  -394,  -394,  -394,  -394
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
       0,    52,     0,     2,     3,     4,     7,     8,    13,    14,
      15,    16,    12,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   182,   183,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     1,     0,     0,
       0,     0,    10,     9,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,   178,     0,     0,     0,     0,
      54,   143,    51,     0,     0,     6,     0,     0,     0,    21,
      27,    24,   140,   133,     0,     0,     0,   137,   139,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    11,     0,     0,    22,    23,    28,    29,
      25,    26,   134,     0,   136,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    53,     0,     0,     0,     0,
       0,   135,   138,     0,   144,     0,     0,   145,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,    81,    83,     0,     0,     0,     0,
       0,     0,     0,   191,   192,   189,   190,   195,   194,   193,
       0,   186,   188,   181,   179,   180,    37,    38,     0,     0,
       0,     0,     0,     0,     5,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,    82,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,   115,     0,     0,     0,     0,     0,     0,     0,
     103,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,   125,   127,     0,     0,     0,   184,     0,    31,    32,
       0,     0,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,   116,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,   126,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   109,   111,   113,     0,
       0,   123,     0,   164,   172,     0,     0,     0,   150,   176,
       0,   152,   154,   162,   166,     0,     0,   170,   187,     0,
       0,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   110,   112,   114,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,    99,   121,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,   165,   173,     0,   158,   168,     0,   151,   177,   153,
     155,   163,   167,     0,     0,     0,     0,     0,     0,     0,
     160,     0,    17,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   122,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,     0,     0,   159,   169,     0,     0,     0,
       0,     0,     0,     0,   161,     0,    18,    20,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    69,    79,     0,     0,    95,     0,
       0,     0,   156,   196,   199,   198,   197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    70,
      80,     0,     0,    96,     0,     0,     0,     0,     0,    57,
      59,    61,     0,     0,     0,     0,   119,     0,    77,     0,
       0,   171,   157,   175,   174,     0,     0,    58,    60,    62,
       0,     0,     0,     0,   120,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   129,     0,     0,    64,     0,     0,
       0,     0,     0,   130,     0,    67,    97,     0,    73,    71,
       0,     0,    68,    98,     0,    74,    72,     0,     0,     0,
       0,    93,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   117,   102,   118
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -394,  -394,    -8,  -394,   -45,  -394,   -13,  -394,  -394,  -394,
    -394,  -394,   173,  -394,  -394,  -171,  -133,  -394,  -394,  -177,
    -393,  -131,  -394,  -123,  -122,  -394,  -394,  -394,   669,   411,
    -394
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    53,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     246,    30,    31,    32,    33,    34,    35,    36,   250,   251,
     252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      44,   245,    52,    75,   476,    49,    48,   243,   231,    49,
     285,    39,     1,   234,   245,     2,     1,     3,    50,     2,
     243,     3,    50,    48,     4,    48,    48,    48,     4,     1,
      51,    95,     2,    37,     3,     5,   288,   218,   169,     5,
     604,     4,   240,   241,   205,   244,     3,   247,   240,   473,
     158,   163,     5,     6,   622,   248,   249,     6,   244,   297,
     247,   242,    52,   103,     5,   272,   194,   474,   248,   249,
       6,   392,   160,     7,    45,   214,    89,     7,    40,     6,
     196,   235,     6,    41,   340,     6,   122,   123,    46,   380,
       7,    90,   605,   301,   159,   298,   164,   170,   124,   125,
     148,   149,     7,   206,   289,   311,   623,   429,   354,   325,
     195,    38,   150,   151,   302,   232,    96,   286,   215,   199,
     341,   219,   145,   126,   185,   186,   171,   531,   393,   394,
     381,   312,   207,    41,   355,   574,   576,   152,   165,   335,
     216,   217,   166,   146,   525,   264,   532,   179,   430,   273,
     245,   526,   181,   533,   167,   172,   243,   344,    42,   336,
     161,   208,   313,     8,   200,   356,    72,     8,   197,   256,
     257,     9,    10,    11,   162,     9,    10,    11,   345,    43,
       8,    48,   198,   482,   127,   483,   536,   537,     9,    10,
      11,   466,     8,    68,   244,   128,   247,     9,   153,    47,
       9,    56,    11,     9,   248,   249,   201,   187,   188,   154,
     202,    71,   314,   315,   316,   357,   358,   359,   479,   129,
     475,   130,   203,   189,   395,   131,   179,    79,    80,    81,
     180,   181,    89,   155,   396,   156,    54,    55,    73,   157,
      76,   467,   268,    69,    70,   328,   329,   102,    74,   480,
     468,    52,    78,   397,   469,   470,    92,   471,   481,   106,
     107,   395,   472,   108,   109,    59,    60,   110,   111,    61,
      91,   396,   134,    77,   398,    63,   137,   138,    93,    65,
     182,   183,    94,   399,   400,   269,    97,   401,   402,    98,
     403,   258,   259,   262,   263,   404,    99,   405,   100,   406,
     326,   327,    59,    60,   101,    57,    61,   270,   271,   184,
     104,   398,    63,    82,   105,    58,   334,   327,   387,   388,
     399,   112,   409,   410,   401,   402,   113,   403,   385,   386,
     434,   435,   404,    83,   405,    84,   406,    85,   115,    86,
     114,    87,    88,   118,    82,   463,    59,    60,   436,   437,
      61,   573,   575,   461,   462,    62,    63,   116,   117,    64,
      65,    66,   119,   121,    83,    67,    84,   464,    85,   120,
      86,   132,    87,    88,   465,   133,   135,   136,   139,   140,
     141,   143,   142,   144,   168,   147,   173,   174,   175,   177,
     176,   178,   190,   191,   193,   192,   204,   209,   211,   212,
     210,   213,   220,   484,   485,   221,   225,   222,   224,   227,
     229,   226,   223,   228,   230,   233,   238,   236,   237,   239,
     253,   254,   255,   260,   261,   266,   267,   275,   276,   274,
     277,   278,   281,   282,   280,   283,   284,   279,   287,   292,
     293,   295,   299,   294,   300,   290,   296,   303,   306,   291,
     305,   304,   310,   307,   318,   308,   319,   309,   320,   317,
     324,   322,   321,   332,   323,   330,   333,   337,   331,   338,
     339,   346,   342,   343,   348,   347,   353,   361,   351,   360,
     349,   364,   362,   365,   352,   350,   363,   367,   370,   371,
     372,   368,   373,   366,   369,   374,   378,   375,   376,   377,
     379,   382,   383,   384,   390,   389,   391,   407,   411,   413,
     415,   414,   416,   412,   420,   419,   417,   418,   422,   421,
     423,   424,   427,   428,   425,   431,   432,   426,   438,   433,
     439,   440,   446,   443,   441,   442,   444,   445,   448,   447,
     451,   454,   452,   449,   450,   456,   455,   457,   459,   458,
     460,   477,   453,   478,   486,   487,   489,   488,   490,   494,
     491,   496,   500,   497,   492,   498,   501,   502,   505,   507,
     511,   495,   503,   513,   515,   493,   509,   510,   514,   508,
     512,   518,   516,   519,   521,   524,   527,   325,   506,   528,
     529,   534,   535,   540,   530,   538,   499,   539,   504,   541,
     542,   543,   520,   544,   545,   546,   547,   548,   550,   551,
     557,   553,   560,   556,   523,   561,   562,   552,   565,   558,
     559,   566,   567,   569,   563,   571,   572,   577,   578,   579,
     555,   517,   580,   564,   581,   585,   586,   587,   591,   568,
     588,   583,   584,   589,   592,   582,   590,   549,   594,   596,
     599,   522,   607,   610,   598,   600,   601,   597,   608,   611,
     612,   617,   615,   593,   626,   613,   614,   554,   616,   628,
     619,   625,   631,   635,   618,   650,   644,   629,   632,   602,
     654,   641,   655,   659,   664,   603,   670,   671,   640,   663,
     677,   570,   678,   620,   679,   633,   638,   686,   595,   682,
     668,   669,   667,   688,   689,   675,   674,   621,   691,   676,
     606,   648,   634,   694,   693,   624,   695,   697,   637,   657,
     696,   698,   699,   642,   643,   665,   609,   700,     0,   672,
       0,     0,     0,     0,     0,     0,     0,     0,   408,   627,
       0,     0,     0,   651,   652,     0,     0,     0,   636,   646,
     660,   661,   630,     0,     0,     0,     0,   649,     0,     0,
       0,     0,     0,   658,     0,     0,     0,     0,     0,   653,
     666,     0,     0,     0,     0,     0,   662,   673,   681,     0,
       0,   639,     0,     0,   684,     0,     0,     0,   645,   680,
       0,     0,     0,   685,   687,     0,   683,     0,   647,     0,
     701,     0,   703,     0,     0,   656,     0,     0,     0,   690,
     692,     0,   702,     0,     0,     0,     0,   704,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265
};

static const yytype_int16 yycheck[] =
{
       8,   178,    15,    48,   397,     4,     3,   178,    10,     4,
      10,    27,    11,    46,   191,    14,    11,    16,    17,    14,
     191,    16,    17,     3,    23,     3,     3,     3,    23,    11,
      29,    83,    14,    12,    16,    34,    46,     6,    27,    34,
      55,    23,    15,    16,    27,   178,    16,   178,    15,    16,
      84,    10,    34,    52,    55,   178,   178,    52,   191,    55,
     191,    34,    75,    76,    34,     6,    84,    34,   191,   191,
      52,    20,    27,    72,     8,    12,    51,    72,   171,    52,
      27,   114,    52,    27,    55,    52,    15,    16,    22,    10,
      72,    66,   107,   120,   128,    91,    55,    86,    27,    28,
      15,    16,    72,    86,   114,    27,   107,    10,    27,    53,
     128,    12,    27,    28,   141,   117,   168,   117,    55,    10,
      91,    90,    40,    52,   137,   138,   115,    34,    77,    78,
      51,    53,   115,    27,    53,   528,   529,    52,    97,    10,
      77,    78,   101,    61,    75,   190,    53,    64,    51,    90,
     327,    82,    69,    60,   113,   144,   327,   120,    53,    30,
     115,   144,    84,   162,    55,    84,   163,   162,   115,   182,
     183,   170,   171,   172,   129,   170,   171,   172,   141,   171,
     162,     3,   129,   163,   113,   163,   163,   163,   170,   171,
     172,    10,   162,    22,   327,   124,   327,   170,   113,     0,
     170,    13,   172,   170,   327,   327,    97,     4,     5,   124,
     101,    54,   134,   135,   136,   134,   135,   136,    20,   148,
     397,   150,   113,    20,    10,   154,    64,    54,    55,    56,
      68,    69,    51,   148,    20,   150,    13,    14,   171,   154,
       6,    60,    12,    63,    64,   258,   259,    74,    10,    51,
      69,   264,    30,    39,    73,    74,    20,    76,    60,    24,
      25,    10,    81,    24,    25,    51,    52,    24,    25,    55,
      63,    20,    99,    18,    60,    61,    24,    25,    12,    65,
      24,    25,    10,    69,    70,    55,    67,    73,    74,     9,
      76,    24,    25,     4,     5,    81,    10,    83,    45,    85,
     166,   167,    51,    52,    22,    10,    55,    77,    78,   136,
      19,    60,    61,    21,    31,    20,   166,   167,   139,   140,
      69,    42,   330,   331,    73,    74,     8,    76,   137,   138,
     137,   138,    81,    41,    83,    43,    85,    45,     7,    47,
      46,    49,    50,    56,    21,    53,    51,    52,   139,   140,
      55,   528,   529,    77,    78,    60,    61,    67,    57,    64,
      65,    66,    10,     6,    41,    70,    43,    75,    45,    62,
      47,    38,    49,    50,    82,    71,    46,    10,    17,    32,
      44,    38,    48,    58,    10,    59,    10,   116,    10,    90,
     153,   165,    33,   165,    10,    60,    10,    10,    10,   153,
     116,    90,    10,   411,   412,    52,    98,   130,   111,    20,
      10,   102,    75,    75,    10,   145,   151,    55,   149,   155,
     173,   171,   173,     6,     6,    40,    62,    52,   130,    10,
      75,   111,    20,    75,   102,    10,    10,    98,   145,   151,
     155,    96,    11,    16,   131,    55,    55,     8,    99,   149,
      30,    74,    82,   103,     8,    76,    20,   143,    20,   119,
      27,   156,   152,     6,    84,   162,     6,    16,   162,    96,
      55,     8,    11,   131,    30,    74,    82,     8,    76,   119,
      99,   152,    20,   156,   143,   103,    20,    90,    67,     8,
      12,    88,    15,   100,    88,    12,    55,    27,    84,   104,
      18,    54,    10,    12,   121,   157,    76,    54,   162,    59,
     100,    27,    90,   162,     8,    67,    88,    88,    15,    12,
      12,    27,    55,    18,    84,    54,    10,   104,   157,    12,
     121,    76,   127,    15,    55,    93,    15,    92,    84,   132,
     105,    82,    20,   147,   112,    12,    90,    52,    20,   133,
     116,     9,   144,     6,    10,    55,    15,    93,    15,    84,
      92,   112,    82,   105,   127,    20,    90,    12,    20,    20,
      10,   147,    52,    12,    16,   132,    89,    89,   104,    94,
      90,    55,   109,    52,    87,    12,    27,    53,   116,    18,
      18,    51,    12,    94,    71,    59,   144,    20,   133,    89,
      89,    10,   113,    90,    12,   104,    16,   109,    55,    52,
      95,    87,    15,    88,   118,    52,    16,   113,    53,    90,
      90,    20,    20,    20,   105,    12,    41,    53,    18,    18,
     118,   145,    10,   106,    88,    15,    52,    16,    20,   125,
     105,    90,    90,   106,    20,    95,    53,   145,    20,    12,
      80,   158,    56,    10,    79,    79,    62,    95,    76,    54,
      41,    80,    95,   125,    76,    59,    59,   158,    79,    10,
      62,    56,    63,    16,    79,    20,    16,    79,    55,   125,
      27,    55,    12,    20,    12,   129,    12,    10,    63,    27,
      12,   159,    10,   125,    15,   109,    79,    12,   159,    15,
      53,    53,    56,    12,     6,    53,    56,   129,     6,    53,
     146,    80,   108,    12,    11,   146,    11,     8,   119,    80,
      12,    10,     8,   109,   108,    80,   160,    10,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,   160,
      -1,    -1,    -1,   110,   110,    -1,    -1,    -1,   161,   119,
     110,   110,   169,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,   134,
     126,    -1,    -1,    -1,    -1,    -1,   134,   126,   120,    -1,
      -1,   169,    -1,    -1,   120,    -1,    -1,    -1,   161,   135,
      -1,    -1,    -1,   128,   128,    -1,   135,    -1,   169,    -1,
     127,    -1,   127,    -1,    -1,   169,    -1,    -1,    -1,   142,
     142,    -1,   141,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    14,    16,    23,    34,    52,    72,   162,   170,
     171,   172,   175,   176,   177,   178,   179,   180,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     195,   196,   197,   198,   199,   200,   201,    12,    12,    27,
     171,    27,    53,   171,   176,     8,    22,     0,     3,     4,
      17,    29,   180,   181,    13,    14,    13,    10,    20,    51,
      52,    55,    60,    61,    64,    65,    66,    70,    22,    63,
      64,    54,   163,   171,    10,   178,     6,    18,    30,   186,
     186,   186,    21,    41,    43,    45,    47,    49,    50,    51,
      66,    63,    20,    12,    10,    83,   168,    67,     9,    10,
      45,    22,   186,   180,    19,    31,    24,    25,    24,    25,
      24,    25,    42,     8,    46,     7,    67,    57,    56,    10,
      62,     6,    15,    16,    27,    28,    52,   113,   124,   148,
     150,   154,    38,    71,   186,    46,    10,    24,    25,    17,
      32,    44,    48,    38,    58,    40,    61,    59,    15,    16,
      27,    28,    52,   113,   124,   148,   150,   154,    84,   128,
      27,   115,   129,    10,    55,    97,   101,   113,    10,    27,
      86,   115,   144,    10,   116,    10,   153,    90,   165,    64,
      68,    69,    24,    25,   186,   180,   180,     4,     5,    20,
      33,   165,    60,    10,    84,   128,    27,   115,   129,    10,
      55,    97,   101,   113,    10,    27,    86,   115,   144,    10,
     116,    10,   153,    90,    12,    55,    77,    78,     6,    90,
      10,    52,   130,    75,   111,    98,   102,    20,    75,    10,
      10,    10,   117,   145,    46,   114,    55,   149,   151,   155,
      15,    16,    34,   189,   190,   193,   194,   195,   197,   198,
     202,   203,   204,   173,   171,   173,   180,   180,    24,    25,
       6,     6,     4,     5,   178,   202,    40,    62,    12,    55,
      77,    78,     6,    90,    10,    52,   130,    75,   111,    98,
     102,    20,    75,    10,    10,    10,   117,   145,    46,   114,
      55,   149,   151,   155,    16,    96,    55,    55,    91,    11,
     131,   120,   141,     8,    74,    30,    99,   103,    76,   143,
      82,    27,    53,    84,   134,   135,   136,   119,     8,    20,
      20,   152,   156,    84,    27,    53,   166,   167,   180,   180,
     162,   162,     6,     6,   166,    10,    30,    16,    96,    55,
      55,    91,    11,   131,   120,   141,     8,    74,    30,    99,
     103,    76,   143,    82,    27,    53,    84,   134,   135,   136,
     119,     8,    20,    20,   152,   156,   100,    90,    88,    88,
      67,     8,    12,    15,    12,    27,    84,   104,    55,    18,
      10,    51,    54,    10,    12,   137,   138,   139,   140,   157,
     121,    76,    20,    77,    78,    10,    20,    39,    60,    69,
      70,    73,    74,    76,    81,    83,    85,    54,   203,   176,
     176,   162,   162,    59,    27,   100,    90,    88,    88,    67,
       8,    12,    15,    12,    27,    84,   104,    55,    18,    10,
      51,    54,    10,    12,   137,   138,   139,   140,   157,   121,
      76,    55,    93,    15,    15,    92,   127,   132,    84,   147,
     112,   105,    20,   144,    82,    90,    12,    52,   133,    20,
     116,    77,    78,    53,    75,    82,    10,    60,    69,    73,
      74,    76,    81,    16,    34,   193,   194,     9,     6,    20,
      51,    60,   163,   163,   176,   176,    10,    55,    93,    15,
      15,    92,   127,   132,    84,   147,   112,   105,    20,   144,
      82,    90,    12,    52,   133,    20,   116,    20,    94,    89,
      89,    10,    90,    12,   104,    16,   109,   145,    55,    52,
     113,    87,   158,   118,    12,    75,    82,    27,    18,    18,
      71,    34,    53,    60,    51,    12,   163,   163,    59,    20,
      94,    89,    89,    10,    90,    12,   104,    16,   109,   145,
      55,    52,   113,    87,   158,   118,    88,    95,    90,    90,
      15,    52,    16,   105,   106,    53,    20,    20,   125,    20,
     159,    12,    41,   193,   194,   193,   194,    53,    18,    18,
      10,    88,    95,    90,    90,    15,    52,    16,   105,   106,
      53,    20,    20,   125,    20,   159,    12,    95,    79,    80,
      79,    62,   125,   129,    55,   107,   146,    56,    76,   160,
      10,    54,    41,    59,    59,    95,    79,    80,    79,    62,
     125,   129,    55,   107,   146,    56,    76,   160,    10,    79,
     169,    63,    55,   109,   108,    16,   161,   119,    79,   169,
      63,    55,   109,   108,    16,   161,   119,   169,    80,   125,
      20,   110,   110,   134,    27,    12,   169,    80,   125,    20,
     110,   110,   134,    27,    12,    80,   126,    56,    53,    53,
      12,    10,    80,   126,    56,    53,    53,    12,    10,    15,
     135,   120,    15,   135,   120,   128,    12,   128,    12,     6,
     142,     6,   142,    11,    12,    11,    12,     8,    10,     8,
      10,   127,   141,   127,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   174,   175,   176,   176,   176,   177,   178,   178,   178,
     179,   179,   180,   180,   180,   180,   180,   181,   181,   181,
     181,   182,   182,   182,   183,   183,   183,   184,   184,   184,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   186,
     186,   186,   186,   186,   186,   186,   186,   186,   186,   186,
     186,   187,   188,   189,   190,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   192,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   195,   196,
     197,   198,   199,   199,   200,   201,   202,   202,   203,   203,
     203,   203,   203,   203,   203,   203,   204,   204,   204,   204
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     7,     3,     1,     1,     2,
       2,     4,     1,     1,     1,     1,     1,     9,    10,     9,
      10,     4,     5,     5,     4,     5,     5,     4,     5,     5,
       6,     8,     8,     4,     6,     6,     5,     7,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     5,     3,    11,    12,    13,    14,    13,
      14,    13,    14,    15,    16,     9,    10,    16,    17,    12,
      13,    16,    17,    16,    17,    12,    13,    13,    14,    12,
      13,     7,     8,     7,     8,     7,     8,     7,     8,     8,
       9,     8,     9,    17,    18,    12,    13,    16,    17,    10,
      11,    22,    23,     8,     9,    10,    11,     9,    10,     9,
      10,     9,    10,     9,    10,     8,     9,    22,    23,    13,
      14,    10,    11,     9,    10,     8,     9,     8,     9,    15,
      16,     2,     1,     4,     5,     6,     5,     4,     6,     4,
       4,     3,     4,     3,     6,     6,    12,    10,     5,     8,
       3,     4,     3,     4,     3,     4,     6,     7,     4,     5,
       4,     5,     3,     4,     3,     4,     3,     4,     4,     5,
       3,     7,     3,     4,     7,     7,     3,     4,     3,     7,
       7,     7,     1,     1,     8,     9,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     6,     6,     6
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
#line 90 "parser.y" /* yacc.c:1646  */
    { *pTree = (yyvsp[0].nPtr); }
#line 2237 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 94 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2243 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2249 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 97 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_KAPPA, 2, (yyvsp[-6].nPtr), (yyvsp[0].nPtr));
				}
#line 2257 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 104 "parser.y" /* yacc.c:1646  */
    {										
					(yyval.nPtr) = opr(AST_OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2265 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2271 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2277 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = opr(AST_LOOKAROUND, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 2283 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_CONCATENATION, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));					
				}
#line 2291 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_CONCATENATION, 2, (yyvsp[-3].nPtr), (yyvsp[0].nPtr));
				}
#line 2299 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2305 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2311 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2317 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2323 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2329 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_LOOKAHEAD, 1, (yyvsp[-1].nPtr));
				}
#line 2337 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_LOOKAHEAD, 1, (yyvsp[-1].nPtr));
				}
#line 2345 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_LOOKBEHIND, 1, (yyvsp[-1].nPtr));
				}
#line 2353 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 146 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_LOOKBEHIND, 1, (yyvsp[-1].nPtr));
				}
#line 2361 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_STAR, 1, (yyvsp[0].nPtr));
				}
#line 2369 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 157 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_STAR, 1, (yyvsp[-1].nPtr));
				}
#line 2377 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_STAR, 1, (yyvsp[-1].nPtr));
				}
#line 2385 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 168 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_PLUS, 1, (yyvsp[0].nPtr));
				}
#line 2393 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_PLUS, 1, (yyvsp[-1].nPtr));
				}
#line 2401 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_PLUS, 1, (yyvsp[-1].nPtr));
				}
#line 2409 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 183 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_QUESTION, 1, (yyvsp[0].nPtr));
				}
#line 2417 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_LAZY_QUESTION, 1, (yyvsp[-1].nPtr));
				}
#line 2425 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSSESSIVE_QUESTION, 1, (yyvsp[-1].nPtr));
				}
#line 2433 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 198 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[0].nPtr));
				}
#line 2452 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 213 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-7].iValue);
					val2.iVal = (yyvsp[-5].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2471 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-7].iValue);
					val2.iVal = (yyvsp[-5].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2490 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 243 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-3].iValue);
					val2.iVal = (yyvsp[-3].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[0].nPtr));
				}
#line 2509 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 258 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = (yyvsp[-5].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2528 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 273 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = (yyvsp[-5].iValue);
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2547 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 288 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-3].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_REPRANGE, 3, p1, p2, (yyvsp[0].nPtr));
				}
#line 2566 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 303 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_LAZY_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2585 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 318 "parser.y" /* yacc.c:1646  */
    {
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = (yyvsp[-5].iValue);
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					(yyval.nPtr) = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 2604 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 334 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2610 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2616 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2622 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 337 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2628 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2634 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2640 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2646 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2652 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 343 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2658 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2664 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2670 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 2676 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 351 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_GROUP, 1, (yyvsp[-1].nPtr));
					(*countGroups)++;
				}
#line 2685 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 358 "parser.y" /* yacc.c:1646  */
    {					
					Valore val;
					int len;					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_STRING, val);					
				}
#line 2699 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 371 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_ANY, val);
				}
#line 2709 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 380 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_UNICODE_ANY, val);
				}
#line 2719 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2729 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 395 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2739 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 401 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Lowercase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2749 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 407 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Lowercase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2759 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 413 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Uppercase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2769 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 419 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Uppercase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2779 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 425 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Titlecase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2789 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 431 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Titlecase_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2799 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 437 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Cased_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2809 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 443 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Cased_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2819 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 449 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Modifier_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2829 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 455 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Modifier_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2839 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 461 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Other_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2849 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 467 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Other_Letter;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2859 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 473 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2869 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 479 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2879 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 485 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Non_Spacing_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2889 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 491 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Non_Spacing_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2899 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 497 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Spacing_Combining_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2909 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 503 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Spacing_Combining_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2919 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 509 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Enclosing_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2929 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 515 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Enclosing_Mark;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2939 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 521 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2949 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 527 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2959 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 533 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Space_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2969 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 539 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Space_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2979 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 545 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Line_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2989 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 551 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Line_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 2999 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 557 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Paragraph_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3009 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 563 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Paragraph_Separator;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3019 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 569 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3029 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 575 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3039 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 581 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Math_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3049 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 587 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Math_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3059 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 593 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Currency_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3069 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 599 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Currency_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3079 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 605 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Modifier_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3089 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 611 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Modifier_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3099 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 617 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Other_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3109 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 623 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Other_Symbol;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3119 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 629 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3129 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 635 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3139 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 641 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Decimal_Digit_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3149 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 647 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Decimal_Digit_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3159 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 653 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Letter_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3169 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 659 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Letter_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3179 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 665 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Other_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3189 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 671 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Other_Number;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3199 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 677 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3209 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 683 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3219 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 689 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Dash_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3229 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 695 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Dash_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3239 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 701 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Open_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3249 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 707 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Open_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3259 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 713 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Close_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3269 "parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 719 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Close_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3279 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 725 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Initial_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3289 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 731 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Initial_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3299 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 737 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Final_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3309 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 743 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Final_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3319 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 749 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Connector_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3329 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 755 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Connector_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3339 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 761 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Other_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3349 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 767 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Other_Punctuation;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3359 "parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 773 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Other;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3369 "parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 779 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Other;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3379 "parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 785 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Control;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3389 "parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 791 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Control;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3399 "parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 797 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Format;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3409 "parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 803 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Format;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3419 "parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 809 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Private_Use;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3429 "parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 815 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Private_Use;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3439 "parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 821 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Surrogate;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3449 "parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 827 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Surrogate;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3459 "parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 833 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = UPROP_Unassigned;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3469 "parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 839 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.iVal = -UPROP_Unassigned;
					(yyval.nPtr) = con(AST_UNICODE_PROP, val);
				}
#line 3479 "parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 918 "parser.y" /* yacc.c:1646  */
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
#line 3496 "parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 934 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = (yyvsp[0].cValue);
					(yyval.nPtr) = con(AST_CHAR, val);					
				}
#line 3506 "parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 940 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 't';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);				
				}
#line 3516 "parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 946 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'v';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);				
				}
#line 3526 "parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 952 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'r';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);				
				}
#line 3536 "parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 958 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'n';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3546 "parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 964 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'a';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3556 "parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 970 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'f';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3566 "parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 976 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'e';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3576 "parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 982 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'b';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3586 "parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 988 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'd';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3596 "parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 994 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'D';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3606 "parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1000 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 's';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3616 "parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'S';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3626 "parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1012 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'w';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3636 "parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1018 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'W';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3646 "parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1024 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'W';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3656 "parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1030 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'b';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3666 "parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1036 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = 'B';
					(yyval.nPtr) = con(AST_SPECIALCHAR, val);
				}
#line 3676 "parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1045 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_ALNUM, val);
				}
#line 3686 "parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1051 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_ALNUM, val);
				}
#line 3696 "parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1057 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_ALPHA, val);				
				}
#line 3706 "parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1063 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_ALPHA, val);
				}
#line 3716 "parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1069 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_ASCII, val);				
				}
#line 3726 "parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1075 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_ASCII, val);
				}
#line 3736 "parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1081 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_BLANK, val);				
				}
#line 3746 "parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1087 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_BLANK, val);
				}
#line 3756 "parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1093 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_CNTRL, val);				
				}
#line 3766 "parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1099 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_CNTRL, val);
				}
#line 3776 "parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1105 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_DIGIT, val);				
				}
#line 3786 "parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1111 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_DIGIT, val);
				}
#line 3796 "parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1117 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_GRAPH, val);				
				}
#line 3806 "parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_GRAPH, val);
				}
#line 3816 "parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1129 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_LOWER, val);				
				}
#line 3826 "parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1135 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_LOWER, val);
				}
#line 3836 "parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1141 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_PRINT, val);				
				}
#line 3846 "parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1147 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_PRINT, val);
				}
#line 3856 "parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1153 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_PUNCT, val);				
				}
#line 3866 "parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_PUNCT, val);
				}
#line 3876 "parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1165 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_SPACE, val);				
				}
#line 3886 "parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1171 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_SPACE, val);
				}
#line 3896 "parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1177 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_UPPER, val);				
				}
#line 3906 "parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1183 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_UPPER, val);
				}
#line 3916 "parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1189 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_WORD, val);				
				}
#line 3926 "parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1195 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_WORD, val);
				}
#line 3936 "parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1201 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '.';
					(yyval.nPtr) = con(AST_POSIX_XDIGIT, val);				
				}
#line 3946 "parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1207 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '^';
					(yyval.nPtr) = con(AST_POSIX_XDIGIT, val);
				}
#line 3956 "parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1234 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					val.cVal = '\0';
					(yyval.nPtr) = con(AST_NUL, val);
				}
#line 3966 "parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1243 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					
					if ( (yyvsp[0].iValue) > 377 )
					{
						char szError[1024];
						sprintf(szError, "codice ottale non valido '%d'.\n", (yyvsp[0].iValue));
						yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
						return 1;
					}					
										
					val.iVal = (yyvsp[0].iValue);
					(yyval.nPtr) = con(AST_OCTAL, val);
				}
#line 3985 "parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1261 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;
					
					len = strlen((yyvsp[0].strValue));
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_HEX, val);
				}
#line 4000 "parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1275 "parser.y" /* yacc.c:1646  */
    {
					Valore val;
					int len;					
					
					len = strlen((yyvsp[0].strValue));
					if ( len > 4 )
					{
						char szError[1024];
						sprintf(szError, "codice unicode non valido '%s'. Deve essere formato da 4 cifre esadecimali.\n", (yyvsp[0].strValue));
						yyerror(&(yylsp[0]), scanner, pTree, szInput, countGroups, szError);
						return 1;
					}					
					
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, (yyvsp[0].strValue), len + 1);
					free((yyvsp[0].strValue));
					(yyval.nPtr) = con(AST_UNICODE, val);
				}
#line 4023 "parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1296 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4029 "parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1297 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4035 "parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1302 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_POSITIVE_SET, 1, (yyvsp[-1].nPtr));
				}
#line 4043 "parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1310 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_NEGATIVE_SET, 1, (yyvsp[-1].nPtr));
				}
#line 4051 "parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1316 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 4057 "parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1317 "parser.y" /* yacc.c:1646  */
    { (yyval.nPtr) = opr(AST_SET_ITEMS, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 4063 "parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1321 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4069 "parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1322 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4075 "parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1323 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4081 "parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1324 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4087 "parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1325 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4093 "parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1326 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4099 "parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1327 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4105 "parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1328 "parser.y" /* yacc.c:1646  */
    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 4111 "parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1337 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 4119 "parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1341 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 4127 "parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1345 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 4135 "parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1349 "parser.y" /* yacc.c:1646  */
    {
					(yyval.nPtr) = opr(AST_RANGE, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
				}
#line 4143 "parser.c" /* yacc.c:1646  */
    break;


#line 4147 "parser.c" /* yacc.c:1646  */
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
#line 1380 "parser.y" /* yacc.c:1906  */


void yyerror(YYLTYPE *locp, void *scanner, nodeType **pTree, char const *szInput, int *countGroups, char const *msg)
{
	int i;
	char *szLine;
	
	UNUSED(scanner);
	UNUSED(pTree);
	UNUSED(countGroups);
	
	/*
	if ( yyget_extra(scanner)->bBegin )
	{
		locp->first_column++;
		locp->last_column++;
	}
	*/
	
    fprintf(stdout, "Errore linea %d colonne %d:%d -> %s\n", locp->first_line, locp->first_column, locp->last_column, msg);	
	
	szLine = readLine(szInput, locp->first_line);
	if ( !szLine )
		return;
	
    fprintf(stdout, "%s\n", szLine);
    for(i = 0; i < locp->first_column - 1; i++)
		fprintf(stdout, " ");
	for(i = 0; i <= (locp->last_column - locp->first_column); i++)
		fprintf(stdout, "^");
	fprintf(stdout, "\n");
	
	free(szLine);
}
