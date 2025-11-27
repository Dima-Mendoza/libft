//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void) {
    char a[10];
    char b[10];

    ft_memset(a, 'X',10);
    memset(b, 'X', 10);



    ft_bzero(a, 3);
    for (int i = 0; i < 10; i++) {
        printf("%d: %c %c\n", i, a[i], b[i]);
    }

    int res = ft_memcmp(a,b,strlen(a));
    printf("res: %d\n", res);
}