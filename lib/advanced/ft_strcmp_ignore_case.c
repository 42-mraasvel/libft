#include "libft.h"

int ft_strcmp_ignore_case(const char* a, const char* b) {
	for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++) {
		int ch_a = ft_tolower((unsigned char)a[i]);
		int ch_b = ft_tolower((unsigned char)b[i]);
		if (ch_a != ch_b) {
			return ch_a - ch_b;
		}
	}
	return 0;
}
