/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                       :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: mendoza <mendoza@student.42.fr>               +#+  +:+       +#+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:00:00 by mendoza             #+#    #+#           */
/*   Updated: 2025/01/01 00:00:00 by mendoza            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int value, size_t n) {
    unsigned char *val = (unsigned char *) s;
    size_t i = 0;

    while (i < n) {
        val[i] = (unsigned char)value;
        i++;
    }

    return s;
}
