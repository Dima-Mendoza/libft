//
// Created by Mendoza on 12/6/2025.
//
#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (const unsigned char *) src;

    size_t i = 0;

    while (i < n) {
        d[i]=s[i];
        ++i;
    }
    return (void *)d;
}