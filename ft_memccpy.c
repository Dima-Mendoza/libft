//
// Created by Mendoza on 12/6/2025.
//
#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    size_t i = 0;
    while (i < n) {
        d[i] = s[i];
        if (s[i] == (unsigned char)c) {
            return (void*) (d+i+1);
        }
        ++i;
    }

    return NULL;

}