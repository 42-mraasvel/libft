#include "libft.h"
#include <stdbool.h>

// true if str starts with s
bool ft_starts_with(const char* str, const char* s) {
	return ft_strncmp(str, s, ft_strlen(s)) == 0;
}
