#include "ft_string.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct FormatFlags {
	int precision;
	char modifiers[2];
} FormatFlags;

FormatFlags formatflags_init() {
	FormatFlags flags;
	flags.precision = -1;
	return flags;
}

typedef int (*ConversionFunction)(String*, va_list*, FormatFlags*);

static int string_conversion(String* str, va_list* ap, FormatFlags* flags) {
	char* s = va_arg(*ap, char*);
	if (flags->precision == -1) {
		return string_push_cstr(str, s);
	}
	for (int i = 0; i < flags->precision && s[i] != '\0'; i++) {
		if (string_push_back(str, s[i]) == -1) {
			return -1;
		}
	}
	return 0;
}

static int char_conversion(String* str, va_list* ap, FormatFlags* flags) {
	(void)flags;
	int ch = va_arg(*ap, int);
	return string_push_back(str, ch);
}

static int int_conversion(String* str, va_list* ap, FormatFlags* flags) {
	(void)flags;
	int n = va_arg(*ap, int);
	char* s = ft_itoa(n);
	if (!s) {
		return -1;
	}
	int result = string_push_cstr(str, s);
	free(s);
	return result;
}

static int conversion_dispatch(String* str, va_list* ap, int ch, FormatFlags* flags) {
	static const ConversionFunction conversions[255] = {
		['s'] = string_conversion,
		['c'] = char_conversion,
		['d'] = int_conversion
	};

	if (conversions[ch] == NULL) {
		fprintf(stderr, "conversion not supported: %c\n", ch);
		return -1;
	}
	return (conversions[ch])(str, ap, flags);
}

static void skip_number(const char** s) {
	if (**s == '-' || **s == '+') {
		*s += 1;
	}
	while (ft_isdigit(**s)) {
		*s += 1;
	}
}

static int parse_flags(const char** fmt, FormatFlags* flags) {
	if (**fmt == '.') {
		// precision
		*fmt += 1;
		flags->precision = ft_atoi(*fmt);
		skip_number(fmt);
	}
	return 0;
}

static int handle_conversion(String* str, const char** fmt, va_list* ap) {
	FormatFlags flags = formatflags_init();
	if (parse_flags(fmt, &flags) == -1) {
		return -1;
	}
	int result = conversion_dispatch(str, ap, **fmt, &flags);
	*fmt += 1;
	return result;
}

static String* do_string_format(const char* fmt, va_list* ap) {
	String* str = string_new(0);
	if (str == NULL) {
		return NULL;
	}
	while (*fmt != '\0') {
		if (*fmt == '%') {
			fmt += 1;
			if (*fmt == '\0') {
				abort();
			} else if (handle_conversion(str, &fmt, ap) == -1) {
				goto ERROR;
			}
		} else {
			if (string_push_back(str, *fmt) == -1) {
				goto ERROR;
			}
			fmt += 1;
		}
	}
	return str;
ERROR:
	string_destroy(str);
	return NULL;

}

/**
 * @brief returns a String object for the given format string
 * 
 * Precision: `%.NUMBER` only works for STRING conversion
 * 
 * @param fmt format string
 * @param ... conversion arguments
 * @return String 
 */
String* string_format(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	String* s = do_string_format(fmt, &ap);
	va_end(ap);
	return s;
}

char* cstr_format(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	String* s = do_string_format(fmt, &ap);
	va_end(ap);
	if (!s) {
		return NULL;
	}
	char* cstr = s->chars->table;
	s->chars->table = NULL;
	string_destroy(s);
	return cstr;
}
