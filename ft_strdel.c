//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

void ft_strdel(char **as) {
    free(*as);
    *as = NULL;
}