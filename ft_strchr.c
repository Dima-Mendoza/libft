//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

char *ft_strchr(const char *s, int c) {
    unsigned char *p_s = (unsigned char *)s;
    unsigned char p_c = (unsigned char )c;

    size_t i = 0;
    while (p_s[i] != p_c && p_s[i] != '\0') {
        ++i;
    }
    if (p_s[i] == p_c) {
        return (char *)p_s + i;
    }

    return NULL;

}