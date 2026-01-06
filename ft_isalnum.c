#include "libft.h"

int ft_isalnum(int c) {
	unsigned char alnum = (unsigned char) c;

	if (alnum >= '0' && alnum <= '9') return 1;
	if (alnum >= 'A' && alnum <='Z') return 1;
	if (alnum >= 'a' && alnum <= 'z') return 1;
	return 0;
}
