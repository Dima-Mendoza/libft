#include "libft.h"

int ft_atoi(const char *nptr) {
	int result = 0;

	size_t i = 0;
	size_t n = 0;
	size_t tmp = 1;
	size_t razrad = ft_strlen(nptr);
	while (i < razrad) {
		n = razrad - 1 - i;
		while(n != 0) {
			tmp *= 10;
			n--;
		}

		result += nptr[i] * tmp;
		tmp = 1;
		i++;	
	}

	return result;
}
