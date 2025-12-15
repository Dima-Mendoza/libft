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

int ft_strncmp(const char *s1, const char *s2, size_t n);

static int norm(int x) { return (x > 0) - (x < 0); }

#define RUN_TEST(name, s1, s2, n) do {                                  \
    int got = ft_strncmp((s1), (s2), (n));                               \
    int ref = strncmp((s1), (s2), (n));                                  \
    if (norm(got) != norm(ref)) {                                       \
        printf("FAIL: %-28s | n=%zu | got=%d (norm=%d) ref=%d (norm=%d)\n", \
               (name), (size_t)(n), got, norm(got), ref, norm(ref));    \
        return 1;                                                       \
    } else {                                                            \
        printf("OK  : %-28s | n=%zu\n", (name), (size_t)(n));            \
    }                                                                   \
} while (0)

int main(void)
{
    // basic equality
    RUN_TEST("equal_full", "hello", "hello", 10);
    RUN_TEST("equal_n_short", "hello", "hello", 3);

    // n == 0
    RUN_TEST("n_zero_equal", "abc", "abc", 0);
    RUN_TEST("n_zero_diff", "abc", "xyz", 0);

    // first char differs
    RUN_TEST("diff_first_char", "abc", "xbc", 5);
    RUN_TEST("diff_first_char_n1", "abc", "xbc", 1);

    // difference inside n
    RUN_TEST("diff_middle", "abCdef", "abDdef", 6);

    // difference after n (should be equal for first n chars)
    RUN_TEST("diff_after_n", "abcdef", "abcXef", 3);
    RUN_TEST("diff_after_n2", "abcdef", "abcXef", 4);

    // prefix / shorter string cases (use padded arrays to stay safe)
    {
        char a[16] = "abc";
        char b[16] = "abcd";
        RUN_TEST("prefix_shorter_n3", a, b, 3);
        RUN_TEST("prefix_shorter_n4", a, b, 4);
        RUN_TEST("prefix_shorter_n10", a, b, 10);
    }
    {
        char a[16] = "abcd";
        char b[16] = "abc";
        RUN_TEST("prefix_longer_n3", a, b, 3);
        RUN_TEST("prefix_longer_n4", a, b, 4);
        RUN_TEST("prefix_longer_n10", a, b, 10);
    }

    // empty strings
    RUN_TEST("empty_empty", "", "", 5);
    RUN_TEST("empty_vs_text", "", "a", 5);
    RUN_TEST("text_vs_empty", "a", "", 5);

    // stops on '\0' inside the buffer
    {
        char a[8] = {'a','b','\0','c','\0','X','Y','Z'};
        char b[8] = {'a','b','\0','d','\0','X','Y','Z'};
        RUN_TEST("embedded_nul_equal", a, b, 4);
    }
    {
        char a[8] = {'a','\0','c','\0','X','Y','Z','W'};
        char b[8] = {'a','b','c','\0','X','Y','Z','W'};
        RUN_TEST("embedded_nul_diff", a, b, 3);
    }

    // signed/unsigned char behavior checks
    {
        char a[4] = {(char)0xFF, 'a', '\0', 0};
        char b[4] = {(char)0x7F, 'a', '\0', 0};
        RUN_TEST("high_bit_bytes_n1", a, b, 1);
    }
    {
        char a[4] = {(char)0x80, '\0', 0, 0};
        char b[4] = {(char)0x00, '\0', 0, 0};
        RUN_TEST("high_bit_vs_zero", a, b, 1);
    }

    // large n with padding
    {
        char a[32] = "sameprefix";
        char b[32] = "sameprefix";
        a[10] = 'A';
        b[10] = 'B';
        RUN_TEST("large_n_padded", a, b, 20);
    }

    printf("All tests passed (sign-compatible with strncmp).\n");
    return 0;
}



















