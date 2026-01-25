//
// Created by Mendoza on 1/25/2026.
//
#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *)) {
    unsigned int i = 0;

    if (s == NULL) return;

    while (*s) {
        f(i, s);
        s++;
        i++;
    }
}