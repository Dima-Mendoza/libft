//
// Created by Mendoza on 1/12/2026.
//
#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len) {

    size_t i = 0;
    size_t j = 0;
    size_t start = 0;
    size_t len_little = ft_strlen(little);

    while (big[i] != '\0') {
        start = i;
        while (big[i] == little[j]) {
            if (little[j] == '\0' && j == len_little) {
                char *result = (char *)big[start];
                return result;
            };
            i++;
            j++;
        }
        j = 0;
        ++i;
    }

    return NULL;

}