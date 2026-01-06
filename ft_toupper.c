#include "libft.h"

int ft_toupper(int c) {
	unsigned char letter = (unsigned char) c;
	if (letter >= 'a' && letter <= 'z') return (letter-32);
	return c;
}
