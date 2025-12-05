//
// Created by Mendoza on 12/5/2025.
//
// VLA VERSION!!!!

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (unsigned char *)src;

    unsigned char buf[n];

    size_t i = 0;

    if (d == s || n == 0) {
        return d;
    }

    while (i < n) {
        buf[i] = (unsigned char ) s[i];
        ++i;
    }
    i = 0;
    while (i < n) {
        d[i] = (unsigned char) buf[i];
        ++i;
    }

    return (void *)d;
}