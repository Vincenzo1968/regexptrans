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

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "symtab.h"
#include "ast.h"
#include "parser.h"
#include "lexer.h"

/*
http://www.regular-expressions.info/
 
http://www.regular-expressions.info/possessive.html
http://docs.oracle.com/javase/tutorial/essential/regex/quant.html
http://www.xyzws.com/javafaq/what-are-differences-among-greedy-reluctant-and-possessive-quantifiers-in-java-patterns/206
 
http://www.regular-expressions.info/posixbrackets.html
 
http://www.charlestonsw.com/perl-regular-expression-k-trick/

http://docstore.mik.ua/orelly/unix/upt/ch26_04.htm

http://www.hscripts.com/tutorials/regular-expression/metacharacter-list.php

http://swtch.com/~rsc/regexp/ 
http://swtch.com/~rsc/regexp/regexp1.html
http://swtch.com/~rsc/regexp/regexp2.html
http://swtch.com/~rsc/regexp/regexp3.html
http://swtch.com/~rsc/regexp/regexp4.html

http://www.cs.umd.edu/class/spring2013/cmsc330/p2/
 
http://perldoc.perl.org/perlrebackslash.html
 
http://www.zytrax.com/tech/web/regex.htm
 
http://msdn.microsoft.com/en-us/library/h5181w5w.aspx
http://msdn.microsoft.com/en-us/library/4edbef7e.aspx
 
http://vertstudios.com/blog/back-references-quantifiers-and-anchors-in-regex/

IMPORTANTE: Verificare le regexp:
http://regexpal.com/
http://regexpal.com/?flags=m&regex=[a-zA-Z0-9+]%2B[0-9]$&input=You+have+5+dollars.%0AI+want+2%0AMy+number+is+903+330+5057%0A903+330+5057+is+my+number.+
http://www.regexplanet.com/
http://regex.larsolavtorvik.com/
http://www.rubular.com/

[img]http://img585.imageshack.us/img585/7079/jra5.jpg[/img]
*/


/*
Table 26.1: Regular Expression Anchor Character Examples:

Pattern		Matches
^A			An A at the beginning of a line
A$			An A at the end of a line
A			An A anywhere on a line
$A			A $A anywhere on a line
^\^			A ^ at the beginning of a line
^^			Same as ^\^
\$$			A $ at the end of a line
$$			Same as \$$
*/

int initUnicodeScriptsTable(HashTable **pHashTable)
{
	int ret = 0;
		
	ret = htInsert(pHashTable, "Arabic", "", "");
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Armenian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Avestan", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Balinese", "", "");
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Bamum", "", "");	
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Bengali", "", "");	
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Bopomofo", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Braille", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Buginese", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Buhid", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Canadian_Aboriginal", "", "");
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Carian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Cham", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Cherokee", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Common", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Coptic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Cuneiform", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Cypriot", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Cyrillic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Deseret", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Devanagari", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Egyptian_Hieroglyphs", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Ethiopic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Georgian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Glagolitic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Gothic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Greek", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Gujarati", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Gurmukhi", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Han", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Hangul", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Hanunoo", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Hebrew, Hiragana", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Imperial_Aramaic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Inherited", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Inscriptional_Pahlavi", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Inscriptional_Parthian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Javanese", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Kaithi", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Kannada", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Katakana", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Kayah_Li", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Kharoshthi", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Khmer", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Lao", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Latin", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Lepcha", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Limbu", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Linear_B", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Lisu", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Lycian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Lydian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Malayalam", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Meetei_Mayek", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Mongolian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Myanmar", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "New_Tai_Lue", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Nko", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Ogham", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Old_Italic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Old_Persian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Old_South_Arabian", "", "");
	if ( !ret )
		return ret;
	ret = htInsert(pHashTable, "Old_Turkic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Ol_Chiki", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Oriya", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Osmanya", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Phags_Pa", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Phoenician", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Rejang", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Runic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Samaritan", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Saurashtra", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Shavian", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Sinhala", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Sundanese", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Syloti_Nagri", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Syriac", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tagalog", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tagbanwa", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tai_Le", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tai_Tham", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tai_Viet", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tamil", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Telugu", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Thaana", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Thai", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tibetan", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Tifinagh", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Ugaritic", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Vai", "", "");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "Yi", "", "");
	if ( !ret )
		return ret;	
	
	return ret;
}

int initUnicodeBlocksTable(HashTable **pHashTable)
{
	int ret = 0;

	ret = htInsert(pHashTable, "InBasic_Latin", "U+0000", "U+007F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLatin-1_Supplement", "U+0080", "U+00FF");
	if ( !ret )
		return ret;			
	ret = htInsert(pHashTable, "InLatin_Extended-A", "U+0100", "U+017F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLatin_Extended-B", "U+0180", "U+024F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InIPA_Extensions", "U+0250", "U+02AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSpacing_Modifier_Letters", "U+02B0", "U+02FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCombining_Diacritical_Marks", " U+0300", "U+036F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGreek_and_Coptic", "U+0370", "U+03FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCyrillic", "U+0500", "U+052F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InArmenian", "U+0530", "U+058F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHebrew", "U+0590", "U+05FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InArabic", "U+0600", "U+06FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSyriac", " U+0700", "U+074F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InThaana", "U+0780", "U+07BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InDevanagari", " U+0900", "U+097F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBengali", "U+0980", "U+09FF ");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGurmukhi", "U+0A00", "U+0A7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGujarati}", "U+0A80", "U+0AFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InOriya", "U+0B00", "U+0B7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTamil", "U+0B80", "U+0BFF ");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTelugu", "U+0C00", "U+0C7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKannada", " U+0C80", "U+0CFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMalayalam", "U+0D00", "U+0D7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSinhala", "U+0D80", "U+0DFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InThai", "U+0E00", "U+0E7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLao", "U+0E80", "U+0EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTibetan", "U+0F00", "U+0FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMyanmar", " U+1000", "U+109F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGeorgian", " U+10A0", "U+10FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHangul_Jamo", "U+1100", "U+11FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InEthiopic", "U+1200", "U+137F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCherokee", "U+13A0", "U+13FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InUnified_Canadian_Aboriginal_Syllabics", "U+1400", "U+167F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InOgham", "U+1680", "U+169F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InRunic", "U+16A0", "U+16FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTagalog", "U+1700", "U+171F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHanunoo", "U+1720", "U+173F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBuhid", " U+1740", "U+175F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTagbanwa", "U+1760", "U+177F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKhmer", "U+1780", "U+17FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMongolian", "U+1800", "U+18AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLimbu", "U+1900", "U+194F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InTai_Le", "U+1950", "U+197F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKhmer_Symbols", "U+19E0", "U+19FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InPhonetic_Extensions", "U+1D00", "U+1D7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLatin_Extended_Additional", "U+1E00", "U+1EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGreek_Extended", "U+1F00", "U+1FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGeneral_Punctuation", "U+2000", "U+206F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSuperscripts_and_Subscripts", "U+2070", "U+209F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCurrency_Symbols", "U+20A0", "U+20CF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCombining_Diacritical_Marks_for_Symbols", "U+20D0", "U+20FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLetterlike_Symbols", "U+2100", "U+214F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InNumber_Forms", " U+2150", "U+218F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InArrows", "U+2190", "U+21FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMathematical_Operators", "U+2200", "U+22FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMiscellaneous_Technical", "U+2300", "U+23FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InControl_Pictures", "U+2400", "U+243F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InOptical_Character_Recognition", "U+2440", "U+245F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InEnclosed_Alphanumerics", "U+2460", "U+24FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBox_Drawing", "U+2500", "U+257F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBlock_Elements", "U+2580", "U+259F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InGeometric_Shapes", "U+25A0", "U+25FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMiscellaneous_Symbols", "U+2600", "U+26FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InDingbats", " U+2700", "U+27BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMiscellaneous_Mathematical_Symbols-A", "U+27C0", "U+27EF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSupplemental_Arrows-A", "U+27F0", "U+27FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBraille_Patterns", "U+2800", "U+28FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSupplemental_Arrows-B", "U+2900", "U+297F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMiscellaneous_Mathematical_Symbols-B", "U+2980", "U+29FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSupplemental_Mathematical_Operators", "U+2A00", "U+2AFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InMiscellaneous_Symbols_and_Arrows", "U+2B00", "U+2BFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Radicals_Supplement", "U+2E80", "U+2EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKangxi_Radicals", "U+2F00", "U+2FDF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InIdeographic_Description_Characters", "U+2FF0", "U+2FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Symbols_and_Punctuation", "U+3000", "U+303F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHiragana", "U+3040", "U+309F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKatakana", "U+30A0", "U+30FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBopomofo", "U+3100", "U+312F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHangul_Compatibility_Jamo", "U+3130", "U+318F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKanbun", "U+3190", "U+319F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InBopomofo_Extended", "U+31A0", "U+31BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InKatakana_Phonetic_Extensions", "U+31F0", "U+31FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InEnclosed_CJK_Letters_and_Months", "U+3200", "U+32FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Compatibility", "U+3300", "U+33FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Unified_Ideographs_Extension_A", "U+3400", "U+4DBF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InYijing_Hexagram_Symbols", "U+4DC0", "U+4DFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Unified_Ideographs", "U+4E00", "U+9FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InYi_Syllables", "U+A000", "U+A48F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InYi_Radicals", "U+A490", "U+A4CF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHangul_Syllables", "U+AC00", "U+D7AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHigh_Surrogates", "U+D800", "U+DB7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHigh_Private_Use_Surrogates", "U+DB80", "U+DBFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InLow_Surrogates", "U+DC00", "U+DFFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InPrivate_Use_Area", "U+E000", "U+F8FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Compatibility_Ideographs", "U+F900", "U+FAFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InAlphabetic_Presentation_Forms", "U+FB00", "U+FB4F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InArabic_Presentation_Forms-A", "U+FB50", "U+FDFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InVariation_Selectors", "U+FE00", "U+FE0F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCombining_Half_Marks", "U+FE20", "U+FE2F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InCJK_Compatibility_Forms", " U+FE30", "U+FE4F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSmall_Form_Variants", "U+FE50", "U+FE6F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InArabic_Presentation_Forms-B", "U+FE70", "U+FEFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InHalfwidth_and_Fullwidth_Forms", "U+FF00", "U+FFEF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "InSpecials", "U+FFF0", "U+FFFF");
	if ( !ret )
		return ret;	

	/* ------------------------   Is prefix   ------------------------ */

	ret = htInsert(pHashTable, "IsBasic_Latin", "U+0000", "U+007F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLatin-1_Supplement", "U+0080", "U+00FF");
	if ( !ret )
		return ret;			
	ret = htInsert(pHashTable, "IsLatin_Extended-A", "U+0100", "U+017F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLatin_Extended-B", "U+0180", "U+024F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsIPA_Extensions", "U+0250", "U+02AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSpacing_Modifier_Letters", "U+02B0", "U+02FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCombining_Diacritical_Marks", " U+0300", "U+036F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGreek_and_Coptic", "U+0370", "U+03FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCyrillic", "U+0500", "U+052F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsArmenian", "U+0530", "U+058F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHebrew", "U+0590", "U+05FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsArabic", "U+0600", "U+06FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSyriac", " U+0700", "U+074F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsThaana", "U+0780", "U+07BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsDevanagari", " U+0900", "U+097F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBengali", "U+0980", "U+09FF ");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGurmukhi", "U+0A00", "U+0A7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGujarati}", "U+0A80", "U+0AFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsOriya", "U+0B00", "U+0B7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTamil", "U+0B80", "U+0BFF ");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTelugu", "U+0C00", "U+0C7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKannada", " U+0C80", "U+0CFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMalayalam", "U+0D00", "U+0D7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSinhala", "U+0D80", "U+0DFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsThai", "U+0E00", "U+0E7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLao", "U+0E80", "U+0EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTibetan", "U+0F00", "U+0FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMyanmar", " U+1000", "U+109F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGeorgian", " U+10A0", "U+10FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHangul_Jamo", "U+1100", "U+11FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsEthiopic", "U+1200", "U+137F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCherokee", "U+13A0", "U+13FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsUnified_Canadian_Aboriginal_Syllabics", "U+1400", "U+167F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsOgham", "U+1680", "U+169F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsRunic", "U+16A0", "U+16FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTagalog", "U+1700", "U+171F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHanunoo", "U+1720", "U+173F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBuhid", " U+1740", "U+175F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTagbanwa", "U+1760", "U+177F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKhmer", "U+1780", "U+17FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMongolian", "U+1800", "U+18AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLimbu", "U+1900", "U+194F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsTai_Le", "U+1950", "U+197F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKhmer_Symbols", "U+19E0", "U+19FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsPhonetic_Extensions", "U+1D00", "U+1D7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLatin_Extended_Additional", "U+1E00", "U+1EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGreek_Extended", "U+1F00", "U+1FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGeneral_Punctuation", "U+2000", "U+206F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSuperscripts_and_Subscripts", "U+2070", "U+209F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCurrency_Symbols", "U+20A0", "U+20CF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCombining_Diacritical_Marks_for_Symbols", "U+20D0", "U+20FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLetterlike_Symbols", "U+2100", "U+214F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsNumber_Forms", " U+2150", "U+218F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsArrows", "U+2190", "U+21FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMathematical_Operators", "U+2200", "U+22FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMiscellaneous_Technical", "U+2300", "U+23FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsControl_Pictures", "U+2400", "U+243F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsOptical_Character_Recognition", "U+2440", "U+245F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsEnclosed_Alphanumerics", "U+2460", "U+24FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBox_Drawing", "U+2500", "U+257F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBlock_Elements", "U+2580", "U+259F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsGeometric_Shapes", "U+25A0", "U+25FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMiscellaneous_Symbols", "U+2600", "U+26FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsDingbats", " U+2700", "U+27BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMiscellaneous_Mathematical_Symbols-A", "U+27C0", "U+27EF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSupplemental_Arrows-A", "U+27F0", "U+27FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBraille_Patterns", "U+2800", "U+28FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSupplemental_Arrows-B", "U+2900", "U+297F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMiscellaneous_Mathematical_Symbols-B", "U+2980", "U+29FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSupplemental_Mathematical_Operators", "U+2A00", "U+2AFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsMiscellaneous_Symbols_and_Arrows", "U+2B00", "U+2BFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Radicals_Supplement", "U+2E80", "U+2EFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKangxi_Radicals", "U+2F00", "U+2FDF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsIdeographic_Description_Characters", "U+2FF0", "U+2FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Symbols_and_Punctuation", "U+3000", "U+303F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHiragana", "U+3040", "U+309F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKatakana", "U+30A0", "U+30FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBopomofo", "U+3100", "U+312F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHangul_Compatibility_Jamo", "U+3130", "U+318F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKanbun", "U+3190", "U+319F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsBopomofo_Extended", "U+31A0", "U+31BF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsKatakana_Phonetic_Extensions", "U+31F0", "U+31FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsEnclosed_CJK_Letters_and_Months", "U+3200", "U+32FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Compatibility", "U+3300", "U+33FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Unified_Ideographs_Extension_A", "U+3400", "U+4DBF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsYijing_Hexagram_Symbols", "U+4DC0", "U+4DFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Unified_Ideographs", "U+4E00", "U+9FFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsYi_Syllables", "U+A000", "U+A48F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsYi_Radicals", "U+A490", "U+A4CF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHangul_Syllables", "U+AC00", "U+D7AF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHigh_Surrogates", "U+D800", "U+DB7F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHigh_Private_Use_Surrogates", "U+DB80", "U+DBFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsLow_Surrogates", "U+DC00", "U+DFFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsPrivate_Use_Area", "U+E000", "U+F8FF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Compatibility_Ideographs", "U+F900", "U+FAFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsAlphabetic_Presentation_Forms", "U+FB00", "U+FB4F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsArabic_Presentation_Forms-A", "U+FB50", "U+FDFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsVariation_Selectors", "U+FE00", "U+FE0F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCombining_Half_Marks", "U+FE20", "U+FE2F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsCJK_Compatibility_Forms", " U+FE30", "U+FE4F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSmall_Form_Variants", "U+FE50", "U+FE6F");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsArabic_Presentation_Forms-B", "U+FE70", "U+FEFF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsHalfwidth_and_Fullwidth_Forms", "U+FF00", "U+FFEF");
	if ( !ret )
		return ret;	
	ret = htInsert(pHashTable, "IsSpecials", "U+FFF0", "U+FFFF");
	if ( !ret )
		return ret;	

	return ret;
}

void printUnicodeProperties(int prop, int pos)
{
	char szNeg[256];
	
	if ( pos )
		strcpy(szNeg, " : ");
	else
		strcpy(szNeg, " diverso da ");
	
	fprintf(stdout, "un carattere unicode");
	switch ( prop )
	{
		case UPROP_Letter:
			fprintf(stdout, "%s qualsiasi tipo di lettera di qualsiasi lingua", szNeg);
			break;
		case UPROP_Lowercase_Letter:
			fprintf(stdout, "%suna lettera minuscola che ha una variante in maiuscolo", szNeg);
			break;
		case UPROP_Uppercase_Letter:
			fprintf(stdout, "%suna lettera maiuscola che ha una variante in minuscolo", szNeg);
			break;
		case UPROP_Titlecase_Letter:
			fprintf(stdout, "%suna lettera maiuscola all'inizio di una parola", szNeg);
			break;
		case UPROP_Cased_Letter:
			fprintf(stdout, "%suna lettera che esiste in entrambe le varianti minuscolo/maiuscolo", szNeg);
			break;
		case UPROP_Modifier_Letter:
			fprintf(stdout, "%scarattere speciale usato come lettera", szNeg);
			break;
		case UPROP_Other_Letter:
			fprintf(stdout, "%suna lettera o un ideogramma che non ha varianti minuscolo/maiuscolo", szNeg);
			break;
		case UPROP_Mark:
			fprintf(stdout, "%scarattere destinato ad essere combinato con un altro /*(accento, dieresi, etc)*/", szNeg);
			break;
		case UPROP_Non_Spacing_Mark:
			fprintf(stdout, "%scarattere destinato ad essere combinato con un altro senza occupare ulteriore spazio /*(accento, dieresi, etc)*/ ", szNeg);
			break;
		case UPROP_Spacing_Combining_Mark:
			fprintf(stdout, "%scarattere destinato ad essere combinato con un altro che occupa ulteriore spazio /*(segni vocalici in molte lingue orientali)*/", szNeg);
			break;
		case UPROP_Enclosing_Mark:
			fprintf(stdout, "%scarattere che racchiude il carattere viene combinato con /*(cerchio, quadrato, keycap, etc)*/", szNeg);
			break;
		case UPROP_Separator:
			fprintf(stdout, "%squalsiasi tipo di spazio bianco o separatore non visibile", szNeg);
			break;
		case UPROP_Space_Separator:
			fprintf(stdout, "%scarattere separatore non visibile che non occupa spazio", szNeg);
			break;
		case UPROP_Line_Separator:
			fprintf(stdout, "%sseparatore di linea /*U+2028*/", szNeg);
			break;
		case UPROP_Paragraph_Separator:
			fprintf(stdout, "%sseparatore di paragrafo /*U+2029*/", szNeg);
			break;
		case UPROP_Symbol:
			fprintf(stdout, "%sun simbolo qualsiasi /*(simboli matematici, simboli di valuta, segni grafici decorativi, etc)*/", szNeg);
			break;
		case UPROP_Math_Symbol:
			fprintf(stdout, "%squalsiasi simbolo matematico", szNeg);
			break;
		case UPROP_Currency_Symbol:
			fprintf(stdout, "%squalsiasi simbolo di valuta", szNeg);
			break;
		case UPROP_Modifier_Symbol:
			fprintf(stdout, "%sun carattere di combinazione /*(mark)*/", szNeg);
			break;
		case UPROP_Other_Symbol:
			fprintf(stdout, "%svari simboli che non sono simboli matematici o di valuta o di combinazione", szNeg);
			break;
		case UPROP_Number:
			fprintf(stdout, "%squalsiasi tipo di carattere numerico in qualsiasi script", szNeg);
			break;
		case UPROP_Decimal_Digit_Number:
			fprintf(stdout, "%suna cifra da zero a nove in qualsiasi script tranne script ideografici.", szNeg);
			break;
		case UPROP_Letter_Number:
			fprintf(stdout, "%sun numero simile a una lettera /*(ad esempio un numero romano)*/", szNeg);
			break;
		case UPROP_Other_Number:
			fprintf(stdout, "%suna cifra in apice o pedice o un numero che non sia una cifra da zero a nove /*(esclusi i numeri da script ideografici)*/", szNeg);
			break;
		case UPROP_Punctuation:
			fprintf(stdout, "%squalsiasi carattere di punteggiatura", szNeg);
			break;
		case UPROP_Dash_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di trattino o lineetta", szNeg);
			break;
		case UPROP_Open_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di parentesi aperta", szNeg);
			break;
		case UPROP_Close_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di parentesi chiusa", szNeg);
			break;
		case UPROP_Initial_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di virgolette aperte", szNeg);
			break;
		case UPROP_Final_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di virgolette chiuse", szNeg);
			break;
		case UPROP_Connector_Punctuation:
			fprintf(stdout, "%sun carattere di connessione /*(come una sottolineatura che connette parole)*/", szNeg);
			break;
		case UPROP_Other_Punctuation:
			fprintf(stdout, "%squalsiasi tipo di carattere di punteggiatura che non sia un trattino o parentesi o citazione o di connessione", szNeg);
			break;
		case UPROP_Other:
			fprintf(stdout, "%scaratteri di controllo invisibili e code point non utilizzati", szNeg);
			break;
		case UPROP_Control:
			fprintf(stdout, "%scarattere di controllo ascii /*0x00–0x1F*/ o Latin1 /*0x80–0x9F*/", szNeg);
			break;
		case UPROP_Format:
			fprintf(stdout, "%sindicatore di formattazione non visibile", szNeg);
			break;
		case UPROP_Private_Use:
			fprintf(stdout, "%sriservato per uso privato", szNeg);
			break;
		case UPROP_Surrogate:
			fprintf(stdout, "%ssurrogati in codifica utf16", szNeg);
			break;
		case UPROP_Unassigned:
			fprintf(stdout, "%squalsiasi code point a cui non è stato assegnato nessun carattere", szNeg);
			break;
	}
}

void translate(nodeType *pTree, TranslateParams *pParams)
{
    if (!pTree)
		return;
				
    switch(pTree->type)
	{
    case typeCon:
		if ( pTree->type1 == AST_CHAR )
		{
			fprintf(stdout, "\"%c\"", pTree->u.con.value.cVal);
		}
		else if ( pTree->type1 == AST_ANY )
		{
			fprintf(stdout, "qualunque carattere tranne nuova linea");
		}
		else if ( pTree->type1 == AST_UNICODE_ANY )
		{
			fprintf(stdout, "qualunque carattere unicode /*(compresa nuova linea)*/");
		}								
		else if ( pTree->type1 == AST_UNICODE_SCRIPT )
		{
			fprintf(stdout, "un carattere unicode che appartenga alla lingua %s", pTree->u.con.value.strVal);
		}								
		else if ( pTree->type1 == AST_UNICODE_SCRIPT_NEG )
		{
			fprintf(stdout, "un carattere unicode che non appartenga alla lingua %s", pTree->u.con.value.strVal);
		}
		else if ( pTree->type1 == AST_UNICODE_BLOCK )
		{
			HashTable *pDati = NULL;
			htFind(pParams->pHT_UnicodeBlocks, pTree->u.con.value.strVal, &pDati);
			fprintf(stdout, "un carattere unicode nel blocco %s /*(da %s a %s)*/", pDati->Key, pDati->szFrom, pDati->szTo);
		}								
		else if ( pTree->type1 == AST_UNICODE_BLOCK_NEG )
		{			
			HashTable *pDati;
			htFind(pParams->pHT_UnicodeBlocks, pTree->u.con.value.strVal, &pDati);
			fprintf(stdout, "un carattere unicode che non appartenga al blocco %s /*(da %s a %s)*/", pDati->Key, pDati->szFrom, pDati->szTo);
		}												
		else if ( pTree->type1 == AST_POSIX_ALNUM )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere alfanumerico");
			else
				fprintf(stdout, "un carattere non alfanumerico");
		}				
		else if ( pTree->type1 == AST_POSIX_ALPHA )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere alfabetico");
			else
				fprintf(stdout, "un carattere non alfabetico");
		}	
		else if ( pTree->type1 == AST_POSIX_ASCII )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere ascii");
			else
				fprintf(stdout, "un carattere non ascii");
		}
		else if ( pTree->type1 == AST_POSIX_BLANK )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere di spazio o tabulazione");
			else
				fprintf(stdout, "un carattere diverso da spazio e tabulazione");
		}
		else if ( pTree->type1 == AST_POSIX_CNTRL )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere di controllo");
			else
				fprintf(stdout, "un carattere non di controllo");
		}
		else if ( pTree->type1 == AST_POSIX_DIGIT )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere numerico");
			else
				fprintf(stdout, "un carattere non numerico");
		}
		else if ( pTree->type1 == AST_POSIX_GRAPH )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere visibile");
			else
				fprintf(stdout, "un carattere non visibile");
		}
		else if ( pTree->type1 == AST_POSIX_LOWER )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "una lettera minuscola");
			else
				fprintf(stdout, "una lettera non minuscola");
		}
		else if ( pTree->type1 == AST_POSIX_PRINT )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere stampabile");
			else
				fprintf(stdout, "un carattere non stampabile");
		}
		else if ( pTree->type1 == AST_POSIX_PUNCT )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere di punteggiatura");
			else
				fprintf(stdout, "un carattere non di punteggiatura");
		}
		else if ( pTree->type1 == AST_POSIX_SPACE )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "qualunque spazio bianco /*(compresa nuova linea)*/");
			else
				fprintf(stdout, "un carattere diverso da qualunque spazio bianco /*(compresa nuova linea)*/");
		}
		else if ( pTree->type1 == AST_POSIX_UPPER )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "una lettera maiuscola");
			else
				fprintf(stdout, "una lettera non maiuscola");
		}
		else if ( pTree->type1 == AST_POSIX_WORD )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere alfanumerico o di sottolineatura");
			else
				fprintf(stdout, "un carattere diverso da alfanumerico e sottolineatura");
		}		
		else if ( pTree->type1 == AST_POSIX_XDIGIT )
		{
			if ( pTree->u.con.value.cVal != '^' )
				fprintf(stdout, "un carattere esadecimale");
			else
				fprintf(stdout, "un carattere non esadecimale");
		}		
		else if ( pTree->type1 == AST_INTEGER )
		{
			fprintf(stdout, "%d", pTree->u.con.value.iVal);
		}
		else if ( pTree->type1 == AST_OCTAL )
		{
			fprintf(stdout, "un carattere corrispondente al codice ottale %s", pTree->u.con.value.strVal);
		}		
		else if ( pTree->type1 == AST_HEX )
		{
			fprintf(stdout, "un carattere corrispondente al codice esadecimale {%s}", pTree->u.con.value.strVal);
		}				
		else if ( pTree->type1 == AST_UNICODE )
		{
			fprintf(stdout, "un carattere corrispondente al codice unicode {%s}", pTree->u.con.value.strVal);
		}						
		else if ( pTree->type1 == AST_UNICODE_PROP )
		{
			if ( pTree->u.con.value.iVal < 0 )
				printUnicodeProperties(-pTree->u.con.value.iVal, 0);
			else
				printUnicodeProperties(pTree->u.con.value.iVal, 1);
		}						
		else if ( pTree->type1 == AST_NUL )
		{
			fprintf(stdout, "un carattere nullo /*(NUL byte)*/");
		}		
		else if ( pTree->type1 == AST_BACKREF )
		{
			if ( pTree->u.con.value.iVal > pParams->countGroups )
			{
				fprintf(stderr, "Errore backreference: riferimento a gruppo %d non valido. Ci sono soltanto %d gruppi.\n", pTree->u.con.value.iVal, pParams->countGroups);
				return;
			}
			else
			{
				translate(pParams->arrayGroups[pTree->u.con.value.iVal - 1], pParams);
			}
		}		
		else if ( pTree->type1 == AST_SPECIALCHAR )
		{
			switch (pTree->u.con.value.cVal)
			{
				case 't':
					fprintf(stdout, "un carattere di tabulazione");
					break;
				case 'v':
					fprintf(stdout, "un carattere di tabulazione verticale");
					break;				
				case 'r':
					fprintf(stdout, "un carattere di ritorno a capo");
					break;				
				case 'n':
					fprintf(stdout, "un carattere di nuova linea");
					break;								
				case 'f':
					fprintf(stdout, "un carattere di avanzamento del modulo");
					break;
				case 'a':
					fprintf(stdout, "un carattere di alert /*(suono: BEL)*/");
					break;
				case 'e':
					fprintf(stdout, "un carattere di escape /*(ESC)*/");
					break;					
				case '<':
					if ( !pParams->bInSet )
						fprintf(stdout, "un carattere delimitatore di parola /*(spazio bianco, nuova linea, etc)*/");
					else
						fprintf(stdout, "\"<\"");
					break;												
				case '>':
					if ( !pParams->bInSet )
						fprintf(stdout, "un carattere delimitatore di parola /*(spazio bianco, nuova linea, etc)*/");
					else
						fprintf(stdout, "\">\"");
					break;																	
				case 'b':
					if ( !pParams->bInSet )
						fprintf(stdout, "un carattere delimitatore di parola /*(spazio bianco, nuova linea, etc)*/");
					else
						fprintf(stdout, "un carattere di backspace");
					break;												
				case 'B':
					if ( !pParams->bInSet )
						fprintf(stdout, "un carattere che non sia delimitatore di parola /*(spazio bianco, nuova linea, etc)*/");
					else
						fprintf(stdout, "\"B\"");
					break;												
				case 'd':
					fprintf(stdout, "un carattere numerico");
					break;																
				case 'D':
					fprintf(stdout, "un carattere non numerico");
					break;																				
				case 's':
					fprintf(stdout, "qualsiasi spazio bianco /*(tabulazione, ritorno a capo, etc)*/");
					break;																				
				case 'S':
					fprintf(stdout, "un carattere qualsiasi tranne spazi bianchi /*(tabulazioni, ritorno a capo, etc)*/");
					break;																								
				case 'w':
					fprintf(stdout, "un carattere alfanumerico o di sottolineatura");
					break;																								
				case 'W':
					fprintf(stdout, "un carattere che non sia né alfanumerico né di sottolineatura");
					break;																												
			}
		}
		return;
    case typeOpr:
		{			
			switch(pTree->u.opr.oper)
			{
			case AST_OR:
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\noppure\n");
				translate(pTree->u.opr.op[1], pParams);
				return;
			case AST_CONCATENATION:
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\nseguito da ");				
				translate(pTree->u.opr.op[1], pParams);
				return;
			case AST_STAR:
				fprintf(stdout, "zero o più ");
				translate(pTree->u.opr.op[0], pParams);
				return;
			case AST_PLUS:
				fprintf(stdout, "uno o più ");
				translate(pTree->u.opr.op[0], pParams);						
				return;
			case AST_QUESTION:
				fprintf(stdout, "zero o uno ");
				translate(pTree->u.opr.op[0], pParams);						
				return;
			case AST_REPRANGE:
				if ( pTree->u.opr.op[0]->u.con.value.iVal == pTree->u.opr.op[1]->u.con.value.iVal )
				{
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);										
				}			
				else if ( pTree->u.opr.op[1]->u.con.value.iVal > 0 )
				{
					fprintf(stdout, "da ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " a ");
					translate(pTree->u.opr.op[1], pParams);			
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);
				}
				else
				{
					fprintf(stdout, "un minimo di ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);					
				}
				return;	
			case AST_LAZY_STAR:
				fprintf(stdout, "zero o più ");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, " riluttante /*(fino alla corrispondenza più vicina di)*/ \n");
				translate(pTree->u.opr.op[1], pParams);
				return;			
			case AST_LAZY_PLUS:
				fprintf(stdout, "uno o più ");
				translate(pTree->u.opr.op[0], pParams);						
				fprintf(stdout, " riluttante /*(fino alla corrispondenza più vicina di)*/ \n");
				translate(pTree->u.opr.op[1], pParams);
				return;
			case AST_LAZY_QUESTION:
				fprintf(stdout, "zero o uno ");
				translate(pTree->u.opr.op[0], pParams);									
				fprintf(stdout, " riluttante /*(fino alla corrispondenza più vicina di)*/ \n");
				translate(pTree->u.opr.op[1], pParams);
				return;																		
			case AST_LAZY_REPRANGE:
				if ( pTree->u.opr.op[0]->u.con.value.iVal == pTree->u.opr.op[1]->u.con.value.iVal )
				{
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);										
				}			
				else if ( pTree->u.opr.op[1]->u.con.value.iVal > 0 )
				{
					fprintf(stdout, "da ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " a ");
					translate(pTree->u.opr.op[1], pParams);			
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);
				}
				else
				{
					fprintf(stdout, "un minimo di ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);					
				}			
				fprintf(stdout, " riluttante /*(fino alla corrispondenza più vicina di)*/ \n");
				translate(pTree->u.opr.op[1], pParams);
				return;				
			case AST_POSSESSIVE_STAR:
				fprintf(stdout, "zero o più ");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, " possessivo /*(l'intera stringa cercata deve corrisponderre interamente al pattern)*/ seguito da \n");
				translate(pTree->u.opr.op[1], pParams);
				return;			
			case AST_POSSESSIVE_PLUS:
				fprintf(stdout, "uno o più ");
				translate(pTree->u.opr.op[0], pParams);						
				fprintf(stdout, " possessivo /*(l'intera stringa cercata deve corrisponderre interamente al pattern)*/ seguito da \n");
				translate(pTree->u.opr.op[1], pParams);
				return;
			case AST_POSSESSIVE_QUESTION:
				fprintf(stdout, "zero o uno ");
				translate(pTree->u.opr.op[0], pParams);									
				fprintf(stdout, " possessivo /*(l'intera stringa cercata deve corrisponderre interamente al pattern)*/ seguito da \n");
				translate(pTree->u.opr.op[1], pParams);
				return;																		
			case AST_POSSESSIVE_REPRANGE:
				if ( pTree->u.opr.op[0]->u.con.value.iVal == pTree->u.opr.op[1]->u.con.value.iVal )
				{
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);										
				}			
				else if ( pTree->u.opr.op[1]->u.con.value.iVal > 0 )
				{
					fprintf(stdout, "da ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " a ");
					translate(pTree->u.opr.op[1], pParams);			
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);
				}
				else
				{
					fprintf(stdout, "un minimo di ");
					translate(pTree->u.opr.op[0], pParams);
					fprintf(stdout, " ripetizioni di: ");
					translate(pTree->u.opr.op[2], pParams);					
				}			
				fprintf(stdout, " possessivo /*(l'intera stringa cercata deve corrisponderre interamente al pattern)*/ seguito da \n");
				translate(pTree->u.opr.op[1], pParams);
				return;								
			case AST_GROUP:
				pParams->arrayGroups[pParams->countGroups++] = pTree->u.opr.op[0];
				fprintf(stdout, "\n(\n");
				translate(pTree->u.opr.op[0], pParams);		
				fprintf(stdout, "\n) ");
				return;		
			case AST_KAPPA:
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\nma il match restituito sarà\n(\n");
				translate(pTree->u.opr.op[1], pParams);
				fprintf(stdout, "\n)\n");
				return;
			case AST_LOOKAROUND:
				translate(pTree->u.opr.op[0], pParams);
				translate(pTree->u.opr.op[1], pParams);
				return;
			case AST_POSITIVE_LOOKAHEAD:
				fprintf(stdout, " se e solo se seguito da\n(\n");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\n)");
				return;
			case AST_NEGATIVE_LOOKAHEAD:
				fprintf(stdout, " se e solo se non seguito da\n(\n");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\n)");
				return;
			case AST_POSITIVE_LOOKBEHIND:
				fprintf(stdout, " se e solo se preceduto da\n(\n");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\n)");			
				return;
			case AST_NEGATIVE_LOOKBEHIND:
				fprintf(stdout, " se e solo se non preceduto da\n(\n");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, "\n)");			
				return;				
			case AST_POSITIVE_SET:
				fprintf(stdout, "un carattere nell'insieme [");
				pParams->bInSet = 1;
				translate(pTree->u.opr.op[0], pParams);									
				pParams->bInSet = 0;
				fprintf(stdout, "] ");
				return;
			case AST_NEGATIVE_SET:
				fprintf(stdout, "un carattere non nell'insieme [");
				pParams->bInSet = 1;
				translate(pTree->u.opr.op[0], pParams);									
				pParams->bInSet = 0;
				fprintf(stdout, "] ");
				return;
			case AST_RANGE:
				fprintf(stdout, "un carattere tra ");
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, " e ");
				translate(pTree->u.opr.op[1], pParams);			
				/* fprintf(stdout, "]"); */
				return;
			case AST_SET_ITEMS:
				translate(pTree->u.opr.op[0], pParams);
				fprintf(stdout, ", ");
				translate(pTree->u.opr.op[1], pParams);
				return;
			}
		}
    }    
}

char* prescan(char const *s, char const *szExeName, int *bBegin, int *bEnd)
{
	char *retString = NULL;
	int len;
	
	*bBegin = *bEnd = 0;
	
	len = strlen(s);
	if ( len <= 0 )
	{
		fprintf(stderr, "Uso: %s regexp\nCon regexp stringa non vuota.\n", szExeName);
		return NULL;
	}
		
	if ( s[0] == '^' )
		*bBegin = 1;
		
	if ( s[len-1] == '$' )
		*bEnd = 1;
		
	if ( s[len-1] == '\\' )
	{
		fprintf(stderr, "Errore: Carattere \"backslash\" alla fine della riga\n");
		return NULL;		
	}
		
		
	if ( len >= 2 && s[len-2] == '\\' )
		*bEnd = 0;
		
	retString = (char*)malloc(sizeof(char) * (len + 1));
	if ( !retString )
	{
		fprintf(stderr, "Errore prescan: memoria insufficiente.\n");
		return NULL;
	}
	retString[0] = '\0';
	
	if ( *bBegin )
		strncpy(retString, s + 1, len + 1);
	else
		strncpy(retString, s, len + 1);
		
	len = strlen(retString);
		
	if ( *bEnd )
		retString[len - 1] = '\0';
	
	return retString;	
}

/*
valgrind --leak-check=full --show-reachable=yes --track-origins=yes --log-file=outValgrind.txt ./retoit_debug 'ciao\125 a tutti!{1,3}'
* 
valgrind --leak-check=full --show-reachable=yes --track-origins=yes --log-file=outValgrind.txt ./retoit_debug 'abc\p{InBasic_Latin}\p{InLatin-1_Supplement}\P{InBasic_Latin}\P{InLatin-1_Supplement}y\p{L}\p{Number}'
 
http://sourceforge.net/p/flex/bugs/140/

http://sourceforge.net/p/flex/bugs/115/
 
http://sourceforge.net/p/flex/bugs/160/
 
echo 'abcdeabcdeabcxyz' | grep -Po 'a.*?abc.*a\Kbc.*'

echo 'abcdeabcdeabcxyz' | grep -Po 'a(.*?)abc.*a\Kbc.*'
 
http://www.ubuntu-it.org/contribuiamo
*/

int main ( int argc, char * argv[] )
{
	yyscan_t scanner;
	nodeType *pTree = NULL;
	MyLexParam lexParam;
	TranslateParams tParams;
	int bBegin, bEnd;
	char *strNew = NULL;
	int countGroups = 0;
	
	int ret;
	int i;
	
	if ( argc != 2 )
	{
		fprintf(stderr, "Uso: %s regexp\n", argv[0]);
		return -1;
	}
	
	lexParam.pHT_UnicodeScripts = (HashTable**)malloc(sizeof(HashTable*) * HT_SIZE);
	if ( !lexParam.pHT_UnicodeScripts )
	{
		fprintf(stderr, "Impossibile creare l'hashtable per unicode scripts.\n");
		return -1;		
	}
	for (i = 0; i < HT_SIZE; i++)
	{
		lexParam.pHT_UnicodeScripts[i] = NULL;
	}
	
	lexParam.pHT_UnicodeBlocks = (HashTable**)malloc(sizeof(HashTable*) * HT_SIZE);
	if ( !lexParam.pHT_UnicodeBlocks )
	{
		fprintf(stderr, "Impossibile creare l'hashtable per unicode blocks.\n");
		return -1;		
	}
	for (i = 0; i < HT_SIZE; i++)
	{
		lexParam.pHT_UnicodeBlocks[i] = NULL;
	}
					
	strNew = prescan(argv[1], argv[0], &bBegin, &bEnd);
	if ( strNew == NULL )
		return -1;
			
	if ( bBegin && bEnd && strlen(argv[1]) == 2 )
	{
		fprintf(stdout, "\n# L'espressione regolare '%s' si legge:\n\n", argv[1]);
		fprintf(stdout, "linea /*(o stringa)*/ vuota\n\n");
		return 0;
	}
	
	
	ret = initUnicodeScriptsTable(lexParam.pHT_UnicodeScripts);
	if ( ret != 1 )
		goto uscita;	
		
	ret = initUnicodeBlocksTable(lexParam.pHT_UnicodeBlocks);
	if ( ret != 1 )
		goto uscita;
	
	lexParam.bFirstClass = 1;
	lexParam.bBegin = bBegin;
	lexParam.bEnd = bEnd;
			
	yylex_init_extra(&lexParam, &scanner);
	yy_scan_string(strNew, scanner);
	
	initTranslateParams(&tParams);
	tParams.pHT_UnicodeBlocks = lexParam.pHT_UnicodeBlocks;
						
	ret = yyparse(scanner, &pTree, argv[1], &countGroups);
	
		
	if ( ret != 0 )
		goto uscita;
		
	if ( pTree == NULL )
	{
		goto uscita;
	}

	fprintf(stdout, "\n# L'espressione regolare '%s' si legge:\n\n", argv[1]);
	
	if ( bBegin && bEnd )
		fprintf(stdout, "all'inizio e alla fine della linea /*(o stringa)*/ :\n");
	else if ( bBegin )
		fprintf(stdout, "all'inizio della linea /*(o stringa) */ :\n");
	else if ( bEnd )
		fprintf(stdout, "alla fine della linea /*(o stringa) */ :\n");
		
	/*		
	initTranslateParams(&tParams);
	
	tParams.pHT_UnicodeBlocks = lexParam.pHT_UnicodeBlocks;
	*/
		
	translate(pTree, &tParams);
	
	fprintf(stdout, "\n");
	
uscita:
	
	htFree(lexParam.pHT_UnicodeScripts);
	htFree(lexParam.pHT_UnicodeBlocks);
	
	yylex_destroy(scanner);
	
	freeNode(pTree);
	
	free(strNew);
	
	return 0;
}


/*
int main ( int argc, char * argv[] )
{
	FILE *in = NULL;
	yyscan_t scanner;
	nodeType *pTree = NULL;
	MyLexParam lexParam;
	
	int ret;
	
	if ( argc != 2 )
	{
		fprintf(stderr, "Uso: %s regexp\n", argv[0]);
		return -1;
	}
	
	in = fopen(argv[1], "r");
	if ( in == NULL )
	{
		printf("Errore nell'apertura del file '%s'\n", argv[1]);
		return -1;
	}
	
	lexParam.bFirstClass = 1;
	
	yylex_init_extra(&lexParam, &scanner);
	yyset_in(in, scanner);
			
	ret = yyparse(scanner, &pTree);
		
	if ( ret != 0 )
		goto uscita;
		
	if ( pTree == NULL )
	{
		goto uscita;
	}
		
	translate(pTree);
	
	fprintf(stdout, "\n");
	
uscita:
	yylex_destroy(scanner);
	
	fclose(in);
	
	freeNode(pTree);
	
	return 0;
}
*/
