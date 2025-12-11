//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *s, int c); // прототип тестируемой функции

static void run_test(const char *s, int c, const char *name)
{
    char *std_res = strrchr(s, c);
    char *ft_res  = ft_strrchr(s, c);

    if (std_res == ft_res) {
        printf("[OK]   %s\n", name);
    } else {
        printf("[FAIL] %s\n", name);
        printf("       strrchr : %ld\n", std_res ? (long)(std_res - s) : -1L);
        printf("       ft_strrchr: %ld\n", ft_res  ? (long)(ft_res  - s) : -1L);
    }
}

int main(void)
{
    /* 1. Базовые случаи */
    run_test("hello world", 'o', "basic: 'hello world', 'o'");
    run_test("hello world", 'l', "basic: 'hello world', 'l'");
    run_test("hello world", 'h', "basic: 'hello world', 'h'");
    run_test("hello world", 'd', "basic: 'hello world', 'd'");

    /* 2. Символ отсутствует */
    run_test("hello", 'x', "no match: 'hello', 'x'");

    /* 3. Повторяющийся шаблон */
    run_test("ababa", 'a', "pattern: 'ababa', 'a'");
    run_test("ababa", 'b', "pattern: 'ababa', 'b'");

    /* 4. Поиск нуль-терминатора '\0' */
    run_test("hello", '\0', "null-char: 'hello', '\\0'");
    run_test("", '\0', "null-char: empty string, '\\0'");

    /* 5. Пустая строка и обычный символ */
    run_test("", 'a', "empty: '', 'a'");

    /* 6. Нестандартные байты */
    {
        const char buf[] = { 1, 2, (char)0xFF, 2, 0 };
        run_test(buf, 0xFF, "bytes: {1,2,0xFF,2,0}, 0xFF");
        run_test(buf, 2,    "bytes: {1,2,0xFF,2,0}, 2");
    }

    /* 7. Значение c > 255 */
    run_test("A", 'A' + 256, "c > 255: 'A', 'A'+256");

    /* 8. Повторяющиеся символы в начале и конце */
    run_test("xxx123x", 'x', "edges: 'xxx123x', 'x'");

    return 0;
}













