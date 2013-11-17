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


%token T_OR T_PLUS T_STAR T_QUESTION T_RANGE T_LPAREN T_RPAREN T_BEGIN_NEG_SET T_BEGIN_POS_SET T_END_SET T_ANY T_UNICODE_ANY T_LBRACE T_RBRACE T_COMMA
%token T_OPEN_POSITIVE_LOOKAHEAD T_OPEN_NEGATIVE_LOOKAHEAD T_OPEN_POSITIVE_LOOKBEHIND T_OPEN_NEGATIVE_LOOKBEHIND
%token T_KAPPA T_UNICODE_START T_UNICODE_START_NEG
%token <cValue> T_POSIX_ALNUM T_POSIX_ALPHA T_POSIX_ASCII T_POSIX_BLANK T_POSIX_CNTRL T_POSIX_DIGIT T_POSIX_GRAPH
%token <cValue> T_POSIX_LOWER T_POSIX_PRINT T_POSIX_PUNCT T_POSIX_SPACE T_POSIX_UPPER T_POSIX_WORD T_POSIX_XDIGIT
%token <cValue> T_CHAR T_SPECIAL T_NUL
%token <iValue> T_INTEGER T_BACKREF T_UNICODE_PROP_ID
%token <strValue> T_UNICODE_SCRIPT T_UNICODE_SCRIPT_NEG T_UNICODE_BLOCK T_UNICODE_BLOCK_NEG
%token <strValue> T_OCTAL T_HEX T_UNICODE T_UNICODE_INVALID
%token <strValue> T_POSIX_UNKNOWN T_POSIX_OUT

%type <nPtr> char any unicode_any unicode_prop unicode_prop_neg backref nul octal hex unicode
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
				| simple_re T_KAPPA simple_re
				{
					$$ = opr(AST_KAPPA, 2, $1, $3);
				}				
				;
				
union:
				re T_OR simple_re
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
				;
				
basic_re:
				star {$$ = $1;}
				| plus {$$ = $1;}
				| question {$$ = $1;}
				| reprange {$$ = $1;}
				| elementary_re {$$ = $1;}
				;
				
lookaround:		T_OPEN_POSITIVE_LOOKAHEAD re T_RPAREN
				{
					$$ = opr(AST_POSITIVE_LOOKAHEAD, 1, $2);
				}
				| T_OPEN_NEGATIVE_LOOKAHEAD re T_RPAREN
				{
					$$ = opr(AST_NEGATIVE_LOOKAHEAD, 1, $2);
				}
				| T_OPEN_POSITIVE_LOOKBEHIND re T_RPAREN
				{
					$$ = opr(AST_POSITIVE_LOOKBEHIND, 1, $2);
				}
				| T_OPEN_NEGATIVE_LOOKBEHIND re T_RPAREN
				{
					$$ = opr(AST_NEGATIVE_LOOKBEHIND, 1, $2);
				}
				;
								
star:
				elementary_re T_STAR
				{
					$$ = opr(AST_STAR, 1, $1);
				}
				| elementary_re T_STAR T_QUESTION basic_re
				{
					$$ = opr(AST_LAZY_STAR, 2, $1, $4);
				}				
				| elementary_re T_STAR T_PLUS basic_re
				{
					$$ = opr(AST_POSSESSIVE_STAR, 2, $1, $4);
				}								
				;
								
plus:
				elementary_re T_PLUS
				{
					$$ = opr(AST_PLUS, 1, $1);
				}
				| elementary_re T_PLUS T_QUESTION basic_re
				{
					$$ = opr(AST_LAZY_PLUS, 2, $1, $4);
				}				
				| elementary_re T_PLUS T_PLUS basic_re
				{
					$$ = opr(AST_POSSESSIVE_PLUS, 2, $1, $4);
				}								
				;
				
question:
				elementary_re T_QUESTION
				{
					$$ = opr(AST_QUESTION, 1, $1);
				}
				| elementary_re T_QUESTION T_QUESTION basic_re
				{
					$$ = opr(AST_LAZY_QUESTION, 2, $1, $4);
				}
				| elementary_re T_QUESTION T_PLUS basic_re
				{
					$$ = opr(AST_POSSESSIVE_QUESTION, 2, $1, $4);
				}								
				;
				
reprange:
				elementary_re T_LBRACE T_INTEGER T_COMMA T_INTEGER T_RBRACE
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $5;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $1);
				}				
				| elementary_re T_LBRACE T_INTEGER T_COMMA T_INTEGER T_RBRACE T_QUESTION basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $5;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $1, $8);
				}	
				| elementary_re T_LBRACE T_INTEGER T_COMMA T_INTEGER T_RBRACE T_PLUS basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $5;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $1, $8);
				}											
				| elementary_re T_LBRACE T_INTEGER T_RBRACE
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $1);
				}								
				| elementary_re T_LBRACE T_INTEGER T_RBRACE T_QUESTION basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $1, $6);
				}
				| elementary_re T_LBRACE T_INTEGER T_RBRACE T_PLUS basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = $3;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $1, $6);
				}												
				| elementary_re T_LBRACE T_COMMA T_INTEGER T_RBRACE
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = $4;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $1);
				}				
				| elementary_re T_LBRACE T_COMMA T_INTEGER T_RBRACE T_QUESTION basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = $4;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $1, $7);
				}
				| elementary_re T_LBRACE T_COMMA T_INTEGER T_RBRACE T_PLUS basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = 0;
					val2.iVal = $4;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $1, $7);
				}								
				| elementary_re T_LBRACE T_INTEGER T_COMMA T_RBRACE
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_REPRANGE, 3, p1, p2, $1);
				}											
				| elementary_re T_LBRACE T_INTEGER T_COMMA T_RBRACE T_QUESTION basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_LAZY_REPRANGE, 4, p1, p2, $1, $7);
				}
				| elementary_re T_LBRACE T_INTEGER T_COMMA T_RBRACE T_PLUS basic_re
				{
					Valore val1, val2;
					
					nodeType *p1;
					nodeType *p2;
					
					val1.iVal = $3;
					val2.iVal = 0;
					
					p1 = con(AST_INTEGER, val1);
					p2 = con(AST_INTEGER, val2);
				
					$$ = opr(AST_POSSESSIVE_REPRANGE, 4, p1, p2, $1, $7);
				}															
				;				
					
elementary_re:
				group {$$ = $1;}
				| any {$$ = $1;}
				| unicode_any {$$ = $1;}
				| unicode_prop {$$ = $1;}
				| unicode_prop_neg {$$ = $1;}
				| backref {$$ = $1;}
				| char {$$ = $1;}
				| nul {$$ = $1;}
				| octal {$$ = $1;}
				| hex {$$ = $1;}
				| unicode {$$ = $1;}
				| set {$$ = $1;}

group:
				T_LPAREN re T_RPAREN
				{
					$$ = opr(AST_GROUP, 1, $2);
					(*countGroups)++;
				}
				;
				
any:
				T_ANY
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_ANY, val);
				}				
				;
				
unicode_any:
				T_UNICODE_ANY
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_UNICODE_ANY, val);
				}				
				;
				
unicode_prop:
				T_UNICODE_START T_UNICODE_PROP_ID
				{
					Valore val;
					val.iVal = $2;
					$$ = con(AST_UNICODE_PROP, val);
				}								
				| T_UNICODE_START T_UNICODE_SCRIPT
				{					
					Valore val;
					int len;					
					len = strlen($2);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $2, len + 1);
					free($2);
					$$ = con(AST_UNICODE_SCRIPT, val);					
				}												
				| T_UNICODE_START T_UNICODE_BLOCK
				{					
					Valore val;
					int len;					
					len = strlen($2);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $2, len + 1);
					free($2);
					$$ = con(AST_UNICODE_BLOCK, val);					
				}																
				| T_UNICODE_START T_UNICODE_INVALID
				{
					char szError[1024];
					sprintf(szError, "riferimento a carattere unicode '%s' non valido.\n", $2);
					yyerror(&@2, scanner, pTree, szInput, countGroups, szError);
					free($2);
					return 1;
				}								
				;				

unicode_prop_neg:
				T_UNICODE_START_NEG T_UNICODE_PROP_ID
				{
					Valore val;
					val.iVal = $2;
					$$ = con(AST_UNICODE_PROP, val);
				}
				| T_UNICODE_START_NEG T_UNICODE_SCRIPT_NEG
				{
					Valore val;
					int len;					
					len = strlen($2);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $2, len + 1);
					free($2);
					$$ = con(AST_UNICODE_SCRIPT_NEG, val);
				}
				| T_UNICODE_START_NEG T_UNICODE_BLOCK_NEG
				{
					Valore val;
					int len;					
					len = strlen($2);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $2, len + 1);
					free($2);
					$$ = con(AST_UNICODE_BLOCK_NEG, val);
				}																			
				| T_UNICODE_START_NEG T_UNICODE_INVALID
				{
					char szError[1024];
					sprintf(szError, "riferimento a carattere unicode '%s' non valido.\n", $2);
					yyerror(&@2, scanner, pTree, szInput, countGroups, szError);
					free($2);
					return 1;
				}								
				;				
				
backref:
				T_BACKREF
				{
					Valore val;
					val.iVal = $1;
					if ($1 > *countGroups )
					{
						char szError[1024];
						sprintf(szError, "backreference: riferimento a gruppo %d non valido. Ci sono soltanto %d gruppi.\n", $1, *countGroups);
						yyerror(&@1, scanner, pTree, szInput, countGroups, szError);
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
				| T_SPECIAL
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_SPECIALCHAR, val);
				}
				| T_POSIX_ALNUM
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_ALNUM, val);				
				}
				| T_POSIX_ALPHA
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_ALPHA, val);				
				}
				| T_POSIX_ASCII
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_ASCII, val);				
				}
				| T_POSIX_BLANK
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_BLANK, val);				
				}
				| T_POSIX_CNTRL
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_CNTRL, val);				
				}
				| T_POSIX_DIGIT
				{
					Valore val;
					val.cVal = '.';
					$$ = con(AST_POSIX_DIGIT, val);				
				}
				| T_POSIX_GRAPH
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_GRAPH, val);				
				}
				| T_POSIX_LOWER
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_LOWER, val);				
				}
				| T_POSIX_PRINT
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_PRINT, val);				
				}
				| T_POSIX_PUNCT
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_PUNCT, val);				
				}
				| T_POSIX_SPACE
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_SPACE, val);				
				}
				| T_POSIX_UPPER
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_UPPER, val);				
				}
				| T_POSIX_WORD
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_WORD, val);				
				}
				| T_POSIX_XDIGIT
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_POSIX_XDIGIT, val);
				}				
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
				;
				
nul:
				T_NUL
				{
					Valore val;
					val.cVal = $1;
					$$ = con(AST_NUL, val);
				}
				;
				
octal:
				T_OCTAL
				{
					Valore val;
					int len;
					
					len = strlen($1);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $1, len + 1);
					free($1);
					$$ = con(AST_OCTAL, val);
				}
				;
				
hex:
				T_HEX
				{
					Valore val;
					int len;
					
					len = strlen($1);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $1, len + 1);
					free($1);
					$$ = con(AST_HEX, val);
				}
				;
				
unicode:
				T_UNICODE
				{
					Valore val;
					int len;
					
					len = strlen($1);
					val.strVal = malloc(sizeof(char) * (len + 1));
					strncpy(val.strVal, $1, len + 1);
					free($1);
					$$ = con(AST_UNICODE, val);
				}
				;
								
set:
				positive_set {$$ = $1;}
				| negative_set {$$ = $1;}
				;
				
positive_set:
				T_BEGIN_POS_SET set_items T_END_SET
				{
					$$ = opr(AST_POSITIVE_SET, 1, $2);
				}
				;
				
negative_set:
				T_BEGIN_NEG_SET set_items T_END_SET
				{
					$$ = opr(AST_NEGATIVE_SET, 1, $2);
				}
				;
				
set_items:
				set_item { $$ = $1; }
				| set_items set_item { $$ = opr(AST_SET_ITEMS, 2, $1, $2); }
				;
				
set_item:
				range {$$ = $1;}
				| char {$$ = $1;}
				| any {$$ = $1;}
				| unicode_any {$$ = $1;}
				| unicode_prop {$$ = $1;}
				| unicode_prop_neg {$$ = $1;}
				;
				
range:
				char T_RANGE char
				{
					$$ = opr(AST_RANGE, 2, $1, $3);
				}
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
				;
				
%%

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
