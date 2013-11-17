AM_CFLAGS=-Wall -W -pedantic -O3
AM_YACC=bison

bin_PROGRAMS = ittore
BUILT_SOURCES = parser.c parser.h lexer.c lexer.h
AM_YFLAGS = -vd -o parser.c
AM_LFLAGS = -f -L -Ca
ittore_SOURCES = symtab.c ast.c parser.y lexer.l main.c

lexer.c lexer.h: lexer.l
	flex -f -L -Ca lexer.l

parser.c parser.h: parser.y
	bison -vd -o parser.c parser.y
