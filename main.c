//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"


#include <stdio.h>
#include <string.h>
#include "libft.h"

static void print_buf(const char *label, const unsigned char *buf, size_t n)
{
    printf("%s: ", label);
    for (size_t i = 0; i < n; i++)
        putchar(buf[i] ? buf[i] : '.');
    putchar('\n');
}

int main(void)
{
    char a1[32] = "1234567890abcdef";
    char a2[32] = "1234567890abcdef";

    printf("=== overlap forward: memmove(x+2, x, 10) ===\n");

    memmove(a1 + 2, a1, 10);
    ft_memmove(a2 + 2, a2, 10); // твоя функция

    print_buf("memmove   ", (unsigned char*)a1, 16);
    print_buf("ft_memmove", (unsigned char*)a2, 16);

    return 0;
}






