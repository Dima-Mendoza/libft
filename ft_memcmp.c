//
// Created by Mendoza on 11/27/2025.
//

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *p1 = (unsigned char *)s1;
    unsigned char *p2 = (unsigned char *)s2;

    size_t i = 0;

    int result = 0;

    while (i < n) {
        if (p1[i] != p2[i]) {
            result = p1[i] - p2[i];
            break;
        }
        i++;
    }

    return result;
}