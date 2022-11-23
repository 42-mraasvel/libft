#ifndef MONOVEC_H
#define MONOVEC_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_max(int a, int b);

/**
 * Generic monomorphic vector for C usage
 * MONOVEC_DECLARATION(int, VecInt, veci);
 * MONOVEC_DEFINITIONS(int, VecInt, veci);
 * 
 * Declarations are just prototypes
 * -- Result
 * struct VecInt { ... }
 * veci_construct( ... );
 * veci_destroy( ... );
 */

#define MONOVEC_DECLARATION(Type, Name, FunctionPrefix) \
typedef struct Name { \
	size_t length; \
	size_t capacity; \
	Type* table; \
} Name; \
\
Name* FunctionPrefix##_construct(size_t capacity); \
int FunctionPrefix##_push_back(Name* ptr, Type value); \
void FunctionPrefix##_destroy(Name* ptr); \
Type* FunctionPrefix##_get(Name* ptr, size_t index);

#define MONOVEC_DEFINITIONS(Type, Name, FunctionPrefix) \
Name* FunctionPrefix##_construct(size_t capacity) { \
	Name* x = (Name*)malloc(1 * sizeof(Name)); \
	if (!x) { \
		return NULL; \
	} \
	x->length = 0; \
	x->capacity = capacity; \
	x->table = NULL; \
	if (capacity > 0) { \
		x->table = (Type*)malloc(capacity * sizeof(Type)); \
		if (!x->table) { \
			free(x); \
			return NULL; \
		} \
	} \
	return x; \
} \
\
static int FunctionPrefix##_resize(Name* ptr) { \
	ptr->capacity = ft_max(ptr->capacity * 2, 1); \
	Type* table = (Type*)malloc(ptr->capacity * sizeof(Type)); \
	if (!table) { \
		return -1; \
	} \
	ft_memcpy(table, ptr->table, ptr->length * sizeof(Type)); \
	free(ptr->table); \
	ptr->table = table; \
	return 0; \
} \
\
int FunctionPrefix##_push_back(Name* ptr, Type value) { \
	if (ptr->capacity == ptr->length) { \
		if (FunctionPrefix##_resize(ptr) == -1) { \
			return -1; \
		} \
	} \
	ptr->table[ptr->length++] = value; \
	return 0; \
} \
\
Type* FunctionPrefix##_get(Name* ptr, size_t index) { \
	assert(index < ptr->length); \
	return &ptr->table[index]; \
} \
\
void FunctionPrefix##_destroy(Name* ptr) { \
	if (!ptr) { \
		return; \
	} \
	free(ptr->table); \
	free(ptr); \
}

#endif /* MONOVEC_H */
