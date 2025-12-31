//
// Created by Mendoza on 12/25/2025.
//
#include "libft.h"

size_t ft_strlcat(char *dest, const char* src, size_t size) {

	size_t i = 0;
	size_t len_dest = ft_strlen(dest);
	size_t len_src = ft_strlen(src);
	size_t size_after_minus = size -len_dest-1;

	if (size == 0) return ft_strlen(dest)+size;
	if (len_dest > size) return len_dest+1;

	while (size_after_minus > 0 && src[i] != '\0') {
		dest[len_dest + i] = src[i];
		++i;
		--size_after_minus;
	}

	dest[len_dest+i] = '\0';

	return len_src + len_dest;
}
