//
// Created by Mendoza on 12/17/2025.
//
#include "libft.h"

char *ft_strncat(char *dst, const char *src, size_t ssize) {
    char *p_dst = dst;
    const char *p_src = src;

    size_t i = 0;
    size_t null_terminated = 0;


    while (p_dst[i] != '\0') {
        ++i;
    }

    null_terminated = i;
    i = 0;
    while (i < ssize) {
        if (p_src[i] == '\0') {
            break;
        }
        p_dst[null_terminated] = p_src[i];
        ++i;
        ++null_terminated;
    }

    p_dst[null_terminated] = '\0';
    return p_dst;
}

#if 0
while (i < ssize) {
    if (p_src[i] == '\0') return p_dst;
    if (p_dst[i] == '\0') {is_end = 1; null_terminated = i;}
    if (is_end) {
        p_dst[i] = p_src[null_terminated];
    }
    ++i;
    ++null_terminated;
}
#endif