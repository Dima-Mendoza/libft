//
// Created by Mendoza on 12/14/2025.
//
#include "libft.h"

char *ft_strstr(const char* haystack, const char* needle) {
    const char *p_haystack = haystack;
    const char *p_needle = needle;

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t len_needle = ft_strlen(needle);
    if (*p_needle == '\0') return (char *)p_haystack;
    while (p_haystack[i] != '\0' && *p_needle != '\0') {
        if (p_haystack[i] == p_needle[j]) {
            k = i;
            while (j < len_needle && p_haystack[i] == p_needle[j]) {
                ++i;
                ++j;
            }
            if (j == len_needle) {
                return (char *)p_haystack + k;
            }
            j = 0;
            i = k;
        }
        j = 0;

        ++i;
    }

    return NULL;
}