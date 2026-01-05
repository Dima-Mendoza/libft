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



int ft_atoi(const char *nptr) {
    int result = 0;

    size_t i = 0;
    size_t n = 0;
    size_t tmp = 1;
    int isNegative = 0;

    //Delete trash
    if (nptr[0] == '\0') {return 0;}
    while (!ft_isdigit(nptr[i]) && nptr[i] != '\0') {
        i++;
        if (nptr[0] == '-' || nptr[i] == '-') {isNegative = 1;}
    }

    size_t razrad = ft_strlen(nptr);



    while (i < razrad && nptr[i] != '\0') {

        n = razrad - i - 1;
        while(n != 0) {
            tmp *= 10;
            n--;
        }


        //ASCII to int
        size_t byte_ascii = nptr[i] - '0';
        if (byte_ascii > 9) {break;};
        result += byte_ascii * tmp;
        byte_ascii = 0;
        tmp = 1;
        i++;
    }


    if (isNegative) result *= -1;
    return result;
}


/*
 * "Оракул" для ожидаемого поведения: как atoi/strtol.
 * - пропускает пробелы
 * - учитывает знак
 * - читает цифры до первой нецифры
 * - если цифр нет -> 0
 * - overflow/underflow мы тут НЕ обрабатываем как стандарт (strtol может clamp-ить),
 *   поэтому overflow-тесты лучше не использовать как строгие.
 */
static int ref_atoi_like(const char *s) {
    // Используем strtol: он корректно обрабатывает пробелы/знак/остановку на нецифре
    // Но переполнение для int нужно отдельно учитывать — здесь просто приводим.
    char *end = NULL;
    long v = strtol(s, &end, 10);

    // Если не было ни одной цифры, strtol вернёт 0 и end == s (после пробелов/знака)
    // Это соответствует atoi-подобному ожиданию.
    return (int)v;
}

static int g_total = 0;
static int g_pass  = 0;

static void run_case(const char *name, const char *input, int expected) {
    g_total++;
    int got = ft_atoi(input);
    if (got == expected) {
        g_pass++;
        printf("[PASS] %-28s input=\"%s\" -> %d\n", name, input, got);
    } else {
        printf("[FAIL] %-28s input=\"%s\" -> got %d, expected %d\n",
               name, input, got, expected);
    }
}

static void run_case_ref(const char *name, const char *input) {
    int expected = ref_atoi_like(input);
    run_case(name, input, expected);
}

int main(void) {
    puts("=== Basic digit-only cases (must pass for correct implementation) ===");
    run_case_ref("zero", "0");
    run_case_ref("single digit", "7");
    run_case_ref("two digits", "42");
    run_case_ref("leading zeros", "007");
    run_case_ref("three digits", "123");
    run_case_ref("ten", "10");
    run_case_ref("ninety-nine", "99");
    run_case_ref("hundred", "100");


    puts("\n=== Standard atoi behavior cases (whitespace/sign/stop at non-digit) ===");
    run_case_ref("leading spaces", "   42");
    run_case_ref("plus sign", "+42");
    run_case_ref("minus sign", "-42");
    run_case_ref("spaces and minus", " \t\n-15");

    run_case_ref("stop at letter", "123abc");
    run_case_ref("stop after sign", "-12xyz");
    run_case_ref("no digits", "abc");
    run_case_ref("only sign", "+");
    run_case_ref("empty string", "");

    puts("\n=== Boundary-ish (no overflow here for int) ===");
    run_case_ref("INT_MAX exact", "2147483647");
    run_case_ref("INT_MIN exact", "-2147483648");

    /*
    puts("\n=== Overflow (undefined for atoi; enable only if you want to observe behavior) ===");
    run_case_ref("overflow +", "2147483648");
    run_case_ref("overflow -", "-2147483649");
    */

    printf("\nResult: %d/%d passed\n", g_pass, g_total);
    return (g_pass == g_total) ? 0 : 1;
}



