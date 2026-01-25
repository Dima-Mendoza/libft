//
// Created by Mendoza on 1/25/2026.
//
#include "libft.h"

void ft_striter(char *s, void (*f)(char *)) {
    if (s == NULL) return;

    while (*s) {
        f(s);
        s++;
    }
}