//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

#include <stdio.h>
#include <stddef.h>

void test(const char *big, const char *little, size_t len,
          int expect_null, size_t expect_offset)
{
    char *r = ft_strnstr(big, little, len);

    if (expect_null)
        printf(r == NULL ? "OK\n" : "FAIL\n");
    else
        printf(r == big + expect_offset ? "OK\n" : "FAIL\n");
}


int main(void)
{
    // empty little
    test("abc", "", 0, 0, 0);
    test("abc", "", 1, 0, 0);
    test("abc", "", 3, 0, 0);
    test("", "", 0, 0, 0);

    // basic found
    test("hello world", "hello", 5, 0, 0);
    test("hello world", "world", 11, 0, 6);

    // basic not found (len)
    test("hello world", "world", 6, 1, 0);
    test("hello world", "world", 7, 1, 0);

    // boundary exact fit
    test("abcdef", "def", 6, 0, 3);
    test("abcdef", "def", 5, 1, 0);

    // repeats
    test("aaaaa", "aaa", 5, 0, 0);
    test("aaaaa", "aaa", 3, 0, 0);
    test("aaaaa", "aaa", 2, 1, 0);

    // overlaps
    test("abababab", "bab", 8, 0, 1);
    test("abababab", "bab", 3, 1, 0);

    // single char
    test("abc", "a", 1, 0, 0);
    test("abc", "b", 1, 1, 0);
    test("abc", "b", 2, 0, 1);

    // not found
    test("abcdef", "xyz", 6, 1, 0);
    test("", "a", 0, 1, 0);

    return 0;
}

