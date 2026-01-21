//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putendl(char const *s) {
    if (!s) return;

    size_t len_string = ft_strlen(s);

    write(1, s, len_string);
    write(1, "\n", 1);
}