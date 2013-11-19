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

#ifndef AST_H
#define AST_H

#define SIZE_ARRAY_GROUPS 100
#define SIZE_ARRAY_LINESINFO 1024
#define BLOCK_SIZE 4096

#define UNUSED(x) (void)(x)

#include "symtab.h"

typedef enum _UnicodePropertiesType
{	
	UPROP_Letter = 1,
	UPROP_Lowercase_Letter,
	UPROP_Uppercase_Letter,
	UPROP_Titlecase_Letter,
	UPROP_Cased_Letter,
	UPROP_Modifier_Letter,
	UPROP_Other_Letter,
	UPROP_Mark,
	UPROP_Non_Spacing_Mark,
	UPROP_Spacing_Combining_Mark,
	UPROP_Enclosing_Mark,
	UPROP_Separator,
	UPROP_Space_Separator,
	UPROP_Line_Separator,
	UPROP_Paragraph_Separator,
	UPROP_Symbol,
	UPROP_Math_Symbol,
	UPROP_Currency_Symbol,
	UPROP_Modifier_Symbol,
	UPROP_Other_Symbol,
	UPROP_Number,
	UPROP_Decimal_Digit_Number,
	UPROP_Letter_Number,
	UPROP_Other_Number,
	UPROP_Punctuation,
	UPROP_Dash_Punctuation,
	UPROP_Open_Punctuation,
	UPROP_Close_Punctuation,
	UPROP_Initial_Punctuation,
	UPROP_Final_Punctuation,
	UPROP_Connector_Punctuation,
	UPROP_Other_Punctuation,
	UPROP_Other,
	UPROP_Control,
	UPROP_Format,
	UPROP_Private_Use,
	UPROP_Surrogate,
	UPROP_Unassigned
} UnicodePropertiesType;

typedef enum _UnicodeScriptsType
{	
	USCRIPT_Arabic = 1,
	USCRIPT_Armenian,
	USCRIPT_Avestan,
	USCRIPT_Balinese,
	USCRIPT_Bamum,
	USCRIPT_Bengali,
	USCRIPT_Bopomofo,
	USCRIPT_Braille,
	USCRIPT_Buginese,
	USCRIPT_Buhid,
	USCRIPT_Canadian_Aboriginal,
	USCRIPT_Carian,
	USCRIPT_Cham,
	USCRIPT_Cherokee,
	USCRIPT_Common,
	USCRIPT_Coptic,
	USCRIPT_Cuneiform,
	USCRIPT_Cypriot,
	USCRIPT_Cyrillic,
	USCRIPT_Deseret,
	USCRIPT_Devanagari,
	USCRIPT_Egyptian_Hieroglyphs,
	USCRIPT_Ethiopic,
	USCRIPT_Georgian,
	USCRIPT_Glagolitic,
	USCRIPT_Gothic,
	USCRIPT_Greek,
	USCRIPT_Gujarati,
	USCRIPT_Gurmukhi,
	USCRIPT_Han,
	USCRIPT_Hangul,
	USCRIPT_Hanunoo,
	USCRIPT_Hebrew, Hiragana,
	USCRIPT_Imperial_Aramaic,
	USCRIPT_Inherited,
	USCRIPT_Inscriptional_Pahlavi,
	USCRIPT_Inscriptional_Parthian,
	USCRIPT_Javanese,
	USCRIPT_Kaithi,
	USCRIPT_Kannada,
	USCRIPT_Katakana,
	USCRIPT_Kayah_Li,
	USCRIPT_Kharoshthi,
	USCRIPT_Khmer,
	USCRIPT_Lao,
	USCRIPT_Latin,
	USCRIPT_Lepcha,
	USCRIPT_Limbu,
	USCRIPT_Linear_B,
	USCRIPT_Lisu,
	USCRIPT_Lycian,
	USCRIPT_Lydian,
	USCRIPT_Malayalam,
	USCRIPT_Meetei_Mayek,
	USCRIPT_Mongolian,
	USCRIPT_Myanmar,
	USCRIPT_New_Tai_Lue,
	USCRIPT_Nko,
	USCRIPT_Ogham,
	USCRIPT_Old_Italic,
	USCRIPT_Old_Persian,
	USCRIPT_Old_South_Arabian,
	USCRIPT_Old_Turkic,
	USCRIPT_Ol_Chiki,
	USCRIPT_Oriya,
	USCRIPT_Osmanya,
	USCRIPT_Phags_Pa,
	USCRIPT_Phoenician,
	USCRIPT_Rejang,
	USCRIPT_Runic,
	USCRIPT_Samaritan,
	USCRIPT_Saurashtra,
	USCRIPT_Shavian,
	USCRIPT_Sinhala,
	USCRIPT_Sundanese,
	USCRIPT_Syloti_Nagri,
	USCRIPT_Syriac,
	USCRIPT_Tagalog,
	USCRIPT_Tagbanwa,
	USCRIPT_Tai_Le,
	USCRIPT_Tai_Tham,
	USCRIPT_Tai_Viet,
	USCRIPT_Tamil,
	USCRIPT_Telugu,
	USCRIPT_Thaana,
	USCRIPT_Thai,
	USCRIPT_Tibetan,
	USCRIPT_Tifinagh,
	USCRIPT_Ugaritic,
	USCRIPT_Vai,
	USCRIPT_Yi
} UnicodeScriptsType;

typedef enum _enumTipo1
{	
	AST_OR,	
	AST_CONCATENATION,
	AST_STAR,
	AST_PLUS,
	AST_QUESTION,
	AST_REPRANGE,
	AST_LAZY_STAR,
	AST_LAZY_PLUS,
	AST_LAZY_QUESTION,
	AST_LAZY_REPRANGE,	
	AST_POSSESSIVE_STAR,
	AST_POSSESSIVE_PLUS,
	AST_POSSESSIVE_QUESTION,
	AST_POSSESSIVE_REPRANGE,
	AST_RANGE,
	AST_GROUP,
	AST_LOOKAROUND,
	AST_POSITIVE_LOOKAHEAD,
	AST_NEGATIVE_LOOKAHEAD,
	AST_POSITIVE_LOOKBEHIND,
	AST_NEGATIVE_LOOKBEHIND,
	AST_POSITIVE_SET,
	AST_NEGATIVE_SET,
	AST_SET_ITEMS,
	AST_CHAR,
	AST_STRING,
	AST_SPECIALCHAR,
	AST_POSIX_ALNUM,
	AST_POSIX_ALPHA,
	AST_POSIX_ASCII,
	AST_POSIX_BLANK,
	AST_POSIX_CNTRL,
	AST_POSIX_DIGIT,
	AST_POSIX_GRAPH,
	AST_POSIX_LOWER,
	AST_POSIX_PRINT,
	AST_POSIX_PUNCT,
	AST_POSIX_SPACE,
	AST_POSIX_UPPER,
	AST_POSIX_WORD,
	AST_POSIX_XDIGIT,
	AST_KAPPA,
	AST_NUL,
	AST_OCTAL,
	AST_HEX,
	AST_UNICODE,
	AST_UNICODE_PROP,
	AST_UNICODE_SCRIPT,
	AST_UNICODE_SCRIPT_NEG,
	AST_UNICODE_BLOCK,
	AST_UNICODE_BLOCK_NEG,	
    AST_INTEGER,
    AST_ANY,
    AST_UNICODE_ANY,
    AST_BACKREF,
    AST_BEGIN,
    AST_END,
    AST_BEGIN_END,
    AST_VOID_LINE
} enumTipo1;

typedef union _Valore
{
	char *strVal;
	char cVal;
    int iVal;
} Valore;

typedef enum  _nodeEnum { typeCon, typeOpr } nodeEnum;

/* constants */
typedef struct _conNodeType
{
	Valore value;
} conNodeType;

/* operators */
typedef struct _oprNodeType
{
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

typedef struct nodeTypeTag
{
    nodeEnum type;              /* type of node */
	/*enumTipo1 type1; */
	int type1;

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union
	{
        conNodeType con;        /* constants */
        oprNodeType opr;        /* operators */
    } u;
} nodeType;

/* ------------------------------------------------------------------------------------------------ */

typedef struct _LineInfo
{
	int index1;
	int index2;	
} LineInfo;

typedef struct _LinesInfo
{
	int count;
	LineInfo *pArrayLineInfo;
} LinesInfo;

typedef struct _MyLexParam
{
	char szString[1024];
	int indexString;	
	int bFirstClass;
	int bBegin;
	int bEnd;
	int prevState;
	HashTable **pHT_UnicodeScripts;
	HashTable **pHT_UnicodeBlocks;
} MyLexParam;

typedef struct _TranslateParams
{
	int bInSet;
	nodeType* arrayGroups[SIZE_ARRAY_GROUPS];
	int countGroups;
	HashTable **pHT_UnicodeBlocks;
} TranslateParams;


/* prototypes */
nodeType *con(int t1, Valore value);
nodeType *opr(int oper, int nops, ...);
void freeNode(nodeType *p);

char* readLine(char const *szFileName, int lineNum);
void initTranslateParams(TranslateParams *pParams);
void translate(nodeType *pTree, TranslateParams *pParams);

#endif /* AST_H */
