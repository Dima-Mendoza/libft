//
// Created by Mendoza on 12/11/2025.
//
#include "libft.h"

char *ft_strcat(char *s1, const char *s2) {
    unsigned char *p_s1 = (unsigned char *)s1;
    const unsigned char *p_s2 = (unsigned char *)s2;

    size_t i = 0;
    size_t dest_len = ft_strlen(s1);

    while (p_s2[i] != '\0') {
        p_s1[dest_len+i] = p_s2[i];
        ++i;
    }

    p_s1[dest_len+i] = '\0';

    return p_s1;
}