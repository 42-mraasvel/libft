#include "ft_string.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int (*ConversionFunction)(String*, va_list*);

static int string_conversion(String* str, va_list* ap) {
	char* s = va_arg(*ap, char*);
	return string_push_cstr(str, s);
}

static int char_conversion(String* str, va_list* ap) {
	int ch = va_arg(*ap, int);
	return string_push_back(str, ch);
}

static int int_conversion(String* str, va_list* ap) {
	int n = va_arg(*ap, int);
	char* s = ft_itoa(n);
	if (!s) {
		return -1;
	}
	int result = string_push_cstr(str, s);
	free(s);
	return result;
}

static int conversion_dispatch(String* str, va_list* ap, int ch) {
	static const ConversionFunction conversions[255] = {
		['s'] = string_conversion,
		['c'] = char_conversion,
		['d'] = int_conversion
	};

	if (conversions[ch] == NULL) {
		fprintf(stderr, "conversion not supported: %c\n", ch);
		return -1;
	}
	return (conversions[ch])(str, ap);
}

static int handle_conversion(String* str, const char* fmt, va_list* ap) {
	return conversion_dispatch(str, ap, *fmt);
}

/**
 * @brief returns a String object for the given format string
 * 
 * @param fmt format string
 * @param ... conversion arguments
 * @return String 
 */
String* string_format(const char* fmt, ...) {
	String* str = string_new(0);
	if (str == NULL) {
		return NULL;
	}
	va_list ap;
	va_start(ap, fmt);
	for (int i = 0; fmt[i] != '\0'; i++) {
		if (fmt[i] == '%') {
			i += 1;
			if (fmt[i] == '\0') {
				// invalid format string: program is considered invalid so abort
				abort();
			} else if (handle_conversion(str, fmt + i, &ap) == -1) {
				goto ERROR;
			}
		} else {
			if (string_push_back(str, fmt[i]) == -1) {
				goto ERROR;
			}
		}
	}
	va_end(ap);
	return str;
ERROR:
	string_destroy(str);
	va_end(ap);
	return NULL;
}
