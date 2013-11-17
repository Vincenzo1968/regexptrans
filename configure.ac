#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([RegExpTranslator], [1.0], [vincenzo.locicero@libero.it])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([gnu -Wall -Werror])
AC_CONFIG_SRCDIR([it_to_re/main.c])
AC_CONFIG_SRCDIR([re_to_it/main.c])
AC_CONFIG_HEADERS([config.h])
AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([malloc.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC

AC_CONFIG_FILES([Makefile it_to_re/Makefile re_to_it/Makefile])
AC_OUTPUT
