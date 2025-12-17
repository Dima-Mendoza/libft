//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

// test_ft_strncmp.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include <stdio.h>
#include <string.h>



// test_ft_strncat_vs_strncat.c
// Компиляция: cc -Wall -Wextra -Werror test_ft_strncat_vs_strncat.c && ./a.out

#include <stdio.h>
#include <string.h>
#include <stddef.h>

char *ft_strncat(char *dst, const char *src, size_t ssize);

static int run_case(const char *name,
                    const char *dst_init,
                    const char *src,
                    size_t ssize)
{
    char a[128];
    char b[128];

    memset(a, 'X', sizeof(a));
    memset(b, 'X', sizeof(b));
    a[sizeof(a)-1] = '\0';
    b[sizeof(b)-1] = '\0';
    strncpy(a, dst_init, sizeof(a)-1);
    strncpy(b, dst_init, sizeof(b)-1);


    ft_strncat(a, src, ssize);
    strncat(b, src, ssize);

    if (memcmp(a, b, sizeof(a)) != 0) {
        printf("[FAIL] %s\n", name);
        printf("  dst_init=\"%s\"\n", dst_init);
        printf("  src     =\"%s\"\n", src);
        printf("  ssize   =%zu\n", ssize);
        printf("  ft      =\"%s\"\n", a);
        printf("  libc    =\"%s\"\n", b);
        return 1;
    }

    printf("[OK]   %s\n", name);
    return 0;
}

int main(void)
{
    int fails = 0;

    // базовые
    fails += run_case("empty + abc, ssize=0",   "",      "abc", 0);
    fails += run_case("empty + abc, ssize=1",   "",      "abc", 1);
    fails += run_case("empty + abc, ssize=2",   "",      "abc", 2);
    fails += run_case("empty + abc, ssize=3",   "",      "abc", 3);
    fails += run_case("empty + abc, ssize=10",  "",      "abc", 10);

    fails += run_case("hi + 42, ssize=0",       "hi",    "42",  0);
    fails += run_case("hi + 42, ssize=1",       "hi",    "42",  1);
    fails += run_case("hi + 42, ssize=2",       "hi",    "42",  2);
    fails += run_case("hi + 42, ssize=10",      "hi",    "42",  10);

    // пробелы/пунктуация
    fails += run_case("a b +  c, ssize=4",      "a b",   " c",  4);
    fails += run_case("path + /file, ssize=8",  "/usr",  "/bin", 8);

    // длинный src, разные ssize
    fails += run_case("x + long, ssize=1",      "x",     "0123456789", 1);
    fails += run_case("x + long, ssize=5",      "x",     "0123456789", 5);
    fails += run_case("x + long, ssize=20",     "x",     "0123456789", 20);

    // dst уже длинный
    fails += run_case("long dst + z, ssize=1",  "0123456789012345", "z", 1);
    fails += run_case("long dst + z, ssize=8",  "0123456789012345", "z", 8);
    fails += run_case("long dst + z, ssize=32", "0123456789012345", "z", 32);

    // src пустая
    fails += run_case("dst + empty src, ssize=8", "hello", "", 8);

    fails += run_case("no null terminator", "hi", "42", 2);
    fails += run_case(
    "no null-terminator when src >= ssize",
    "hi",
    "42",
    2
);
    if (fails == 0) {
        printf("ALL TESTS PASSED\n");
        return 0;
    } else {
        printf("FAILED CASES: %d\n", fails);
        return 1;
    }
}





















