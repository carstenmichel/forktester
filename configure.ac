#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(forktester, 1.0, carsten.michel@de.ibm.com)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_SRCDIR([src/fork.c])
AC_CONFIG_HEADERS([config.h])
AC_CHECK_FUNCS([gettimeofday])
AC_CHECK_FUNCS([strerror])
AC_CHECK_HEADERS([string.h])
AC_CHECK_HEADERS([sys/time.h])
AC_FUNC_FORK

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile)
