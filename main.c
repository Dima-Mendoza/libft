//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

// test_ft_strlcat.c
// Компилируй вместе с libft: gcc -Wall -Wextra -Werror test_ft_strlcat.c libft.a -I. -o test
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "libft.h"

// test_ft_atoi.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>



#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <stddef.h>

void test(const char *big, const char *little, size_t len, int expect_null, size_t expect_offset)
{
    char *res = ft_strnstr(big, little, len);

    if (expect_null)
        printf("%s\n", res == NULL ? "OK" : "FAIL");
    else
        printf("%s\n", (res && res == big + expect_offset) ? "OK" : "FAIL");
}

int main(void)
{
    test("hello world", "world", 11, 0, 6);
    test("hello world", "world", 7, 1, 0);
    test("hello world", "hello", 5, 0, 0);
    test("hello world", "hello", 4, 1, 0);
    test("hello world", "", 11, 0, 0);
    test("", "", 0, 0, 0);
    test("", "a", 0, 1, 0);
    test("aaaaa", "aaa", 5, 0, 0);
    test("aaaaa", "aaa", 3, 0, 0);
    test("abcabcabc", "abc", 9, 0, 0);
    test("abcabcabc", "cab", 9, 0, 2);
    test("abcabcabc", "abc", 2, 1, 0);
    test("abcdef", "def", 6, 0, 3);
    test("abcdef", "def", 5, 1, 0);
    test("abcdef", "xyz", 6, 1, 0);
    return 0;
}





