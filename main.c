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

static size_t my_strnlen(const char *s, size_t maxlen) {
	size_t i = 0;
	while (i < maxlen && s[i] != '\0') i++;
	return i;
}

static size_t ref_strlcat(char *dst, const char *src, size_t dstsize) {
	size_t dlen = my_strnlen(dst, dstsize);
	size_t slen = strlen(src);

	if (dlen == dstsize)
		return dstsize + slen;

	if (dstsize > 0) {
		size_t space = dstsize - dlen - 1; // место под символы src (без '\0')
		if (space > 0) {
			size_t n = (slen < space) ? slen : space;
			memcpy(dst + dlen, src, n);
			dst[dlen + n] = '\0';
		}
	}

	return dlen + slen;
}

#define GUARD_BYTE 0xCC

static int check_guards(const unsigned char *buf, size_t n_total, size_t n_used) {
	(void)n_used;
	// Проверяем, что хвостовые guard-байты не тронуты
	for (size_t i = n_total; i < n_total + 16; i++) {
		if (buf[i] != GUARD_BYTE) return 0;
	}
	return 1;
}

static int run_case(const char *name, const char *init_dst, const char *src, size_t size) {
	unsigned char dst1[256 + 16];
	unsigned char dst2[256 + 16];

	memset(dst1, GUARD_BYTE, sizeof(dst1));
	memset(dst2, GUARD_BYTE, sizeof(dst2));

	// Заполняем первые 256 байт как буфер назначения
	memset(dst1, 0, 256);
	memset(dst2, 0, 256);

	// Кладём init_dst в оба буфера
	strncpy((char*)dst1, init_dst, 255);
	strncpy((char*)dst2, init_dst, 255);
	dst1[255] = '\0';
	dst2[255] = '\0';

	size_t got = ft_strlcat((char*)dst1, src, size);
	size_t exp = ref_strlcat((char*)dst2, src, size);

	int ok = 1;

	if (strcmp((char*)dst1, (char*)dst2) != 0) ok = 0;
	if (got != exp) ok = 0;

	// Проверка, что guard-байты за пределами 256 не были затронуты
	if (!check_guards(dst1, 256, size)) ok = 0;

	if (!ok) {
		printf("FAIL: %s\n", name);
		printf("  init_dst: \"%s\"\n", init_dst);
		printf("  src:      \"%s\"\n", src);
		printf("  size:     %zu\n", size);
		printf("  got_dst:  \"%s\"\n", (char*)dst1);
		printf("  exp_dst:  \"%s\"\n", (char*)dst2);
		printf("  got_ret:  %zu\n", got);
		printf("  exp_ret:  %zu\n", exp);
		return 0;
	}

	printf("OK:   %s\n", name);
	return 1;
}

int main(void) {
	int pass = 1;

	pass &= run_case("basic_concat_big_size",
		"abc", "defghij", 32);

	pass &= run_case("basic_concat_exact_fit",
		"abc", "def", 7); // "abcdef" + '\0' => size 7

	pass &= run_case("truncate_one_char",
		"abc", "XYZ", 5); // место 1 символ: "abcX"

	pass &= run_case("truncate_more",
		"hello", "WORLD", 8); // "helloWO"

	pass &= run_case("size_equals_destlen_plus1",
		"abcd", "ZZZ", 5); // места 0: "abcd"

	pass &= run_case("size_smaller_than_destlen",
		"abcdef", "123", 4); // ничего не добавится

	pass &= run_case("size_zero",
		"abc", "XYZ", 0);

	pass &= run_case("dest_empty",
		"", "abc", 4); // "abc"

	pass &= run_case("src_empty",
		"abc", "", 10); // "abc"

	pass &= run_case("size_one_nonempty_dest",
		"abc", "XYZ", 1);

	pass &= run_case("size_one_empty_dest",
		"", "XYZ", 1); // только '\0' останется

	pass &= run_case("long_src_small_buffer",
		"start", "0123456789", 9); // "start012"

	pass &= run_case("large_inputs",
		"1234567890", "abcdefghij", 15); // "1234567890abcd"

	pass &= run_case("size_just_enough_for_null",
		"abc", "Z", 4); // "abc" (места 0)

	printf("\nRESULT: %s\n", pass ? "ALL TESTS PASSED" : "SOME TESTS FAILED");
	return pass ? 0 : 1;
}

