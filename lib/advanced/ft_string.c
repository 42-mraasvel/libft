#include "ft_string.h"
#include "libft.h"
#include <stdarg.h>

String* string_new(size_t capacity) {
	String* s = malloc(1 * sizeof(String));
	if (s == NULL) {
		return NULL;
	}
	s->chars = vecchar_construct(capacity + 1);
	if (s->chars == NULL) {
		free(s);
		return NULL;
	}
	vecchar_push_back(s->chars, '\0');
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
	return str->chars->length - 1;
}

void string_destroy(String* str) {
	if (!str) {
		return;
	}
	vecchar_destroy(str->chars);
	free(str);
}

int string_push_back(String* str, char ch) {
	size_t len = string_length(str);
	// replace null terminator
	str->chars->table[len] = ch;
	if (vecchar_push_back(str->chars, '\0') == -1) {
		str->chars->table[len] = '\0';
		return -1;
	}
	return 0;
}

int string_push_cstr(String* str, const char* c_str) {
	for (int i = 0; c_str[i] != '\0'; i++) {
		if (string_push_back(str, c_str[i]) == -1) {
			return -1;
		}
	}
	return 0;
}

char* string_cstr(String* str) {
	return str->chars->table;
}

MONOVEC_DEFINITIONS(char, VecChar, vecchar);
