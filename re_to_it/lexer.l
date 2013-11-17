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

%x reprange
%x class
%x literal
%x comment
%x uni
%x unineg

%%
"(?="				{return T_OPEN_POSITIVE_LOOKAHEAD;}
"(?!"				{return T_OPEN_NEGATIVE_LOOKAHEAD;}
"(?<="				{return T_OPEN_POSITIVE_LOOKBEHIND;}
"(?<!"				{return T_OPEN_NEGATIVE_LOOKBEHIND;}
<INITIAL,class>"(?#"	{yyextra->prevState = YYSTATE; BEGIN(comment);}
<comment>")"		{BEGIN(yyextra->prevState);}
<comment>"]"		{
						if ( yyextra->prevState == class )
						{
							if ( !(yyextra->bFirstClass) )
							{
								yyextra->bFirstClass = 0;
								return T_END_SET;
							}
						}
					}
<comment>.			{}

<INITIAL,class>\\p						{yyextra->prevState = YYSTATE; BEGIN(uni); return T_UNICODE_START;}
<INITIAL,class>\\P						{yyextra->prevState = YYSTATE; BEGIN(unineg); return T_UNICODE_START_NEG;}
<uni,unineg>"{Letter}"					|
<uni,unineg>"{L}"						|
<uni,unineg>"L"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Letter;
											else
												yylval->iValue = -UPROP_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Lowercase_Letter}"		|
<uni,unineg>"{Ll}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Lowercase_Letter;
											else
												yylval->iValue = -UPROP_Lowercase_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Uppercase_Letter}"		|
<uni,unineg>"{Lu}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Uppercase_Letter;
											else
												yylval->iValue = -UPROP_Uppercase_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Titlecase_Letter}"		|
<uni,unineg>"{Lt}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Titlecase_Letter;
											else
												yylval->iValue = -UPROP_Titlecase_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Cased_Letter}"			|
<uni,unineg>"{L&}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Cased_Letter;
											else
												yylval->iValue = -UPROP_Cased_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Modifier_Letter}"			|
<uni,unineg>"{Lm}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Modifier_Letter;
											else
												yylval->iValue = -UPROP_Modifier_Letter;
											BEGIN(yyextra->prevState);
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Other_Letter}"			|
<uni,unineg>"{Lo}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Other_Letter;
											else
												yylval->iValue = -UPROP_Other_Letter;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Mark}"					|
<uni,unineg>"{M}"						|
<uni,unineg>"M"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Mark;
											else
												yylval->iValue = -UPROP_Mark;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Non_Spacing_Mark}"		|
<uni,unineg>"{Mn}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Non_Spacing_Mark;
											else
												yylval->iValue = -UPROP_Non_Spacing_Mark;											
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Spacing_Combining_Mark}"	|
<uni,unineg>"{Mc}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Spacing_Combining_Mark;
											else
												yylval->iValue = -UPROP_Spacing_Combining_Mark;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Enclosing_Mark}"			|
<uni,unineg>"{Me}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Enclosing_Mark;
											else
												yylval->iValue = -UPROP_Enclosing_Mark;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Separator}"				|
<uni,unineg>"{Z}"						|
<uni,unineg>"Z"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Separator;
											else
												yylval->iValue = -UPROP_Separator;
											BEGIN(yyextra->prevState);
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Space_Separator}"			|
<uni,unineg>"{Zs}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Space_Separator;
											else
												yylval->iValue = -UPROP_Space_Separator;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Line_Separator}"			|
<uni,unineg>"{Zl}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Line_Separator;
											else
												yylval->iValue = -UPROP_Line_Separator;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Paragraph_Separator}"		|
<uni,unineg>"{Zp}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Paragraph_Separator;
											else
												yylval->iValue = -UPROP_Paragraph_Separator;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Symbol}"					|
<uni,unineg>"{S}"						|
<uni,unineg>"S"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Symbol;
											else
												yylval->iValue = -UPROP_Symbol;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Math_Symbol}"				|
<uni,unineg>"{Sm}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Math_Symbol;
											else
												yylval->iValue = -UPROP_Math_Symbol;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Currency_Symbol}"			|
<uni,unineg>"{Sc}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Currency_Symbol;
											else
												yylval->iValue = -UPROP_Currency_Symbol;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Modifier_Symbol}"			|
<uni,unineg>"{Sk}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Modifier_Symbol;
											else
												yylval->iValue = -UPROP_Modifier_Symbol;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Other_Symbol}"			|
<uni,unineg>"{So}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Other_Symbol;
											else
												yylval->iValue = -UPROP_Other_Symbol;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Number}"					|
<uni,unineg>"{N}"						|
<uni,unineg>"N"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Number;
											else
												yylval->iValue = -UPROP_Number;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Decimal_Digit_Number}"	|
<uni,unineg>"{Nd}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Decimal_Digit_Number;
											else
												yylval->iValue = -UPROP_Decimal_Digit_Number;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Letter_Number}"			|
<uni,unineg>"{Nl}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Letter_Number;
											else
												yylval->iValue = -UPROP_Letter_Number;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Other_Number}"			|
<uni,unineg>"{No}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Other_Number;
											else
												yylval->iValue = -UPROP_Other_Number;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Punctuation}"				|
<uni,unineg>"{P}"						|
<uni,unineg>"P"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Punctuation;
											else
												yylval->iValue = -UPROP_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Dash_Punctuation}"		|
<uni,unineg>"{Pd}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Dash_Punctuation;
											else
												yylval->iValue = -UPROP_Dash_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Open_Punctuation}"		|
<uni,unineg>"{Ps}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Open_Punctuation;
											else
												yylval->iValue = -UPROP_Open_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Close_Punctuation}"		|
<uni,unineg>"{Pe}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Close_Punctuation;
											else
												yylval->iValue = -UPROP_Close_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Initial_Punctuation}"		|
<uni,unineg>"{Pi}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Initial_Punctuation;
											else
												yylval->iValue = -UPROP_Initial_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Final_Punctuation}"		|
<uni,unineg>"{Pf}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Final_Punctuation;
											else
												yylval->iValue = -UPROP_Final_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Connector_Punctuation}"	|
<uni,unineg>"{Pc}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Connector_Punctuation;
											else
												yylval->iValue = -UPROP_Connector_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Other_Punctuation}"		|
<uni,unineg>"{Po}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Other_Punctuation;
											else
												yylval->iValue = -UPROP_Other_Punctuation;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Other}"					|
<uni,unineg>"{C}"						|
<uni,unineg>"C"							{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Other;
											else
												yylval->iValue = -UPROP_Other;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Control}"					|
<uni,unineg>"{Cc}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Control;
											else
												yylval->iValue = -UPROP_Control;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Format}"					|
<uni,unineg>"{Cf}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Format;
											else
												yylval->iValue = -UPROP_Format;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Private_Use}"				|
<uni,unineg>"{Co}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Private_Use;
											else
												yylval->iValue = -UPROP_Private_Use;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Surrogate}"				|
<uni,unineg>"{Cs}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Surrogate;
											else
												yylval->iValue = -UPROP_Surrogate;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}
<uni,unineg>"{Unassigned}"				|
<uni,unineg>"{Cn}"						{
											if ( YYSTATE == uni )
												yylval->iValue = UPROP_Unassigned;
											else
												yylval->iValue = -UPROP_Unassigned;
											BEGIN(yyextra->prevState);
											yyextra->bFirstClass = 0;
											return T_UNICODE_PROP_ID;
										}

<uni,unineg>\{I(n|s)[[:alnum:]_-]+\}	{
											HashTable *pDati = NULL;
											char myBlock[256];
											strcpy(myBlock, &yytext[1]);
											myBlock[strlen(myBlock) - 1] = '\0';
											yylval->strValue = (char*)malloc(sizeof(char)*strlen(myBlock)+1);
											strcpy(yylval->strValue, myBlock);											
											yyextra->bFirstClass = 0;
											
											if ( htFind(yyextra->pHT_UnicodeBlocks, myBlock, &pDati) != -1 )
											{
												if ( YYSTATE == uni )
												{
													BEGIN(yyextra->prevState);
													return T_UNICODE_BLOCK;
												}
												else
												{
													BEGIN(yyextra->prevState);
													return T_UNICODE_BLOCK_NEG;
												}
											}
											else
											{
												BEGIN(yyextra->prevState);
												return T_UNICODE_INVALID;
											}
										}

<uni,unineg>\{[A-Z][[:alpha:]_]+\}		{
											HashTable *pDati = NULL;
											char myScript[256];
											strcpy(myScript, &yytext[1]);
											myScript[strlen(myScript) - 1] = '\0';
											yylval->strValue = (char*)malloc(sizeof(char)*strlen(myScript)+1);
											strcpy(yylval->strValue, myScript);
											yyextra->bFirstClass = 0;
											
											if ( htFind(yyextra->pHT_UnicodeScripts, myScript, &pDati) != -1 )
											{
												if ( YYSTATE == uni )
												{
													BEGIN(yyextra->prevState);
													return T_UNICODE_SCRIPT;
												}
												else
												{
													BEGIN(yyextra->prevState);
													return T_UNICODE_SCRIPT_NEG;
												}
											}
											else
											{
												BEGIN(yyextra->prevState);
												return T_UNICODE_INVALID;
											}
										}
										

<uni,unineg>\{[[:alnum:][:digit:][:space:][:xdigit:][:cntrl:]]*\}	|
<uni,unineg>.														{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, yytext);
						BEGIN(yyextra->prevState);
						yyextra->bFirstClass = 0;						
						return T_UNICODE_INVALID;
					}
										

\\Q					{BEGIN(literal);}
<literal>\\E		{BEGIN(INITIAL);}
<literal>.			{yylval->cValue = yytext[0]; yyextra->bFirstClass = 0; return T_CHAR;}
"{"					{
						BEGIN(reprange);
						return T_LBRACE;
					}
<reprange>[0-9]+	{
						yylval->iValue = atoi(yytext);
						return T_INTEGER;						
					}
<reprange>","		{return T_COMMA;}
<reprange>"}"		{						
						BEGIN(INITIAL);
						return T_RBRACE;
					}
<reprange>.			{yylval->cValue = yytext[0]; return T_CHAR;}					
"|"					{return T_OR;}
"+"					{return T_PLUS;}
"*"					{return T_STAR;}
"?"					{return T_QUESTION;}
"("					{return T_LPAREN;}
")"					{return T_RPAREN;}
\\[1-9]				{yylval->iValue = atoi(&yytext[1]); return T_BACKREF;}
<INITIAL,class>\\[0-7][0-7][0-7]?	{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, &yytext[1]);
						/* strcpy(yylval->strValue, yytext); */
						return T_OCTAL;
					}
<INITIAL,class>\\[uU][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]	{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, &yytext[2]);
						/* strcpy(yylval->strValue, yytext); */
						return T_UNICODE;
					}
<INITIAL,class>\\x[0-9a-fA-F][0-9a-fA-F]?	{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, &yytext[2]);
						/*strcpy(yylval->strValue, yytext);*/
						return T_HEX;
					}
<INITIAL,class>\\x\{[0-9a-fA-F]+\}	{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, &yytext[3]);
						/* strcpy(yylval->strValue, yytext); */
						yylval->strValue[strlen(yylval->strValue) - 1] = '\0';						
						return T_HEX;
					}					
<INITIAL,class>\\0	{yylval->cValue = '\0'; return T_NUL;}					
"[^"				{
						BEGIN(class);
						yyextra->bFirstClass = 1;
						return T_BEGIN_NEG_SET;
					}
"["					{
						BEGIN(class);
						yyextra->bFirstClass = 1;
						return T_BEGIN_POS_SET;
					}
<class>"]"			{
						if ( yyextra->bFirstClass )
						{
							yylval->cValue = ']';
							yyextra->bFirstClass = 0;
							return T_CHAR;							
						}
						yyextra->bFirstClass = 0;
						BEGIN(INITIAL);
						return T_END_SET;
					}
\\K					{return T_KAPPA;}
<INITIAL,class>\\.	{
						yylval->cValue = yytext[1];
						switch (yytext[1])
						{
							case 'a':
							case 'e':							
							case 't':
							case 'v':
							case 'r':
							case 'n':
							case 'f':
							case '<':
							case '>':							
							case 'b':
							case 'B':
							case 'd':
							case 'D':
							case 's':
							case 'S':
							case 'w':
							case 'W':
								yyextra->bFirstClass = 0;
								return T_SPECIAL;
							case 'X':
								yyextra->bFirstClass = 0;
								return T_UNICODE_ANY;							
							default:
								yyextra->bFirstClass = 0;
								return T_CHAR;
						}
					}
<class>"-"			{
						if ( yyextra->bFirstClass )
						{
							yylval->cValue = '-';
							yyextra->bFirstClass = 0;
							return T_CHAR;
						}
						yyextra->bFirstClass = 0;
						return T_RANGE;
					}
<class>-/]			{yylval->cValue = '-'; yyextra->bFirstClass = 0; return T_CHAR;}

<INITIAL>"[:^alnum:]"	|
<INITIAL>"[:alnum:]"	|
<INITIAL>"[:^alpha:]"	|
<INITIAL>"[:alpha:]"	|
<INITIAL>"[:^ascii:]"	|
<INITIAL>"[:ascii:]"	|
<INITIAL>"[:^blank:]"	|
<INITIAL>"[:blank:]"	|
<INITIAL>"[:^cntrl:]"	|
<INITIAL>"[:cntrl:]"	|
<INITIAL>"[:^digit:]"	|
<INITIAL>"[:digit:]"	|
<INITIAL>"[:^graph:]"	|
<INITIAL>"[:graph:]"	|
<INITIAL>"[:^lower:]"	|
<INITIAL>"[:lower:]"	|
<INITIAL>"[:^print:]"	|
<INITIAL>"[:print:]"	|
<INITIAL>"[:^punct:]"	|
<INITIAL>"[:punct:]"	|
<INITIAL>"[:^space:]"	|
<INITIAL>"[:space:]"	|
<INITIAL>"[:^upper:]"	|
<INITIAL>"[:upper:]"	|
<INITIAL>"[:^word:]"	|
<INITIAL>"[:word:]"		|
<INITIAL>"[:^xdigit:]"	|
<INITIAL>"[:xdigit:]"	|
<INITIAL>\[:\^[[:alnum:][:digit:][:space:][:xdigit:][:cntrl:]]*:\]	|
<INITIAL>\[:[[:alnum:][:digit:][:space:][:xdigit:][:cntrl:]]*:\]	{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, yytext);						
						return T_POSIX_OUT;
					}
						
<class>"[:^alnum:]"	|
<class>"[:alnum:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_ALNUM;}
<class>"[:^alpha:]"	|
<class>"[:alpha:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_ALPHA;}
<class>"[:^ascii:]"	|
<class>"[:ascii:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_ASCII;}
<class>"[:^blank:]"	|
<class>"[:blank:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_BLANK;}
<class>"[:^cntrl:]"	|
<class>"[:cntrl:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_CNTRL;}
<class>"[:^digit:]"	|
<class>"[:digit:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_DIGIT;}
<class>"[:^graph:]"	|
<class>"[:graph:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_GRAPH;}
<class>"[:^lower:]"	|
<class>"[:lower:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_LOWER;}
<class>"[:^print:]"	|
<class>"[:print:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_PRINT;}
<class>"[:^punct:]"	|
<class>"[:punct:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_PUNCT;}
<class>"[:^space:]"	|
<class>"[:space:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_SPACE;}
<class>"[:^upper:]"	|
<class>"[:upper:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_UPPER;}
<class>"[:^word:]"	|
<class>"[:word:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_WORD;}
<class>"[:^xdigit:]"	|
<class>"[:xdigit:]"	{yylval->cValue = yytext[2]; yyextra->bFirstClass = 0; return T_POSIX_XDIGIT;}

<class>\[:\^[[:alnum:][:digit:][:space:][:xdigit:][:cntrl:]]*:\]	|
<class>\[:[[:alnum:][:digit:][:space:][:xdigit:][:cntrl:]]*:\]		{
						yylval->strValue = (char*)malloc(sizeof(char)*strlen(yytext)+1);
						strcpy(yylval->strValue, yytext);						
						return T_POSIX_UNKNOWN;
					}

<INITIAL,class>"."	{yyextra->bFirstClass = 0; return T_ANY;}
<INITIAL,class>.	{yylval->cValue = yytext[0]; yyextra->bFirstClass = 0; return T_CHAR;}

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


