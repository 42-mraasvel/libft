#include "ft_string.h"
#include "libft.h"
#include <stdarg.h>

String* string_new(size_t capacity) {
	String* s = malloc(1 * sizeof(String));
	if (s == NULL) {
		return NULL;
	}
	s->chars = vecchar_construct(capacity);
	if (s->chars == NULL) {
		free(s);
		return NULL;
	}
	return s;
}

String* string_from(const char* src) {
	size_t len = ft_strlen(src) + 1;
	String* s = string_new(len);
	if (!s) {
		return NULL;
	}
	ft_memcpy(s->chars->table, src, len);
	s->chars->length = len;
	return s;
}

size_t string_length(String* str) {
	return str->chars->length;
}

void string_destroy(String* str) {
	if (!str) {
		return;
	}
	vecchar_destroy(str->chars);
	free(str);
}

int string_push_back(String* str, char ch) {
	return vecchar_push_back(str->chars, ch);
}

char* string_cstr(String* str) {
	return str->chars->table;
}

static int handle_conversion(String* str, const char* fmt, va_list* ap) {
	if (*fmt != 's') {
		return -1;
	}
	char* s = va_arg(*ap, char*);
	for (int i = 0; s[i] != '\0'; i++) {
		if (string_push_back(str, s[i]) == -1) {
			return -1;
		}
	}
	return 0;
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
			} else if (fmt[i] == '%') {
				if (string_push_back(str, '%') == -1) {
					goto ERROR;
				}
			} else if (handle_conversion(str, fmt + i, &ap) == -1) {
				goto ERROR;
			}
		} else {
			if (string_push_back(str, fmt[i]) == -1) {
				goto ERROR;
			}
		}
	}
	if (string_push_back(str, '\0') == -1) {
		goto ERROR;
	}
	va_end(ap);
	return str;
ERROR:
	string_destroy(str);
	va_end(ap);
	return NULL;
}

MONOVEC_DEFINITIONS(char, VecChar, vecchar);
