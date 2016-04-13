/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_test_class.h"



static int le_test_class;

PHP_FUNCTION(rs_echo)
{
	char *arg = NULL;
	size_t arg_len;
	zend_string *strg;
	if(zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &arg, &arg_len) == FAILURE) {
		return ;
	}

	strg = strpprintf(0, "hello word %s!", arg);
	RETURN_STR(strg);
}



PHP_MINIT_FUNCTION(test_class)
{
	return SUCCESS;
}


PHP_MSHUTDOWN_FUNCTION(test_class)
{
	return SUCCESS;
}



PHP_RINIT_FUNCTION(test_class)
{
#if defined(COMPILE_DL_TEST_CLASS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}



PHP_RSHUTDOWN_FUNCTION(test_class)
{
	return SUCCESS;
}


PHP_MINFO_FUNCTION(test_class)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "test_class support", "enabled");
	php_info_print_table_end();

}


const zend_function_entry test_class_functions[] = {
	PHP_FE(rs_echo, NULL)
	PHP_FE_END	/* Must be the last line in test_class_functions[] */
};


zend_module_entry test_class_module_entry = {
	STANDARD_MODULE_HEADER,
	"test_class",
	test_class_functions,
	PHP_MINIT(test_class),
	PHP_MSHUTDOWN(test_class),
	PHP_RINIT(test_class),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(test_class),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(test_class),
	PHP_TEST_CLASS_VERSION,
	STANDARD_MODULE_PROPERTIES
};


#ifdef COMPILE_DL_TEST_CLASS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(test_class)
#endif

