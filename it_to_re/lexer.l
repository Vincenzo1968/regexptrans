/*
   Copyright (C) 2013 Vincenzo Lo Cicero

   Author: Vincenzo Lo Cicero.
   e-mail: vincenzo.locicero@libero.it
       
   This file is part of ittore.

   ittore is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ittore is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with ittore.  If not, see <http://www.gnu.org/licenses/>.
*/

%option reentrant
%option extra-type="MyLexParam *"
%option bison-bridge
%option bison-locations
%option yylineno
%option nounput 
%option noinput 
%option noyywrap
%option noyyalloc
%option noyyrealloc
%option noyyfree
%option noread
%option nounistd
%option always-interactive
%option outfile="lexer.c" header-file="lexer.h"

%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ast.h"
#include "parser.h"

#define YY_EXIT_FAILURE ( (void)yyscanner, 2 )

#define YY_USER_ACTION yyget_lloc(yyscanner)->first_line = yyget_lloc(yyscanner)->last_line = yylineno; \
yyget_lloc(yyscanner)->first_column = yycolumn; yyget_lloc(yyscanner)->last_column = yycolumn+yyleng-1; \
yycolumn += yyleng; 
%}

%x string
%x comment
%x comment_sl
%x esadec

%%

[ ]						{}
[\t]					{yycolumn += 7;}
[\r\n]					{}
"//"					{BEGIN(comment_sl);}
"#"						{BEGIN(comment_sl);}
"'"						{return T_APICE;}
":"						{return T_COLON;}
"/"						{return T_DIV;}
<comment_sl>.			{}
<comment_sl>\n			{BEGIN(INITIAL);}
"/*"					{BEGIN(comment);}
<comment>[^*\n]*		{}
<comment>"*"+[^*/\n]*	{}
<comment>\n 			{}
<comment>"*"+"/"		{BEGIN(INITIAL);}

"alfanumerico"			{return T_KW_ALFANUMERICO;}
"alfabetico"			{return T_KW_ALFABETICO;}
"almeno"				{return T_KW_ALMENO;}
"ascii"					{return T_KW_ASCII;}
"alert"					{return T_KW_ALERT;}
"altro"					{return T_KW_ALTRO;}
"apice"					{return T_KW_APICE;}
"aperta"				{return T_KW_APERTA;}
"aperte"				{return T_KW_APERTE;}
"appartenga"			{return T_KW_APPARTENGA;}
"assegnato"				{return T_KW_ASSEGNATO;}
"avanzamento"			{return T_KW_AVANZAMENTO;}
"bianco"				{return T_KW_BIANCO;}
"bianchi"				{return T_KW_BIANCHI;}
"blocco"				{return T_KW_BLOCCO;}
"backspace"				{return T_KW_BACKSPACE;}
"capo"					{return T_KW_CAPO;}
"carattere"				{return T_KW_CARATTERE;}
"caratteri"				{return T_KW_CARATTERI;}
"chiusa"				{return T_KW_CHIUSA;}
"chiuse"				{return T_KW_CHIUSE;}
"cifra"					{return T_KW_CIFRA;}
"citazione"				{return T_KW_CITAZIONE;}
"code"					{return T_KW_CODE;}
"codice"				{return T_KW_CODICE;}
"codifica"				{return T_KW_CODIFICA;}
"combinato"				{return T_KW_COMBINATO;}
"combinazione"			{return T_KW_COMBINAZIONE;}
"come"					{return T_KW_COME;}
"compreso"				{return T_KW_COMPRESO;}
"compresa"				{return T_KW_COMPRESA;}
"connessione"			{return T_KW_CONNESSIONE;}
"corrispondente"		{return T_KW_CORRISPONDENTE;}
"controllo"				{return T_KW_CONTROLLO;}
"diverso"				{return T_KW_DIVERSO;}
"delimitatore"			{return T_KW_DELIMITATORE;}
"destinato"				{return T_KW_DESTINATO;}
"entrambe"				{return T_KW_ENTRAMBE;}
"esadecimale"			{return T_KW_ESADECIMALE;}
"escape"				{return T_KW_ESCAPE;}
"esiste"				{return T_KW_ESISTE;}
"essere"				{return T_KW_ESSERE;}
"formattazione"			{return T_KW_FORMATTAZIONE;}
"gruppo"				{return T_KW_GRUPPO;}
"ideogramma"			{return T_KW_IDEOGRAMMA;}
"ideografici"			{return T_KW_IDEOGRAFICI;}
"indicatore"			{return T_KW_INDICATORE;}
"inizio"				{return T_KW_INIZIO;}
"insieme"				{return T_KW_INSIEME;}
"invisibili"			{return T_KW_INVISIBILI;}
"Latin1"				{return T_KW_LATIN1;}
"lettera"				{return T_KW_LETTERA;}
"linea"					{return T_KW_LINEA;}
"lineetta"				{return T_KW_LINEETTA;}
"lingua"				{return T_KW_LINGUA;}
"match"					{return T_KW_MATCH;}
"minuscola"				{return T_KW_MINUSCOLA;}
"maiuscola"				{return T_KW_MAIUSCOLA;}
"minuscolo"				{return T_KW_MINUSCOLO;}
"maiuscolo"				{return T_KW_MAIUSCOLO;}
"matematico"			{return T_KW_MATEMATICO;}
"matematici"			{return T_KW_MATEMATICI;}
"modulo"				{return T_KW_MODULO;}
"nessun"				{return T_KW_NESSUN;}
"nove"					{return T_KW_NOVE;}
"numerico"				{return T_KW_NUMERICO;}
"numero"				{return T_KW_NUMERO;}
"nuova"					{return T_KW_NUOVA;}
"nullo"					{return T_KW_NULLO;}
"occupare"				{return T_KW_OCCUPARE;}
"occupa"				{return T_KW_OCCUPA;}
"oppure"				{return T_KW_OPPURE;}
"ottale"				{return T_KW_OTTALE;}
"parola"				{return T_KW_PAROLA;}
"paragrafo"				{return T_KW_PARAGRAFO;}
"parentesi"				{return T_KW_PARENTESI;}
"pedice"				{return T_KW_PEDICE;}
"preceduto"				{return T_KW_PRECEDUTO;}
"privato"				{return T_KW_PRIVATO;}
"point"					{return T_KW_POINT;}
"posix"					{return T_KW_POSIX;}
"punteggiatura"			{return T_KW_PUNTEGGIATURA;}
"possessivo"			{return T_KW_POSSESSIVO;}
"qualunque"				{return T_KW_QUALUNQUE;}
"qualsiasi"				{return T_KW_QUALSIASI;}
"racchiude"				{return T_KW_RACCHIUDE;}
"restituito"			{return T_KW_RESTITUITO;}
"ripetizioni"			{return T_KW_RIPETIZIONI;}
"riservato"				{return T_KW_RISERVATO;}
"ritorno"				{return T_KW_RITORNO;}
"riluttante"			{return T_KW_RILUTTANTE;}
"sarà"					{return T_KW_SARA;}
"senza"					{return T_KW_SENZA;}
"script"				{return T_KW_SCRIPT;}
"seguito"				{return T_KW_SEGUITO;}
"separatore"			{return T_KW_SEPARATORE;}
"simbolo"				{return T_KW_SIMBOLO;}
"simboli"				{return T_KW_SIMBOLI;}
"simile"				{return T_KW_SIMILE;}
"sottolineatura"		{return T_KW_SOTTOLINEATURA;}
"stampabile"			{return T_KW_STAMPABILE;}
"spazio"				{return T_KW_SPAZIO;}
"spazi"					{return T_KW_SPAZI;}
"speciale"				{return T_KW_SPECIALE;}
"siano"					{return T_KW_SIANO;}
"solo"					{return T_KW_SOLO;}
"sono"					{return T_KW_SONO;}
"stato"					{return T_KW_STATO;}
"surrogati"				{return T_KW_SURROGATI;}
"tabulazione"			{return T_KW_TABULAZIONE;}
"tipo"					{return T_KW_TIPO;}
"tranne"				{return T_KW_TRANNE;}
"trattino"				{return T_KW_TRATTINO;}
"ulteriore"				{return T_KW_ULTERIORE;}
"unicode"				{return T_KW_UNICODE;}
"usato"					{return T_KW_USATO;}
"uso"					{return T_KW_USO;}
"utf16"					{return T_KW_UTF16;}
"utilizzati"			{return T_KW_UTILIZZATI;}
"valuta"				{return T_KW_VALUTA;}
"variante"				{return T_KW_VARIANTE;}
"varianti"				{return T_KW_VARIANTI;}
"varie"					{return T_KW_VARIE;}
"vari"					{return T_KW_VARI;}
"verticale"				{return T_KW_VERTICALE;}
"viene"					{return T_KW_VIENE;}
"virgolette"			{return T_KW_VIRGOLETTE;}
"visibile"				{return T_KW_VISIBILE;}
"zero"					{return T_KW_ZERO;}

"all"					{return T_KW_ALL;}
"ad"					{return T_KW_AD;}
"al"					{return T_KW_AL;}
"alla"					{return T_KW_ALLA;}
"a"						{return T_KW_A;}
"che"					{return T_KW_CHE;}
"con"					{return T_KW_CON;}
"cui"					{return T_KW_CUI;}
"del"					{return T_KW_DEL;}
"da"					{return T_KW_DA;}
"di"					{return T_KW_DI;}
"e"						{return T_KW_E;}
"è"						{return T_KW_E_VERBO;}
"ha"					{return T_KW_HA;}
"il"					{return T_KW_IL;}
"le"					{return T_KW_LE;}
"in"					{return T_KW_IN;}
"ma"					{return T_KW_MA;}
"né"					{return T_KW_NE;}
"nell"					{return T_KW_NELL;}
"nel"					{return T_KW_NEL;}
"non"					{return T_KW_NON;}
"o"						{return T_KW_O;}
"per"					{return T_KW_PER;}
"più"					{return T_KW_PIU;}
"se"					{return T_KW_SE;}
"sia"					{return T_KW_SIA;}
"tra"					{return T_KW_TRA;}
"uno"					{return T_KW_UNO;}
"una"					{return T_KW_UNA;}
"un"					{return T_KW_UN;}

"{"						{BEGIN(esadec);}
<esadec>"}"				{BEGIN(INITIAL);}
<esadec>[0-9a-fA-F][0-9a-fA-F]*	{
							yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
							strcpy(yylval->strValue, yytext);
							return T_HEX;
						}
<esadec>.				{return T_KW_UNKNOWN;}

[0-9]+					{yylval->iValue = atoi(yytext); return T_INTEGER;}
		

I(n|s)[[:alnum:]_-]+	{
							HashTable *pDati = NULL;
							char myBlock[256];
							strncpy(myBlock, yytext, 256);
							yylval->strValue = (char*)malloc(sizeof(char)*strlen(myBlock)+1);
							strcpy(yylval->strValue, myBlock);											
							yyextra->bFirstClass = 0;
											
							if ( htFind(yyextra->pHT_UnicodeBlocks, myBlock, &pDati) != -1 )
								return T_UNICODE_BLOCK;
							else
								return T_KW_UNKNOWN;
						}

[A-Z][[:alpha:]_]+		{
							HashTable *pDati = NULL;
							char myScript[256];
							strncpy(myScript, yytext, 256);
							yylval->strValue = (char*)malloc(sizeof(char)*strlen(myScript)+1);
							strcpy(yylval->strValue, myScript);
							yyextra->bFirstClass = 0;
											
							if ( htFind(yyextra->pHT_UnicodeScripts, myScript, &pDati) != -1 )
								return T_UNICODE_SCRIPT;
							else
								return T_KW_UNKNOWN;
						}				

[A-Za-z_]+				{
							return T_KW_UNKNOWN;
						}				
						
"("						{return T_LPAREN;}
")"						{return T_RPAREN;}
","						{return T_COMMA;}

"[^"					{
							/*
							BEGIN(class);
							yyextra->bFirstClass = 1;
							*/
							return T_BEGIN_NEG_SET;
						}
"["						{
							/*
							BEGIN(class);
							yyextra->bFirstClass = 1;
							*/
							return T_BEGIN_POS_SET;
						}
"]"						{
							/*
							if ( yyextra->bFirstClass )
							{
								yylval->cValue = ']';
								yyextra->bFirstClass = 0;
								return T_CHAR;							
							}
							yyextra->bFirstClass = 0;
							BEGIN(INITIAL);
							*/
							return T_END_SET;
						}

"\""					{
							BEGIN(string);
							yyextra->indexString = 0;
							yyextra->szString[0] = '\0';
						}
<string>"\\\""			{
							yyextra->szString[yyextra->indexString++] = '"';
						}					
<string>"\""			{
							BEGIN(INITIAL);
							yyextra->szString[yyextra->indexString] = '\0';
							if ( yyextra->indexString == 1 )
							{
								yylval->cValue = yyextra->szString[0];
								yyextra->indexString = 0;
								return T_CHAR;
							}
							yylval->strValue = (char*)malloc(sizeof(char)*strlen(yyextra->szString)+1);
							strcpy(yylval->strValue, yyextra->szString);
							yyextra->indexString = 0;
							return T_STRING;
						}
<string>.				{
							yyextra->szString[yyextra->indexString++] = yytext[0];
						}					

%%

void *yyalloc (yy_size_t  size , yyscan_t yyscanner)
{
	UNUSED(yyscanner);
	return (void *) malloc( size );
}

void *yyrealloc  (void * ptr, yy_size_t  size , yyscan_t yyscanner)
{
	UNUSED(yyscanner);
	/* The cast to (char *) in the following accommodates both
	 * implementations that use char* generic pointers, and those
	 * that use void* generic pointers.  It works with the latter
	 * because both ANSI C and C++ allow castless assignment from
	 * any pointer type to void*, and deal with argument conversions
	 * as though doing an assignment.
	 */
	return (void *) realloc( (char *) ptr, size );
}

void yyfree (void * ptr , yyscan_t yyscanner)
{
	UNUSED(yyscanner);
	free( (char *) ptr );	/* see yyrealloc() for (char *) cast */
}


