/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison interface for Yacc-like parsers in C

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
#line 40 "parser.y" /* yacc.c:1909  */

	char *strValue;
	char cValue;
    int iValue;
    nodeType *nPtr;

#line 116 "parser.h" /* yacc.c:1909  */
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
