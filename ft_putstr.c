//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putstr(char const *s) {
    size_t lenght_string = ft_strlen(s);

    write(1, s, lenght_string);
}