//
// Created by Mendoza on 1/8/2026.
//
#include "libft.h"

int ft_isspace(int c) {
    unsigned char letter = (unsigned char)c;
    if(letter == ' ' || letter == '\n' || letter == '\t' || letter == '\f' || letter == '\r' || letter == '\v') return 1;
    return 0;
}