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

int main(void)
{
    const unsigned char src1[] = "Hello, World!";
    const size_t len1 = sizeof(src1); // с '\0'

    // 1) Символ найден в середине
    run_test("1) c = 'o', n = len1", src1, len1, 'o', len1);

    // 2) Символ не найден
    run_test("2) c = 'x' (нет в строке)", src1, len1, 'x', len1);

    // 3) Символ — первый байт
    run_test("3) c = 'H', первый байт", src1, len1, 'H', len1);

    // 4) Символ — нулевой терминатор
    run_test("4) c = '\\0'", src1, len1, '\0', len1);

    // 5) Ограничение по n (символ есть, но дальше n)
    run_test("5) ограниченный n, c за пределами n", src1, len1, 'W', 5);

    // 6) n = 0 (ничего не копируется)
    run_test("6) n = 0", src1, len1, 'H', 0);

    // 7) Бинарные данные с нулевыми байтами
    const unsigned char src_bin[] = {0x01, 0x00, 0x02, 0x03, 0x00, 0xFF};
    run_test("7) бинарные данные, c = 0x00", src_bin, sizeof(src_bin), 0x00, sizeof(src_bin));

    return 0;
}







