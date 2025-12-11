//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

#include <stdio.h>
#include <string.h>

// прототип тестируемой функции
size_t ft_strlen(const char *s);

// макрос проверки
#define TEST(name, expr) \
do { \
if (expr) \
printf("[OK]   %s\n", name); \
else \
printf("[FAIL] %s\n", name); \
} while (0)

int main(void) {
    TEST("basic", ft_strlen("Hello") == strlen("Hello"));
    TEST("empty", ft_strlen("") == strlen(""));
    TEST("spaces", ft_strlen("   ") == strlen("   "));
    TEST("long", ft_strlen("abcdefghijklmnopqrstuvwxyz") == strlen("abcdefghijklmnopqrstuvwxyz"));
    TEST("escaped", ft_strlen("A\nB\tC") == strlen("A\nB\tC"));
    TEST("single char", ft_strlen("X") == strlen("X"));

    const char bytes[] = { 'A', (char)0xFF, 'B', '\0' };
    TEST("raw bytes", ft_strlen(bytes) == strlen(bytes));

    return 0;
}










