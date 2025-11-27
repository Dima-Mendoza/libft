//
// Created by Mendoza on 11/24/2025.
//

#include "libft.h"

void *ft_memset(void *s, int value, size_t n) {
    char *val = (char *) s;
    size_t i = 0;

    while (i < n) {
        val[i] = (char)value;
        i++;
    }

    return s;
}