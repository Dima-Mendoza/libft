//
// Created by Mendoza on 1/24/2026.
//
#include "libft.h"

void *ft_memalloc(size_t size) {
    void *ptr = NULL;
    ptr = (void *)malloc(size);
    if (ptr == NULL) {return NULL;}
    ft_bzero(ptr, size);
    return ptr;
}