//
// Created by Mendoza on 12/15/2025.
//
#include <stdio.h>

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2) {
    unsigned char* p_s1 = (unsigned char*)s1;
    unsigned char* p_s2 = (unsigned char*)s2;

    size_t i = 0;

    while (p_s1[i] == p_s2[i] && (p_s1[i] != '\0' &&  p_s2[i] != '\0')) {
        ++i;
    }

    return p_s1[i] - p_s2[i];
}