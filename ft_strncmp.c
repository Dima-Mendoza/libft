//
// Created by Mendoza on 12/16/2025.
//
#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    const unsigned char *p_s1 = (const unsigned char *)s1;
    const unsigned char *p_s2 = (const unsigned char *)s2;

    size_t i = 0;

    while (i < n && p_s1[i] == p_s2[i] && (p_s1[i] != '\0' &&  p_s2[i] != '\0')) {
        i++;
    }

    if (n == i) return 0;

    return p_s1[i] - p_s2[i];
}