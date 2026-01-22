//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

char *ft_strtrim(char const *s) {
    char *result = NULL;
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;

    while (s[i] != '\0') {
        if (!ft_isspace(s[i])) {
            len++;
        }
        i++;
    }

    result = (char*)malloc(sizeof(char) * (len + 1));
    if (result == NULL) {return (char *)s;}

    while (s[j] != '\0') {
        if (!ft_isspace(s[j]) && ft_isalnum(s[j+1])) {
            result[j] = s[j];
        }
        j++;
    }

    result[j] = '\0';
    return result;
}