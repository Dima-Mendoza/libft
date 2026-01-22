//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

char *ft_strnew(size_t size) {
    char *ptr = malloc(size + 1);
    if (ptr == NULL) {return NULL;}
    ptr[size] = '\0';
    while (size--) {ptr[size]='\0';};
    return ptr;
}