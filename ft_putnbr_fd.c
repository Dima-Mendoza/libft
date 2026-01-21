//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putnbr_fd(int n, int fd) {
    if (n == -2147483648) {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        n = n * -1;
        write(fd, "-", 1);
    }
    char c;

    if (n >= 10) {
        ft_putnbr_fd(n / 10, fd);
    }

    c = (n % 10) + '0';
    write(fd, &c, 1);
}