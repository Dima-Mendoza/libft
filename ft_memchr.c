//
// Created by Mendoza on 12/6/2025.
//
#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)s;

    size_t i = 0;

    while (i < n) {
        if (p[i] == (unsigned char)c) {
            return (void *)p + i;
        }
        ++i;
    }
    return NULL;
}