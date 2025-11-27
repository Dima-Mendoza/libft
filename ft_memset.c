//
// Created by Mendoza on 11/24/2025.
//

#include "libft.h"

void *ft_memset(void *s, int c, size_t n) {
// переменная которой все заполняем
// приводим тип s к байтам
// с помощью цикла переписываем область памяти до n
// возврашаем эту область памяти

unsigned char *p;
p = (unsigned char *)s;

size_t i = 0;

while (i < n) {
    p[i] = (unsigned char)c;
    i++;
}

return (s);
};