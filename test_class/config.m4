dnl $Id$
dnl config.m4 for extension test_class

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(test_class, for test_class support,
dnl Make sure that the comment is aligned:
dnl [  --with-test_class             Include test_class support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(test_class, whether to enable test_class support,
Make sure that the comment is aligned:
[  --enable-test_class           Enable test_class support])

if test "$PHP_TEST_CLASS" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-test_class -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/test_class.h"  # you most likely want to change this
  dnl if test -r $PHP_TEST_CLASS/$SEARCH_FOR; then # path given as parameter
  dnl   TEST_CLASS_DIR=$PHP_TEST_CLASS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for test_class files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       TEST_CLASS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$TEST_CLASS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the test_class distribution])
  dnl fi

  dnl # --with-test_class -> add include path
  dnl PHP_ADD_INCLUDE($TEST_CLASS_DIR/include)

  dnl # --with-test_class -> check for lib and symbol presence
  dnl LIBNAME=test_class # you may want to change this
  dnl LIBSYMBOL=test_class # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $TEST_CLASS_DIR/$PHP_LIBDIR, TEST_CLASS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_TEST_CLASSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong test_class lib version or lib not found])
  dnl ],[
  dnl   -L$TEST_CLASS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(TEST_CLASS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(test_class, test_class.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
