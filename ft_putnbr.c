//
// Created by Mendoza on 1/21/2026.
//
#include "libft.h"

void ft_putnbr(int n) {
    if (n >= 0 && n <= 9) {
        n = n + '0';
        write(1, &n, 1);
    }

    //resucrsion, write in second argument need string, n = 42 => string n = bytes "42" WRONG. use while
}