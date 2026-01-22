//
// Created by Mendoza on 1/22/2026.
//
#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len) {
    size_t i = 0;
    size_t j = 0;
    char *result = (char *) malloc(sizeof (char) * (len + 1));
    if (!result) return NULL;

    while (i < len && s[i] != '\0') {
        if (i == start) {
            result[j] = s[start+j];
        }
        i++;
        j++;
    }
    if (j == len) {return result;}
    return NULL;
}