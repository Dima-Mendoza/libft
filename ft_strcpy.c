//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

char *ft_strcpy(char *dst, const char *src) {
    unsigned char *p_dst = (unsigned char *)dst;
    const unsigned char *p_src = (const unsigned char *)src;

    size_t i = 0;
    while (src[i] != '\0') {
        p_dst[i] = src[i];
        i++;
    }

    p_dst[i] = '\0';

    return (void *)p_dst;
}