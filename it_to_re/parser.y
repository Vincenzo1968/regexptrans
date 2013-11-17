/*
   Copyright (C) 2013 Vincenzo Lo Cicero

   Author: Vincenzo Lo Cicero.
   e-mail: vincenzo.locicero@libero.it
       
   This file is part of retoit.

   retoit is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   retoit is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with retoit.  If not, see <http://www.gnu.org/licenses/>.
*/

%define api.pure full
%locations
%define parse.lac full
%define parse.error verbose

%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast.h"
#include "parser.h"
#include "lexer.h"

int yylex(YYSTYPE * yylval_param, YYLTYPE * yylloc_param, yyscan_t yyscanner);
void yyerror(YYLTYPE *locp, void *scanner, nodeType **pTree, char const *szInput, int *countGroups, char const *msg);
%}

%union {
	char *strValue;
	char cValue;
    int iValue;
    nodeType *nPtr;
};

%token T_KW_OPPURE T_KW_SEGUITO T_KW_PRECEDUTO T_KW_DA T_KW_DEL T_KW_A T_KW_AL T_KW_DI T_KW_ZERO T_KW_O T_KW_PIU T_KW_UNO T_KW_UNA 
%token T_KW_UN T_KW_SE T_KW_E T_KW_SOLO T_KW_NON T_KW_BACKSPACE
%token T_KW_RIPETIZIONI T_KW_ALMENO T_KW_RILUTTANTE T_KW_POSSESSIVO T_KW_UNKNOWN T_KW_CARATTERE T_KW_CARATTERI
%token T_KW_MA T_KW_IL T_KW_MATCH T_KW_RESTITUITO T_KW_SARA T_KW_QUALUNQUE T_KW_COMPRESO T_KW_COMPRESA T_KW_NEL T_KW_INSIEME T_KW_TRA T_KW_NE
%token T_KW_TABULAZIONE T_KW_VERTICALE T_KW_RITORNO T_KW_CAPO T_KW_NUOVA T_KW_LINEA T_KW_AVANZAMENTO T_KW_MODULO
%token T_KW_ALERT T_KW_ESCAPE T_KW_NUMERICO T_KW_QUALSIASI T_KW_SPAZIO T_KW_BIANCO T_KW_CHE T_KW_SIA T_KW_SPAZI T_KW_BIANCHI
%token T_KW_SOTTOLINEATURA T_KW_ALFANUMERICO T_KW_DELIMITATORE T_KW_PAROLA T_KW_TRANNE T_KW_UNICODE T_KW_NULLO T_KW_NELL T_APICE
%token T_KW_OTTALE T_KW_ESADECIMALE T_KW_CORRISPONDENTE T_KW_CODICE T_KW_GRUPPO T_KW_ALFABETICO T_KW_ASCII T_KW_CONTROLLO T_KW_VISIBILE
%token T_KW_MINUSCOLA T_KW_MAIUSCOLA T_KW_MINUSCOLO T_KW_MAIUSCOLO T_KW_STAMPABILE T_KW_PUNTEGGIATURA T_KW_DIVERSO T_KW_LETTERA T_KW_POSIX
%token T_KW_TIPO T_KW_LINGUA T_KW_HA T_KW_VARIANTE T_KW_IN T_KW_ALL T_KW_INIZIO T_KW_ENTRAMBE T_KW_LE T_KW_VARIANTI T_KW_ESISTE 
%token T_KW_SPECIALE T_KW_USATO T_KW_COME T_KW_IDEOGRAMMA T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_ALTRO
%token T_KW_SENZA T_KW_OCCUPARE T_KW_OCCUPA T_KW_ULTERIORE T_KW_RACCHIUDE T_KW_VIENE T_KW_SEPARATORE T_KW_PARAGRAFO T_KW_SIMBOLO T_KW_SIMBOLI
%token T_KW_MATEMATICO T_KW_MATEMATICI T_KW_VALUTA T_KW_COMBINAZIONE T_KW_SONO T_KW_SIANO T_KW_VARIE T_KW_VARI T_KW_SCRIPT 
%token T_KW_IDEOGRAFICI T_KW_NOVE T_KW_CIFRA T_KW_NUMERO T_KW_SIMILE T_KW_APICE T_KW_PEDICE T_KW_LINEETTA T_KW_TRATTINO 
%token T_KW_PARENTESI T_KW_VIRGOLETTE T_KW_APERTA T_KW_CHIUSA T_KW_APERTE T_KW_CHIUSE T_KW_CONNESSIONE T_KW_CITAZIONE 
%token T_KW_INVISIBILI T_KW_CODE T_KW_POINT T_KW_UTILIZZATI T_KW_LATIN1 T_KW_INDICATORE T_KW_FORMATTAZIONE T_KW_RISERVATO T_KW_USO T_KW_PRIVATO
%token T_KW_PER T_KW_SURROGATI T_KW_CODIFICA T_KW_UTF16 T_KW_CUI T_KW_E_VERBO T_KW_STATO T_KW_ASSEGNATO T_KW_NESSUN T_KW_BLOCCO T_KW_ALLA T_KW_APPARTENGA

%token T_LPAREN T_RPAREN T_BEGIN_NEG_SET T_BEGIN_POS_SET T_END_SET T_COMMA T_COLON T_DIV
%token <cValue> T_CHAR
%token <iValue> T_INTEGER
%token <strValue> T_STRING T_HEX T_UNICODE_SCRIPT T_UNICODE_BLOCK

/*
%token T_OPEN_POSITIVE_LOOKAHEAD T_OPEN_NEGATIVE_LOOKAHEAD T_OPEN_POSITIVE_LOOKBEHIND T_OPEN_NEGATIVE_LOOKBEHIND
%token T_KAPPA T_UNICODE_START T_UNICODE_START_NEG
%token <cValue> T_POSIX_ALNUM T_POSIX_ALPHA T_POSIX_ASCII T_POSIX_BLANK T_POSIX_CNTRL T_POSIX_DIGIT T_POSIX_GRAPH
%token <cValue> T_POSIX_LOWER T_POSIX_PRINT T_POSIX_PUNCT T_POSIX_SPACE T_POSIX_UPPER T_POSIX_WORD T_POSIX_XDIGIT
%token <strValue> T_POSIX_UNKNOWN T_POSIX_OUT
*/

%type <nPtr> string char posix_char any unicode_any unicode_prop /*unicode_prop-neg*/ backref nul octal hex unicode
%type <nPtr> goal re union simple_re concatenation basic_re star plus question reprange
%type <nPtr> lookaround group elementary_re set positive_set negative_set set_items set_item range

%lex-param {void * scanner}
%parse-param {void * scanner}
%parse-param {nodeType **pTree}
%parse-param {char const *szInput}
%parse-param {int *countGroups}

%%

goal:			re { *pTree = $1; }
				;

re:
				union {$$ = $1;}
				| simple_re {$$ = $1;}
				| simple_re T_KW_MA T_KW_IL T_KW_MATCH T_KW_RESTITUITO T_KW_SARA simple_re
				{
					$$ = opr(AST_KAPPA, 2, $1, $7);
				}				
				;
								
union:
				re T_KW_OPPURE simple_re
				{										
					$$ = opr(AST_OR, 2, $1, $3);
				}
				;
				
simple_re:
				concatenation {$$ = $1;}
				| basic_re {$$ = $1;}
				| simple_re lookaround {$$ = opr(AST_LOOKAROUND, 2, $1, $2);}
				;

concatenation:
				simple_re basic_re
				{
					$$ = opr(AST_CONCATENATION, 2, $1, $2);					
				}
				| simple_re T_KW_SEGUITO T_KW_DA basic_re
				{
					$$ = opr(AST_CONCATENATION, 2, $1, $4);
				}
				;
				
basic_re:		elementary_re {$$ = $1;}
				| star {$$ = $1;}
				| plus {$$ = $1;}
				| question {$$ = $1;}
				| reprange {$$ = $1;}
				;
				
lookaround:		T_KW_SE T_KW_E T_KW_SOLO T_KW_SE T_KW_SEGUITO T_KW_DA T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_POSITIVE_LOOKAHEAD, 1, $8);
				}
				| T_KW_SE T_KW_E T_KW_SOLO T_KW_SE T_KW_NON T_KW_SEGUITO T_KW_DA T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_NEGATIVE_LOOKAHEAD, 1, $9);
				}
				| T_KW_SE T_KW_E T_KW_SOLO T_KW_SE T_KW_PRECEDUTO T_KW_DA T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_POSITIVE_LOOKBEHIND, 1, $8);
				}
				| T_KW_SE T_KW_E T_KW_SOLO T_KW_SE T_KW_NON T_KW_PRECEDUTO T_KW_DA T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_NEGATIVE_LOOKBEHIND, 1, $9);
				}
				;				
			
star:
				T_KW_ZERO T_KW_O T_KW_PIU elementary_re
				{
					$$ = opr(AST_STAR, 1, $4);
				}
				| T_KW_ZERO T_KW_O T_KW_PIU elementary_re T_KW_RILUTTANTE
				{
					$$ = opr(AST_LAZY_STAR, 1, $4);
				}
				| T_KW_ZERO T_KW_O T_KW_PIU elementary_re T_KW_POSSESSIVO
				{
					$$ = opr(AST_POSSESSIVE_STAR, 1, $4);
				}				
				;
								
plus:
				T_KW_UNO T_KW_O T_KW_PIU elementary_re
				{
					$$ = opr(AST_PLUS, 1, $4);
				}
				| T_KW_UNO T_KW_O T_KW_PIU elementary_re T_KW_RILUTTANTE
				{
					$$ = opr(AST_LAZY_PLUS, 1, $4);
				}
				| T_KW_UNO T_KW_O T_KW_PIU elementary_re T_KW_POSSESSIVO
				{
					$$ = opr(AST_POSSESSIVE_PLUS, 1, $4);
				}				
				;
				
question:
				T_KW_ZERO T_KW_O T_KW_UNO elementary_re
				{
					$$ = opr(AST_QUESTION, 1, $4);
				}
				| T_KW_ZERO T_KW_O T_KW_UNO elementary_re T_KW_RILUTTANTE
				{
					$$ = opr(AST_LAZY_QUESTION, 1, $4);
				}
				| T_KW_ZERO T_KW_O T_KW_UNO elementary_re T_KW_POSSESSIVO
				{
					$$ = opr(AST_POSSESSIVE_QUESTION, 1, $4);
				}								
				;
				
reprange:
				T_INTEGER T_KW_A T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $6);
				}				
				| T_INTEGER T_KW_A T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_RILUTTANTE basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $6, $8);
				}	
				| T_INTEGER T_KW_A T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_POSSESSIVO basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $6, $8);
				}					
				| T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $1;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $4);
				}	
				| T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_RILUTTANTE basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $1;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $4, $6);
				}
				| T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_POSSESSIVO basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $1;
					val2.iVal = $1;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $4, $6);
				}				
				| T_KW_ALMENO T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $2;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $5);
				}
				| T_KW_ALMENO T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_RILUTTANTE basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $2;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $5, $7);
				}
				| T_KW_ALMENO T_INTEGER T_KW_RIPETIZIONI T_KW_DI elementary_re T_KW_POSSESSIVO basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $2;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $5, $7);
				}				
					
elementary_re:
				group {$$ = $1;}
				| string {$$ = $1;}
				| any {$$ = $1;}
				| unicode_any {$$ = $1;}
				| unicode_prop {$$ = $1;}
				/* | unicode_prop_neg {$$ = $1;} */
				| backref {$$ = $1;}
				| char {$$ = $1;}
				| nul {$$ = $1;}
				| octal {$$ = $1;}
				| hex {$$ = $1;}
				| unicode {$$ = $1;}
				| set {$$ = $1;}
				;

group:
				T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_GROUP, 1, $2);
					(*countGroups)++;
				}
				;
												
string:			T_STRING
				{					
					Valore val;
					int len;					
					len = strlen($1);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $1, len + 1);
					free($1);
					$$ = con(AST_STRING, val);					
				}				
				;

any:
				T_KW_QUALUNQUE T_KW_CARATTERE T_KW_TRANNE T_KW_NUOVA T_KW_LINEA
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_ANY, val);
				}				
				;

unicode_any:
				T_KW_QUALUNQUE T_KW_CARATTERE T_KW_UNICODE
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_UNICODE_ANY, val);
				}				
				;

unicode_prop:	
				T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_LETTERA T_KW_DI T_KW_QUALSIASI T_KW_LINGUA
				{
					Valore val;
					val.iVal = UPROP_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_LETTERA T_KW_DI T_KW_QUALSIASI T_KW_LINGUA
				{
					Valore val;
					val.iVal = -UPROP_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_LETTERA T_KW_MINUSCOLA T_KW_CHE T_KW_HA T_KW_UNA T_KW_VARIANTE T_KW_IN T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = UPROP_Lowercase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_LETTERA T_KW_MINUSCOLA T_KW_CHE T_KW_HA T_KW_UNA T_KW_VARIANTE T_KW_IN T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = -UPROP_Lowercase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}												
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_LETTERA T_KW_MAIUSCOLA T_KW_CHE T_KW_HA T_KW_UNA T_KW_VARIANTE T_KW_IN T_KW_MINUSCOLO
				{
					Valore val;
					val.iVal = UPROP_Uppercase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_LETTERA T_KW_MAIUSCOLA T_KW_CHE T_KW_HA T_KW_UNA T_KW_VARIANTE T_KW_IN T_KW_MINUSCOLO
				{
					Valore val;
					val.iVal = -UPROP_Uppercase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_LETTERA T_KW_MAIUSCOLA T_KW_ALL T_APICE T_KW_INIZIO T_KW_DI T_KW_UNA T_KW_PAROLA
				{
					Valore val;
					val.iVal = UPROP_Titlecase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_LETTERA T_KW_MAIUSCOLA T_KW_ALL T_APICE T_KW_INIZIO T_KW_DI T_KW_UNA T_KW_PAROLA
				{
					Valore val;
					val.iVal = -UPROP_Titlecase_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_LETTERA T_KW_CHE T_KW_ESISTE T_KW_IN T_KW_ENTRAMBE T_KW_LE T_KW_VARIANTI T_KW_MINUSCOLO T_DIV T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = UPROP_Cased_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_LETTERA T_KW_CHE T_KW_ESISTE T_KW_IN T_KW_ENTRAMBE T_KW_LE T_KW_VARIANTI T_KW_MINUSCOLO T_DIV T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = -UPROP_Cased_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_SPECIALE T_KW_USATO T_KW_COME T_KW_LETTERA
				{
					Valore val;
					val.iVal = UPROP_Modifier_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_SPECIALE T_KW_USATO T_KW_COME T_KW_LETTERA
				{
					Valore val;
					val.iVal = -UPROP_Modifier_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_LETTERA T_KW_O T_KW_UN T_KW_IDEOGRAMMA T_KW_CHE T_KW_NON T_KW_HA T_KW_VARIANTI T_KW_MINUSCOLO T_DIV T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = UPROP_Other_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_LETTERA T_KW_O T_KW_UN T_KW_IDEOGRAMMA T_KW_CHE T_KW_NON T_KW_HA T_KW_VARIANTI T_KW_MINUSCOLO T_DIV T_KW_MAIUSCOLO
				{
					Valore val;
					val.iVal = -UPROP_Other_Letter;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO
				{
					Valore val;
					val.iVal = UPROP_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO
				{
					Valore val;
					val.iVal = -UPROP_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO T_KW_SENZA T_KW_OCCUPARE T_KW_ULTERIORE T_KW_SPAZIO
				{
					Valore val;
					val.iVal = UPROP_Non_Spacing_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO T_KW_SENZA T_KW_OCCUPARE T_KW_ULTERIORE T_KW_SPAZIO
				{
					Valore val;
					val.iVal = -UPROP_Non_Spacing_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO T_KW_CHE T_KW_OCCUPA T_KW_ULTERIORE T_KW_SPAZIO
				{
					Valore val;
					val.iVal = UPROP_Spacing_Combining_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_DESTINATO T_KW_AD T_KW_ESSERE T_KW_COMBINATO T_KW_CON T_KW_UN T_KW_ALTRO T_KW_CHE T_KW_OCCUPA T_KW_ULTERIORE T_KW_SPAZIO
				{
					Valore val;
					val.iVal = -UPROP_Spacing_Combining_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_CHE T_KW_RACCHIUDE T_KW_IL T_KW_CARATTERE T_KW_VIENE T_KW_COMBINATO T_KW_CON
				{
					Valore val;
					val.iVal = UPROP_Enclosing_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_CHE T_KW_RACCHIUDE T_KW_IL T_KW_CARATTERE T_KW_VIENE T_KW_COMBINATO T_KW_CON
				{
					Valore val;
					val.iVal = -UPROP_Enclosing_Mark;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_SPAZIO T_KW_BIANCO T_KW_O T_KW_SEPARATORE T_KW_NON T_KW_VISIBILE
				{
					Valore val;
					val.iVal = UPROP_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_SPAZIO T_KW_BIANCO T_KW_O T_KW_SEPARATORE T_KW_NON T_KW_VISIBILE
				{
					Valore val;
					val.iVal = -UPROP_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_SEPARATORE T_KW_NON T_KW_VISIBILE T_KW_CHE T_KW_NON T_KW_OCCUPA T_KW_SPAZIO
				{
					Valore val;
					val.iVal = UPROP_Space_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_SEPARATORE T_KW_NON T_KW_VISIBILE T_KW_CHE T_KW_NON T_KW_OCCUPA T_KW_SPAZIO
				{
					Valore val;
					val.iVal = -UPROP_Space_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_SEPARATORE T_KW_DI T_KW_LINEA
				{
					Valore val;
					val.iVal = UPROP_Line_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_SEPARATORE T_KW_DI T_KW_LINEA
				{
					Valore val;
					val.iVal = -UPROP_Line_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_SEPARATORE T_KW_DI T_KW_PARAGRAFO
				{
					Valore val;
					val.iVal = UPROP_Paragraph_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_SEPARATORE T_KW_DI T_KW_PARAGRAFO
				{
					Valore val;
					val.iVal = -UPROP_Paragraph_Separator;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UN T_KW_SIMBOLO T_KW_QUALSIASI
				{
					Valore val;
					val.iVal = UPROP_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UN T_KW_SIMBOLO T_KW_QUALSIASI
				{
					Valore val;
					val.iVal = -UPROP_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_SIMBOLO T_KW_MATEMATICO
				{
					Valore val;
					val.iVal = UPROP_Math_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_SIMBOLO T_KW_MATEMATICO
				{
					Valore val;
					val.iVal = -UPROP_Math_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_SIMBOLO T_KW_DI T_KW_VALUTA
				{
					Valore val;
					val.iVal = UPROP_Currency_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_SIMBOLO T_KW_DI T_KW_VALUTA
				{
					Valore val;
					val.iVal = -UPROP_Currency_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_COMBINAZIONE
				{
					Valore val;
					val.iVal = UPROP_Modifier_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_COMBINAZIONE
				{
					Valore val;
					val.iVal = -UPROP_Modifier_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_VARI T_KW_SIMBOLI T_KW_CHE T_KW_NON T_KW_SONO T_KW_SIMBOLI T_KW_MATEMATICI T_KW_O T_KW_DI T_KW_VALUTA T_KW_O T_KW_DI T_KW_COMBINAZIONE
				{
					Valore val;
					val.iVal = UPROP_Other_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_VARI T_KW_SIMBOLI T_KW_CHE T_KW_NON T_KW_SONO T_KW_SIMBOLI T_KW_MATEMATICI T_KW_O T_KW_DI T_KW_VALUTA T_KW_O T_KW_DI T_KW_COMBINAZIONE
				{
					Valore val;
					val.iVal = -UPROP_Other_Symbol;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_CARATTERE T_KW_NUMERICO T_KW_IN T_KW_QUALSIASI T_KW_SCRIPT
				{
					Valore val;
					val.iVal = UPROP_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_CARATTERE T_KW_NUMERICO T_KW_IN T_KW_QUALSIASI T_KW_SCRIPT
				{
					Valore val;
					val.iVal = -UPROP_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_CIFRA T_KW_DA T_KW_ZERO T_KW_A T_KW_NOVE T_KW_IN T_KW_QUALSIASI T_KW_SCRIPT T_KW_TRANNE T_KW_SCRIPT T_KW_IDEOGRAFICI
				{
					Valore val;
					val.iVal = UPROP_Decimal_Digit_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_CIFRA T_KW_DA T_KW_ZERO T_KW_A T_KW_NOVE T_KW_IN T_KW_QUALSIASI T_KW_SCRIPT T_KW_TRANNE T_KW_SCRIPT T_KW_IDEOGRAFICI
				{
					Valore val;
					val.iVal = -UPROP_Decimal_Digit_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UN T_KW_NUMERO T_KW_SIMILE T_KW_A T_KW_UNA T_KW_LETTERA
				{
					Valore val;
					val.iVal = UPROP_Letter_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UN T_KW_NUMERO T_KW_SIMILE T_KW_A T_KW_UNA T_KW_LETTERA
				{
					Valore val;
					val.iVal = -UPROP_Letter_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UNA T_KW_CIFRA T_KW_IN T_KW_APICE T_KW_O T_KW_PEDICE T_KW_O T_KW_UN T_KW_NUMERO T_KW_CHE T_KW_NON T_KW_SIA T_KW_UNA T_KW_CIFRA T_KW_DA T_KW_ZERO T_KW_A T_KW_NOVE
				{
					Valore val;
					val.iVal = UPROP_Other_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UNA T_KW_CIFRA T_KW_IN T_KW_APICE T_KW_O T_KW_PEDICE T_KW_O T_KW_UN T_KW_NUMERO T_KW_CHE T_KW_NON T_KW_SIA T_KW_UNA T_KW_CIFRA T_KW_DA T_KW_ZERO T_KW_A T_KW_NOVE
				{
					Valore val;
					val.iVal = -UPROP_Other_Number;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_CARATTERE T_KW_DI T_KW_PUNTEGGIATURA
				{
					Valore val;
					val.iVal = UPROP_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_CARATTERE T_KW_DI T_KW_PUNTEGGIATURA
				{
					Valore val;
					val.iVal = -UPROP_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_TRATTINO T_KW_O T_KW_LINEETTA
				{
					Valore val;
					val.iVal = UPROP_Dash_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_TRATTINO T_KW_O T_KW_LINEETTA
				{
					Valore val;
					val.iVal = -UPROP_Dash_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_PARENTESI T_KW_APERTA
				{
					Valore val;
					val.iVal = UPROP_Open_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_PARENTESI T_KW_APERTA
				{
					Valore val;
					val.iVal = -UPROP_Open_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_PARENTESI T_KW_CHIUSA
				{
					Valore val;
					val.iVal = UPROP_Close_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_PARENTESI T_KW_CHIUSA
				{
					Valore val;
					val.iVal = -UPROP_Close_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_VIRGOLETTE T_KW_APERTE
				{
					Valore val;
					val.iVal = UPROP_Initial_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_VIRGOLETTE T_KW_APERTE
				{
					Valore val;
					val.iVal = -UPROP_Initial_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_VIRGOLETTE T_KW_CHIUSE
				{
					Valore val;
					val.iVal = UPROP_Final_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_VIRGOLETTE T_KW_CHIUSE
				{
					Valore val;
					val.iVal = -UPROP_Final_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_CONNESSIONE
				{
					Valore val;
					val.iVal = UPROP_Connector_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_CONNESSIONE
				{
					Valore val;
					val.iVal = -UPROP_Connector_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_CARATTERE T_KW_DI T_KW_PUNTEGGIATURA T_KW_CHE T_KW_NON T_KW_SIA T_KW_UN T_KW_TRATTINO T_KW_O T_KW_PARENTESI T_KW_O T_KW_CITAZIONE T_KW_O T_KW_DI T_KW_CONNESSIONE
				{
					Valore val;
					val.iVal = UPROP_Other_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_TIPO T_KW_DI T_KW_CARATTERE T_KW_DI T_KW_PUNTEGGIATURA T_KW_CHE T_KW_NON T_KW_SIA T_KW_UN T_KW_TRATTINO T_KW_O T_KW_PARENTESI T_KW_O T_KW_CITAZIONE T_KW_O T_KW_DI T_KW_CONNESSIONE
				{
					Valore val;
					val.iVal = -UPROP_Other_Punctuation;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERI T_KW_DI T_KW_CONTROLLO T_KW_INVISIBILI T_KW_E T_KW_CODE T_KW_POINT T_KW_NON T_KW_UTILIZZATI
				{
					Valore val;
					val.iVal = UPROP_Other;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERI T_KW_DI T_KW_CONTROLLO T_KW_INVISIBILI T_KW_E T_KW_CODE T_KW_POINT T_KW_NON T_KW_UTILIZZATI
				{
					Valore val;
					val.iVal = -UPROP_Other;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_CARATTERE T_KW_DI T_KW_CONTROLLO T_KW_ASCII T_KW_O T_KW_LATIN1
				{
					Valore val;
					val.iVal = UPROP_Control;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_CARATTERE T_KW_DI T_KW_CONTROLLO T_KW_ASCII T_KW_O T_KW_LATIN1
				{
					Valore val;
					val.iVal = -UPROP_Control;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_INDICATORE T_KW_DI T_KW_FORMATTAZIONE T_KW_NON T_KW_VISIBILE
				{
					Valore val;
					val.iVal = UPROP_Format;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_INDICATORE T_KW_DI T_KW_FORMATTAZIONE T_KW_NON T_KW_VISIBILE
				{
					Valore val;
					val.iVal = -UPROP_Format;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_RISERVATO T_KW_PER T_KW_USO T_KW_PRIVATO
				{
					Valore val;
					val.iVal = UPROP_Private_Use;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_RISERVATO T_KW_PER T_KW_USO T_KW_PRIVATO
				{
					Valore val;
					val.iVal = -UPROP_Private_Use;
					$$ = con(AST_UNICODE_PROP, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_SURROGATI T_KW_IN T_KW_CODIFICA T_KW_UTF16
				{
					Valore val;
					val.iVal = UPROP_Surrogate;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_SURROGATI T_KW_IN T_KW_CODIFICA T_KW_UTF16
				{
					Valore val;
					val.iVal = -UPROP_Surrogate;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_COLON T_KW_QUALSIASI T_KW_CODE T_KW_POINT T_KW_A T_KW_CUI T_KW_NON T_KW_E_VERBO T_KW_STATO T_KW_ASSEGNATO T_KW_NESSUN T_KW_CARATTERE
				{
					Valore val;
					val.iVal = UPROP_Unassigned;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_DIVERSO T_KW_DA T_KW_QUALSIASI T_KW_CODE T_KW_POINT T_KW_A T_KW_CUI T_KW_NON T_KW_E_VERBO T_KW_STATO T_KW_ASSEGNATO T_KW_NESSUN T_KW_CARATTERE
				{
					Valore val;
					val.iVal = -UPROP_Unassigned;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_CHE T_KW_APPARTENGA T_KW_ALLA T_KW_LINGUA T_UNICODE_SCRIPT
				{					
					Valore val;
					int len;					
					len = strlen($8);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $8, len + 1);
					free($8);
					$$ = con(AST_UNICODE_SCRIPT, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_CHE T_KW_NON T_KW_APPARTENGA T_KW_ALLA T_KW_LINGUA T_UNICODE_SCRIPT
				{					
					Valore val;
					int len;					
					len = strlen($9);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $9, len + 1);
					free($9);
					$$ = con(AST_UNICODE_SCRIPT_NEG, val);					
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_NEL T_KW_BLOCCO T_UNICODE_BLOCK
				{					
					Valore val;
					int len;					
					len = strlen($6);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $6, len + 1);
					free($6);
					$$ = con(AST_UNICODE_BLOCK, val);					
				}
				| T_KW_UN T_KW_CARATTERE T_KW_UNICODE T_KW_CHE T_KW_NON T_KW_APPARTENGA T_KW_AL T_KW_BLOCCO T_UNICODE_BLOCK
				{					
					Valore val;
					int len;					
					len = strlen($9);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $9, len + 1);
					free($9);
					$$ = con(AST_UNICODE_BLOCK_NEG, val);					
				}
				/*
				| T_UNICODE_START T_UNICODE_INVALID
				{
					char szError[1024];
					sprintf(szError, "riferimento a carattere unicode '%s' non valido.\n", $2);
					yyerror(&@2, scanner, pTree, szInput, countGroups, szError);
					free($2);
					return 1;
				}
				*/
				;				
				
backref:
				T_KW_GRUPPO T_INTEGER 
				{
					Valore val;
					val.iVal = $2;
					if ($2 > *countGroups )
					{
						char szError[1024];
						sprintf(szError, "backreference: riferimento a gruppo %d non valido. Ci sono soltanto %d gruppi.\n", $2, *countGroups);
						yyerror(&@2, scanner, pTree, szInput, countGroups, szError);
						return 1;
					}
					$$ = con(AST_BACKREF, val);
				}				
				;

char:
				T_CHAR 
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_CHAR, val);					
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_TABULAZIONE
				{
					Valore val;
					val.cVal = 't';
					$$ = con(AST_SPECIALCHAR, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_TABULAZIONE T_KW_VERTICALE
				{
					Valore val;
					val.cVal = 'v';
					$$ = con(AST_SPECIALCHAR, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_RITORNO T_KW_A T_KW_CAPO
				{
					Valore val;
					val.cVal = 'r';
					$$ = con(AST_SPECIALCHAR, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_NUOVA T_KW_LINEA
				{
					Valore val;
					val.cVal = 'n';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_ALERT
				{
					Valore val;
					val.cVal = 'a';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_AVANZAMENTO T_KW_DEL T_KW_MODULO
				{
					Valore val;
					val.cVal = 'f';
					$$ = con(AST_SPECIALCHAR, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_ESCAPE
				{
					Valore val;
					val.cVal = 'e';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_BACKSPACE
				{
					Valore val;
					val.cVal = 'b';
					$$ = con(AST_SPECIALCHAR, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_NUMERICO
				{
					Valore val;
					val.cVal = 'd';
					$$ = con(AST_SPECIALCHAR, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_NUMERICO
				{
					Valore val;
					val.cVal = 'D';
					$$ = con(AST_SPECIALCHAR, val);
				}								
				| T_KW_QUALSIASI T_KW_SPAZIO T_KW_BIANCO
				{
					Valore val;
					val.cVal = 's';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_QUALSIASI T_KW_TRANNE T_KW_SPAZI T_KW_BIANCHI
				{
					Valore val;
					val.cVal = 'S';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_ALFANUMERICO T_KW_O T_KW_DI T_KW_SOTTOLINEATURA
				{
					Valore val;
					val.cVal = 'w';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_CHE T_KW_NON T_KW_SIA T_KW_NE T_KW_ALFANUMERICO T_KW_NE T_KW_IL T_KW_CARATTERE T_KW_DI T_KW_SOTTOLINEATURA
				{
					Valore val;
					val.cVal = 'W';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_CHE T_KW_NON T_KW_SIA T_KW_NE T_KW_ALFANUMERICO T_KW_NE T_KW_DI T_KW_SOTTOLINEATURA
				{
					Valore val;
					val.cVal = 'W';
					$$ = con(AST_SPECIALCHAR, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_DELIMITATORE T_KW_DI T_KW_PAROLA
				{
					Valore val;
					val.cVal = 'b';
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_CHE T_KW_NON T_KW_SIA T_KW_DELIMITATORE T_KW_DI T_KW_PAROLA
				{
					Valore val;
					val.cVal = 'B';
					$$ = con(AST_SPECIALCHAR, val);
				}
				;		
				
posix_char:		
				T_KW_UN T_KW_CARATTERE T_KW_ALFANUMERICO
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_ALNUM, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_ALFANUMERICO
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_ALNUM, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_ALFABETICO 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_ALPHA, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_ALFABETICO 
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_ALPHA, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_ASCII 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_ASCII, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_ASCII 
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_ASCII, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_SPAZIO T_KW_O T_KW_TABULAZIONE 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_BLANK, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DIVERSO T_KW_DA T_KW_SPAZIO T_KW_E T_KW_TABULAZIONE  
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_BLANK, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_CONTROLLO 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_CNTRL, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_DI T_KW_CONTROLLO 
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_CNTRL, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_POSIX T_KW_NUMERICO
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_DIGIT, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_POSIX T_KW_NON T_KW_NUMERICO
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_DIGIT, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_VISIBILE 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_GRAPH, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_VISIBILE
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_GRAPH, val);
				}
				| T_KW_UNA T_KW_LETTERA T_KW_MINUSCOLA 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_LOWER, val);				
				}
				| T_KW_UNA T_KW_LETTERA T_KW_NON T_KW_MINUSCOLA
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_LOWER, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_STAMPABILE 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_PRINT, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_STAMPABILE
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_PRINT, val);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DI T_KW_PUNTEGGIATURA
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_PUNCT, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_DI T_KW_PUNTEGGIATURA
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_PUNCT, val);
				}
				| T_KW_QUALUNQUE T_KW_SPAZIO T_KW_BIANCO
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_SPACE, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DIVERSO T_KW_DA T_KW_QUALUNQUE T_KW_SPAZIO T_KW_BIANCO
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_SPACE, val);
				}
				| T_KW_UNA T_KW_LETTERA T_KW_MAIUSCOLA 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_UPPER, val);				
				}
				| T_KW_UNA T_KW_LETTERA T_KW_NON T_KW_MAIUSCOLA
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_UPPER, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_POSIX T_KW_ALFANUMERICO T_KW_O T_KW_DI T_KW_SOTTOLINEATURA 
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_WORD, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_DIVERSO T_KW_DA T_KW_ALFANUMERICO T_KW_E T_KW_SOTTOLINEATURA
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_WORD, val);
				}				
				| T_KW_UN T_KW_CARATTERE T_KW_ESADECIMALE
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_XDIGIT, val);				
				}
				| T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_ESADECIMALE
				{
					Valore val;
					val.cVal = '^';
					$$ = con(AST_POSIX_XDIGIT, val);
				}
				/*
				| T_POSIX_UNKNOWN
				{					
					char szError[1024];
					sprintf(szError, "classe di caratteri posix '%s' non valida.\n", $1);
					yyerror(&@1, scanner, pTree, szInput, countGroups, szError);
					free($1);
					return 1;
				}								
				| T_POSIX_OUT
				{					
					char szError[1024];
					sprintf(szError, "classe di caratteri posix '%s' non valida al di fuori di [].\n", $1);
					yyerror(&@1, scanner, pTree, szInput, countGroups, szError);
					free($1);
					return 1;
				}
				*/											
				;

nul:
				T_KW_UN T_KW_CARATTERE T_KW_NULLO
				{
					Valore val;
					val.cVal = '\0';
					$$ = con(AST_NUL, val);
				}
				;

octal:
				T_KW_UN T_KW_CARATTERE T_KW_CORRISPONDENTE T_KW_AL T_KW_CODICE T_KW_OTTALE T_INTEGER
				{
					Valore val;
					
					if ( $7 > 377 )
					{
						char szError[1024];
						sprintf(szError, "codice ottale non valido '%d'.\n", $7);
						yyerror(&@7, scanner, pTree, szInput, countGroups, szError);
						return 1;
					}					
										
					val.iVal = $7;
					$$ = con(AST_OCTAL, val);
				}
				;
				
hex:
				T_KW_UN T_KW_CARATTERE T_KW_CORRISPONDENTE T_KW_AL T_KW_CODICE T_KW_ESADECIMALE T_HEX
				{
					Valore val;
					int len;
					
					len = strlen($7);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $7, len + 1);
					free($7);
					$$ = con(AST_HEX, val);
				}
				;
				
unicode:
				T_KW_UN T_KW_CARATTERE T_KW_CORRISPONDENTE T_KW_AL T_KW_CODICE T_KW_UNICODE T_HEX
				{
					Valore val;
					int len;					
					
					len = strlen($7);
					if ( len > 4 )
					{
						char szError[1024];
						sprintf(szError, "codice unicode non valido '%s'. Deve essere formato da 4 cifre esadecimali.\n", $7);
						yyerror(&@7, scanner, pTree, szInput, countGroups, szError);
						return 1;
					}					
					
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $7, len + 1);
					free($7);
					$$ = con(AST_UNICODE, val);
				}
				;
								
set:
				positive_set {$$ = $1;}
				| negative_set {$$ = $1;}
				;
				
positive_set:
				T_KW_UN T_KW_CARATTERE T_KW_NELL T_APICE T_KW_INSIEME T_BEGIN_POS_SET set_items T_END_SET
				{
					$$ = opr(AST_POSITIVE_SET, 1, $7);
				}
				;
				
negative_set:
				/* T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_NELL T_APICE T_KW_INSIEME T_BEGIN_NEG_SET set_items T_END_SET */
				T_KW_UN T_KW_CARATTERE T_KW_NON T_KW_NELL T_APICE T_KW_INSIEME T_BEGIN_POS_SET set_items T_END_SET
				{
					$$ = opr(AST_NEGATIVE_SET, 1, $8);
				}
				;
				
set_items:
				set_item { $$ = $1; }
				| set_items T_COMMA set_item { $$ = opr(AST_SET_ITEMS, 2, $1, $3); }
				;
				
set_item:
				range {$$ = $1;}
				| char {$$ = $1;}
				| posix_char {$$ = $1;}
				| any {$$ = $1;}
				| unicode_any {$$ = $1;}
				| unicode {$$ = $1;}
				| hex {$$ = $1;}
				| nul {$$ = $1;}
				/*								
				| unicode_prop {$$ = $1;}
				| unicode_prop_neg {$$ = $1;}
				*/
				;
				
range:
				T_KW_UN T_KW_CARATTERE T_KW_TRA char T_KW_E char
				{
					$$ = opr(AST_RANGE, 2, $4, $6);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_TRA posix_char T_KW_E posix_char
				{
					$$ = opr(AST_RANGE, 2, $4, $6);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_TRA posix_char T_KW_E char
				{
					$$ = opr(AST_RANGE, 2, $4, $6);
				}
				| T_KW_UN T_KW_CARATTERE T_KW_TRA char T_KW_E posix_char
				{
					$$ = opr(AST_RANGE, 2, $4, $6);
				}
				/*
				| unicode_prop T_RANGE unicode_prop
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}
				| unicode_prop T_RANGE char
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}				
				| char T_RANGE unicode_prop
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}
				| unicode_prop_neg T_RANGE unicode_prop_neg
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}
				| unicode_prop_neg T_RANGE char
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}				
				| char T_RANGE unicode_prop_neg
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}
				*/										
				;
				
%%

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
