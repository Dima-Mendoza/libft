//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

char *ft_strrchr(const char *s, int c) {
    unsigned char *p_s = (unsigned char *)s;
    unsigned char p_c = (unsigned char )c;

    size_t i = ft_strlen(s);

    while (p_s[i] != p_c && i > 0) {
        --i;
    }
    if (p_s[i] == p_c) {
        return (char *)p_s+i;
    }
    return NULL;
}