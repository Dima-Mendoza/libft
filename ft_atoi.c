#include "libft.h"

int ft_atoi(const char *nptr) {
	int result = 0;

	size_t i = 0;
	size_t n = 0;
	size_t tmp = 1;
	int isNegative = 0;

	//Delete trash
	if (nptr[0] == '\0') {return 0;}
	while (!ft_isdigit(nptr[i]) && nptr[i] != '\0') {
		i++;
		if (nptr[0] == '-' || nptr[i] == '-') {isNegative = 1;}
	}

	size_t razrad = ft_strlen(nptr);


	int k = 0;
	while (nptr[k] != '\0') {
		if (!ft_isdigit(nptr[k]) && k >= i) {break;}
		k++;
	}
	int end = k;
	int len = end - i;

	while (i < razrad && nptr[i] != '\0') {

		n = len; //-i-1
		while(n != 0) {
			tmp *= 10;
			n--;
		}


		//ASCII to int
		size_t byte_ascii = nptr[i] - '0';
		if (byte_ascii > 9) {break;};
		result += byte_ascii * tmp;
		byte_ascii = 0;
		tmp = 1;
		i++;
	}


	if (isNegative) result *= -1;
	return result;
}
