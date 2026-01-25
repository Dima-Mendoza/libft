//
// Created by Mendoza on 1/25/2026.
//
#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char)) {
    char *result = NULL;
    char *start = NULL;

    result = (char*) malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (result == NULL) return (NULL);
    if (s == NULL && f == NULL) {return NULL;}


    start = result;
    while (*s) {
        *result = f(*s);
        result++;
        s++;
    }

    *result = '\0';
    return start;
}