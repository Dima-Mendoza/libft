//
// Created by Mendoza on 1/12/2026.
//
#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len) {

    size_t i = 0;
    size_t j = 0;

    if (little[0] == '\0') return &big;

    while (big[i] != '\0' && i < len) {
        while (big[i+j] == little[j] && i + j < len) {
            if (little[j+1] == '\0') {
                char *result = (char *)(big + i);
                return result;
            };
            j++;
        }
        j = 0;
        ++i;
    }

    return NULL;

}
