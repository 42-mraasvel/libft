#ifndef MONOQUICKSORT_H
#define MONOQUICKSORT_H

/*
Type parameterized quicksort array
Function name will be `${TYPE}_quicksort_by();`
->
QUICKSORT_DEFINITION(int)
->
void int_quicksort_by(int* start, int* end, int (*compare)(const int*, const int*));

Comparison function: int compare(const Type* a, const Type* b);
Move/swap function: void Swap(Type* a, Type* b);
- ZERO on a == b
- POSITIVE INT on a > b
- NEGATIVE INT on a < b
*/

#define MONO_QUICKSORT_DEFINITION(Type, UniqueFunctionPrefix) \
void _##UniqueFunctionPrefix##_do_swap(Type* x, Type* y) { \
	Type temp = *x; \
	*x = *y; \
	*y = temp; \
} \
\
Type* _##UniqueFunctionPrefix##_partition(Type* start, Type* end, int (*compare)(Type*, Type*)) { \
	Type* pivot_position = start; \
	Type* pivot = start; \
	start += 1; \
	while (start != end) { \
		if (compare(start, pivot) < 0) { \
			pivot_position++; \
			/* swap(start, pivot_position) */ \
			_##UniqueFunctionPrefix##_do_swap(start, pivot_position); \
		} \
		start++; \
	} \
	_##UniqueFunctionPrefix##_do_swap(pivot, pivot_position); \
	return pivot_position; \
} \
\
void UniqueFunctionPrefix##_quicksort_by(Type* start, Type* end, int (*compare)(Type*, Type*)) { \
	if (end - start <= 1) { \
		return; \
	} \
	Type* pivot = _##UniqueFunctionPrefix##_partition(start, end, compare); \
	UniqueFunctionPrefix##_quicksort_by(start, pivot, compare); \
	UniqueFunctionPrefix##_quicksort_by(pivot + 1, end, compare); \
}

#endif /* MONOQUICKSORT_H */
