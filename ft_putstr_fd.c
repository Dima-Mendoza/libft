//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putstr_fd(const char *s, int fd) {
    if (!s) return;
    write(fd, s, ft_strlen(s));
}