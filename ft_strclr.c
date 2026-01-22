//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

void ft_strclr(char *s) {
    size_t i = 0;
    if (s == NULL) return;
    while(s[i] != '\0') {s[i] = '\0';i++;};
}