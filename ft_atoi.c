#include "libft.h"

int ft_atoi(const char *nptr) {
	int result = 0;

	size_t i = 0;
	int isNegative = 0;

	while (ft_isspace(nptr[i])) {i++;}
	if (nptr[i] == '-' || nptr[i] == '+') {
		if (nptr[i] == '-') isNegative = 1;
		i++;
	}
	while (ft_isdigit(nptr[i])) {
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	if (isNegative) return -result;
	return result;


}
