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
#line 40 "parser.y" /* yacc.c:1909  */

	char *strValue;
	char cValue;
    int iValue;
    nodeType *nPtr;

#line 235 "parser.h" /* yacc.c:1909  */
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
