//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

char *ft_strncpy(char *s1, const char *s2, size_t n) {
    unsigned char *p_s1 = (unsigned char *)s1;
    const unsigned char *p_s2 = (unsigned char *)s2;

    size_t i = 0;

    while (i < n) {
        if (p_s2[i] == '\0') {
            while (i < n) {
                p_s1[i] = 0;
                ++i;
            }
            break;
        }
        p_s1[i] = p_s2[i];
        ++i;
    }

    return p_s1;
}