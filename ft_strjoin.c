//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2) {
    size_t i = 0;
    size_t j = 0;
    char *result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (result == NULL) return NULL;

    while (s1[i] != '\0') {
        result[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        result[i+j] = s2[j];
        j++;
    }
    result[i+j] = '\0';
    return result;
}