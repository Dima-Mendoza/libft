//
// Created by Mendoza on 1/25/2026.
//
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
    char *result = NULL;
    char *start = NULL;
    unsigned int i = 0;

    result = (char*) malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (result == NULL) return (NULL);
    if (s == NULL && f == NULL) {return NULL;}


    start = result;
    while (*s) {
        *result = f(i, *s);
        result++;
        s++;
        i++;
    }

    *result = '\0';
    return start;
}