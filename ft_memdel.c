//
// Created by Mendoza on 1/24/2026.
//
#include "libft.h"
void ft_memdel(void **ap) {
    if (!ap) return;

    free(*ap);

    *ap = NULL;
}