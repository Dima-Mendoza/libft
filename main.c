//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"

//////////////////////////

#include <assert.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void) {
    /* empty / empty */
    assert(ft_strcmp("", "") == 0);

    /* empty vs non-empty */
    assert(ft_strcmp("", "a") < 0);
    assert(ft_strcmp("a", "") > 0);

    /* single-char vs single-char */
    assert(ft_strcmp("a", "a") == 0);
    assert(ft_strcmp("a", "b") < 0);
    assert(ft_strcmp("b", "a") > 0);

    /* single-char vs longer */
    assert(ft_strcmp("a", "aa") < 0);
    assert(ft_strcmp("a", "ab") < 0);
    assert(ft_strcmp("b", "aa") > 0);
    assert(ft_strcmp("b", "ba") < 0);
    assert(ft_strcmp("z", "a0") > 0);
    assert(ft_strcmp("0", "00") < 0);

    /* longer vs single-char */
    assert(ft_strcmp("aa", "a") > 0);
    assert(ft_strcmp("ab", "a") > 0);
    assert(ft_strcmp("aa", "b") < 0);
    assert(ft_strcmp("ba", "b") > 0);
    assert(ft_strcmp("a0", "z") < 0);
    assert(ft_strcmp("00", "0") > 0);

    /* same length, identical */
    assert(ft_strcmp("ab", "ab") == 0);
    assert(ft_strcmp("hello", "hello") == 0);

    /* same length, differ at last char */
    assert(ft_strcmp("ab", "aa") > 0);
    assert(ft_strcmp("aa", "ab") < 0);
    assert(ft_strcmp("hellp", "hello") > 0);
    assert(ft_strcmp("hello", "hellp") < 0);

    /* same length, differ at first char */
    assert(ft_strcmp("xbc", "abc") > 0);
    assert(ft_strcmp("abc", "xbc") < 0);

    /* different lengths */
    assert(ft_strcmp("test", "tests") < 0);
    assert(ft_strcmp("tests", "test") > 0);
    assert(ft_strcmp("a", "bbb") < 0);
    assert(ft_strcmp("bbb", "a") > 0);
    assert(ft_strcmp("ab", "c") < 0);
    assert(ft_strcmp("c", "ab") > 0);

    /* non-alphabetic */
    assert(ft_strcmp("123", "123") == 0);
    assert(ft_strcmp("123", "124") < 0);
    assert(ft_strcmp("!@#", "!@#") == 0);
    assert(ft_strcmp("!@#", "!@+") < 0);

    return 0;
}

















