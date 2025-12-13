//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

/* tests_ft_strstr.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strstr(const char *haystack, const char *needle);

static int g_ok = 0;
static int g_fail = 0;

static void check_ptr(const char *name, const char *h, const char *n)
{
    char *exp = strstr(h, n);
    char *got = ft_strstr(h, n);

    if (exp == got)
    {
        printf("[OK]   %s\n", name);
        g_ok++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        printf("  haystack: \"%s\"\n", h);
        printf("  needle:   \"%s\"\n", n);
        printf("  expected: %p", (void *)exp);
        if (exp) printf(" (\"%s\")", exp);
        printf("\n");
        printf("  got:      %p", (void *)got);
        if (got) printf(" (\"%s\")", got);
        printf("\n");
        g_fail++;
    }
}

static void check_offset(const char *name, const char *h, const char *n, ptrdiff_t off)
{
    char *got = ft_strstr(h, n);
    char *exp = (off < 0) ? NULL : (char *)h + off;

    if (got == exp)
    {
        printf("[OK]   %s\n", name);
        g_ok++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        printf("  haystack: \"%s\"\n", h);
        printf("  needle:   \"%s\"\n", n);
        printf("  expected: %p", (void *)exp);
        if (exp) printf(" (offset %td)", off);
        printf("\n");
        printf("  got:      %p", (void *)got);
        if (got) printf(" (offset %td)", got - (char *)h);
        printf("\n");
        g_fail++;
    }
}

int main(void)
{

    /* add these to main() */

check_ptr("poison: mississippi/issi",        "mississippi", "issi");
check_ptr("poison: mississippi/issip",       "mississippi", "issip");
check_ptr("poison: mississippi/sippi",       "mississippi", "sippi");
check_ptr("poison: mississippi/pi",          "mississippi", "pi");
check_ptr("poison: mississippi/mississippi", "mississippi", "mississippi");
check_ptr("poison: mississippi/mississippia","mississippi", "mississippia");

check_ptr("poison: aaaaa/aaa",   "aaaaa", "aaa");
check_ptr("poison: aaaaa/aaaa",  "aaaaa", "aaaa");
check_ptr("poison: aaaaa/aaaaa", "aaaaa", "aaaaa");
check_ptr("poison: aaaaa/aaaaaa","aaaaa", "aaaaaa");
check_ptr("poison: aaaaa/ba",    "aaaaa", "ba");

check_ptr("poison: ababa/baba",  "ababa", "baba");
check_ptr("poison: ababa/aba",   "ababa", "aba");
check_ptr("poison: ababa/abab",  "ababa", "abab");
check_ptr("poison: ababa/ababa", "ababa", "ababa");
check_ptr("poison: abababa/babab", "abababa", "babab");

check_ptr("poison: prefix clash 1", "aaaaab", "aaab");
check_ptr("poison: prefix clash 2", "aaaabaaab", "aaab");
check_ptr("poison: prefix clash 3", "aaacaab", "aab");
check_ptr("poison: prefix clash 4", "abcxabcdabxabcdabcdabcy", "abcdabcy");

check_ptr("poison: ends with needle",   "abcxxx", "xxx");
check_ptr("poison: near-end partial",   "abcxx",  "xxx");
check_ptr("poison: needle at last char","abc", "c");
check_ptr("poison: needle after null?", "abc", ""); /* should be haystack */

check_ptr("poison: spaces 1", "    ", "   ");
check_ptr("poison: spaces 2", " a  a   a", "a   a");
check_ptr("poison: tabs/newlines", "a\tb\nc\rd", "\tb\nc");

check_ptr("poison: punctuation 1", "--==--==--", "==--==");
check_ptr("poison: punctuation 2", "[]{}()<>", "{}()");

check_ptr("poison: digits 1", "000001000010000", "100001");
check_ptr("poison: digits 2", "123451234512345", "51234");

check_ptr("poison: long-ish repeat", "abababababababababab", "ababababab");
check_ptr("poison: long-ish miss",   "abababababababababab", "abababababaX");

check_ptr("poison: single-char haystack hit",  "a", "a");
check_ptr("poison: single-char haystack miss", "a", "b");
check_ptr("poison: empty haystack",            "", "a");
check_ptr("poison: both empty",                "", "");

check_ptr("poison: case-sensitive", "AaAaA", "aAa"); /* should NOT ignore case */

/* if you want a stress case without malloc */
check_ptr("poison: big homogenous",
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
          "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");


    check_ptr("poison: mississippi/issi", "mississippi", "issi");
    check_ptr("poison: aaaaa/aaa", "aaaaa", "aaa");
    check_ptr("poison: ababa/baba", "ababa", "baba");
    check_ptr("poison: ends with needle", "abcxxx", "xxx");
    check_ptr("poison: not found repeated", "aaaaa", "aaaaaa");

    check_ptr("test - warranty", "aaab", "aab");
    /* базовые */
    check_ptr("basic: found at start",  "hello world", "hello");
    check_ptr("basic: found in middle", "hello world", "world");
    check_ptr("basic: not found",       "hello world", "planet");
    check_ptr("basic: full match",      "abc", "abc");
    check_ptr("basic: single char hit", "abc", "b");
    check_ptr("basic: single char miss","abc", "x");

    /* needle длиннее haystack */
    check_ptr("needle longer", "ab", "abc");

    /* пустые строки */
    check_ptr("empty needle", "abc", "");
    check_ptr("empty haystack", "", "a");
    check_ptr("both empty", "", "");

    /* повторяющиеся паттерны */
    check_ptr("repeated: first occurrence", "aaaaa", "aa");
    check_ptr("repeated: overlap",          "abababab", "abab");
    check_ptr("repeated: late occurrence",  "zzzzabc", "abc");

    /* символы и пробелы */
    check_ptr("spaces", "a b  c   d", "  c");
    check_ptr("punct",  "hi, there!", ", th");
    check_ptr("digits", "id=12345;ok", "123");

    /* совпадение ближе к концу */
    check_ptr("near end", "xxxxxy", "y");
    check_ptr("end substring", "abcde", "de");

    /* точная проверка смещения (для наглядности) */
    check_offset("offset: 'world' at 6", "hello world", "world", 6);
    check_offset("offset: miss => NULL", "hello world", "zzz", -1);

    printf("\nResult: OK=%d FAIL=%d\n", g_ok, g_fail);
    return (g_fail == 0) ? 0 : 1;
}















