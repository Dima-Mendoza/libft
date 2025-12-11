//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

size_t ft_strlen(const char *s) {
    const unsigned char *p = (const unsigned char *)s;
    size_t len = 0;

    while (p[len] != '\0') len++;

    return len;
}