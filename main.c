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

void *ft_memcpy(void *dest, const void *src, size_t n);

/* Вспомогательная функция: сравнить ft_memcpy с стандартной memcpy */
static void test_case(const char *test_name,
                      void *dest1, void *dest2,
                      const void *src,
                      size_t n)
{
    printf("== %s ==\n", test_name);

    // делаем копию исходника, чтобы обе функции читали одно и то же
    unsigned char tmp_src[256];
    assert(n <= sizeof(tmp_src));
    memcpy(tmp_src, src, n);

    memcpy(dest1, tmp_src, n);
    ft_memcpy(dest2, tmp_src, n);

    int cmp = memcmp(dest1, dest2, n);
    if (cmp != 0) {
        printf("[FAIL] dest1 != dest2\n");
        printf("  memcpy:   ");
        for (size_t i = 0; i < n; ++i)
            printf("%02X ", ((unsigned char *)dest1)[i]);
        printf("\n  ft_memcpy:");
        for (size_t i = 0; i < n; ++i)
            printf("%02X ", ((unsigned char *)dest2)[i]);
        printf("\n");
    } else {
        printf("[OK]\n");
    }

    assert(cmp == 0);
}

/* Тест n == 0: ничего не должно меняться */
static void test_zero_length(void)
{
    printf("== test_zero_length ==\n");

    char src[]  = "hello";
    char dest1[] = "XXXXX";
    char dest2[] = "XXXXX";

    memcpy(dest1, src, 0);
    ft_memcpy(dest2, src, 0);

    // буферы должны быть одинаковыми (ничего не копировалось)
    assert(memcmp(dest1, dest2, sizeof(dest1)) == 0);
    printf("[OK]\n");
}

/* Тест строк */
static void test_strings(void)
{
    char src[]   = "abcdef";
    char dest1[16] = {0};
    char dest2[16] = {0};

    test_case("strings full copy", dest1, dest2, src, strlen(src) + 1);

    // частичное копирование
    memset(dest1, 0xAA, sizeof(dest1));
    memset(dest2, 0xAA, sizeof(dest2));
    test_case("strings partial copy", dest1, dest2, src, 3);
}

/* Тест бинарных данных с нулями */
static void test_binary(void)
{
    uint8_t src[]  = {0x00, 0x01, 0xFF, 0x10, 0x00, 0x7F, 0x80, 0x55};
    uint8_t dest1[8] = {0};
    uint8_t dest2[8] = {0};

    test_case("binary data", dest1, dest2, src, sizeof(src));
}

/* Тест большого буфера */
static void test_large(void)
{
    uint8_t src[128];
    uint8_t dest1[128];
    uint8_t dest2[128];

    for (size_t i = 0; i < sizeof(src); ++i)
        src[i] = (uint8_t)(i * 3 + 7);

    test_case("large buffer", dest1, dest2, src, sizeof(src));
}

/* Перекрытие (overlap) — для memcpy это UB, но посмотрим расхождение */
static void test_overlap_demo(void)
{
    printf("== overlap demo (UB для memcpy) ==\n");

    char buf1[16] = "1234567890ABCD";
    char buf2[16] = "1234567890ABCD";

    // стандарт: UB, но часто ведёт себя предсказуемо
    memcpy(buf1 + 2, buf1, 8);
    ft_memcpy(buf2 + 2, buf2, 8);

    printf("memcpy:    %s\n", buf1);
    printf("ft_memcpy: %s\n", buf2);
    printf("Разница здесь не считается багом стандарта, "
           "так как overlap для memcpy — UB.\n\n");
}

int main(void)
{
    test_zero_length();
    test_strings();
    test_binary();
    test_large();
    test_overlap_demo();

    printf("All tests passed.\n");
    return 0;
}






