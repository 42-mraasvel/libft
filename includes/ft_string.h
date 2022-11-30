#ifndef FT_STRING_H
#define FT_STRING_H

#include "monovec.h"

MONOVEC_DECLARATION(char, VecChar, vecchar);

typedef struct String {
	VecChar* chars;
} String;

String* string_format(const char* fmt, ...);
String* string_from(const char* src);
void string_destroy(String* str);
int string_push_back(String* str, char ch);
String* string_new(size_t capacity);
size_t string_length(String* str);
char* string_cstr(String* str);

#endif /* FT_STRING_H */
