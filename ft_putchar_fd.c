//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putchar_fd(char c, int fd) {
    write(fd, &c, 1);
}