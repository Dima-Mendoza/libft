//
// Created by Mendoza on 12/11/2025.
//
#include <stdlib.h>

#include "libft.h"

char *ft_strdup(const char *s) {
    char *result = malloc(ft_strlen(s) + 1);

    if (result == NULL) return NULL;

    return ft_strcpy(result, s);

}