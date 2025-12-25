//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Буфер размером 10 байт */
    char buf[10] = "abc";          //   "abc\0"
    const char *more = "defghijkl";

    /* Сколько символов было бы добавлено, если бы в буфере не ограничение? */
    size_t appended = strlcat(buf, more, sizeof buf);

    /*  →  "abcdefg" + завершающий ноль (общее число символов = 9) */
    printf("Итоговая строка: \"%s\"\n", buf);
    printf("Добавлено %zu символов. Оставшийся размер в буфере = %zu\n",
           appended, sizeof(buf) - 1);

    return 0;
}























