//
// Created by Mendoza on 11/24/2025.
//

#include <stdio.h>
#include <string.h>
#include "libft.h"


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/*
** Прототип твоей функции
*/
void *ft_memccpy(void *dest, const void *src, int c, size_t n);

/*
** Удобная функция для печати буфера
*/
static void print_buf(const char *label, const unsigned char *buf, size_t n)
{
    printf("%s: \"", label);
    for (size_t i = 0; i < n; i++) {
        unsigned char ch = buf[i];
        if (ch >= 32 && ch <= 126)
            printf("%c", ch);
        else
            printf("\\x%02X", ch);
    }
    printf("\"\n");
}

/*
** Проверка одного тест-кейса: сравниваем результат ft_memccpy и memccpy
*/
static void run_test(
    const char *test_name,
    const unsigned char *src_init,
    size_t buf_size,
    int c,
    size_t n
)
{
    unsigned char *src1 = malloc(buf_size);
    unsigned char *src2 = malloc(buf_size);
    unsigned char *dst1 = malloc(buf_size);
    unsigned char *dst2 = malloc(buf_size);

    if (!src1 || !src2 || !dst1 || !dst2) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }

    memcpy(src1, src_init, buf_size);
    memcpy(src2, src_init, buf_size);

    memset(dst1, 0xAA, buf_size); // заполняем мусором для наглядности
    memset(dst2, 0xAA, buf_size);

    void *ret_std = memccpy(dst1, src1, c, n);
    void *ret_ft  = ft_memccpy(dst2, src2, c, n);

    int equal = (memcmp(dst1, dst2, buf_size) == 0);
    int same_ret = 0;

    if (ret_std == NULL && ret_ft == NULL)
        same_ret = 1;
    else if (ret_std != NULL && ret_ft != NULL) {
        // сравниваем смещение указателей от начала dest
        ptrdiff_t off_std = (unsigned char *)ret_std - dst1;
        ptrdiff_t off_ft  = (unsigned char *)ret_ft  - dst2;
        same_ret = (off_std == off_ft);
    }

    printf("=== %s ===\n", test_name);
    printf("c = 0x%02X ('%c'), n = %zu, buf_size = %zu\n",
           (unsigned char)c,
           (c >= 32 && c <= 126) ? c : '.',
           n, buf_size);

    print_buf("dst (std)", dst1, buf_size);
    print_buf("dst ( ft)", dst2, buf_size);

    printf("memcmp(dst_std, dst_ft) = %s\n", equal ? "OK" : "MISMATCH");
    printf("return value           = %s\n", same_ret ? "OK" : "MISMATCH");
    printf("\n");

    // Если хочешь жёсткие проверки — раскомментируй:
    // assert(equal && same_ret);

    free(src1);
    free(src2);
    free(dst1);
    free(dst2);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memchr(const void *s, int c, size_t n);

static void test_case(const char *desc, const void *buf, int c, size_t n) {
    void *std_res = memchr(buf, c, n);
    void *ft_res  = ft_memchr(buf, c, n);

    printf("%-35s | ", desc);

    if (std_res == ft_res)
        printf("OK\n");
    else
        printf("FAIL (expected %p, got %p)\n", std_res, ft_res);
}

int main(void) {
    char data1[] = "Hello world";
    char data2[] = {0, 1, 2, 3, 4, 5};
    char data3[] = "abcdef";

    test_case("char in the middle", data1, 'o', 11);
    test_case("char at start", data1, 'H', 11);
    test_case("char at end", data1, 'd', 11);
    test_case("char not found", data1, 'z', 11);
    test_case("n = 0", data1, 'H', 0);

    test_case("search zero byte", data2, 0, 6);
    test_case("byte > 127", data2, 200, 6);

    test_case("short n", data3, 'e', 3);    // should NOT find
    test_case("short n find", data3, 'c', 3); // should find

    return 0;
}








