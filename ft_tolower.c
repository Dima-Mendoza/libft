#include "libft.h"

int ft_tolower(int c) {
	unsigned char letter = (unsigned char) c;
	if (letter >= 'A' && letter <= 'Z') return (letter + 32);
	return c;
}
