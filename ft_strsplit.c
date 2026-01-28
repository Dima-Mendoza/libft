//
// Created by Mendoza on 1/24/2026.
//
#include "libft.h"

char **ft_strsplit(char const *s, char c) {
    char **result = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
    if (result == NULL) return NULL;
    size_t i = 0, j = 0,k = 0, start_index = 0;

    while (s[i] != '\0') {
        if (s[i] == c && j == 0) {start_index = i; j = 1;continue;}
        if (s[i] == c && j == 1) {
            ft_strcpy(result[k], s + start_index);
            k++;
            j = 0;
            continue;
        }
        i++;
    }

    return result;
}
