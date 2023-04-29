/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:57:36 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/29 17:27:46 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	*a;
	int		res;
	char  ch = 'a';

	a = malloc(sizeof(int));
	res = printf("%c %s %p %d %i %u %x %X %%\n", 'a', "asdf", a, (int)-2147483648, -42,
			(int)-2147483648, 2147483647, 2147483647);
	printf("printf 결과 => %d\n", res);
	res = ft_printf("%c %s %p %d %i %u %x %X %%", 'a', "asdf", a, (int)-2147483648, -42,
			(int)-2147483648, 2147483647, 2147483647);
	printf("\nft_printf 결과 => %d\n", res);

	res = printf("%s\n", (void *)0);
	printf("(void *)0의 printf 결과 => %d\n", res);
	res = ft_printf("%s\n", (void *)0);
	printf("(void *)0의 ft_printf 결과 => %d\n", res);

	res = printf("%x %x %X %X\n", LONG_MIN, LONG_MAX, LONG_MIN, LONG_MAX);
	res = ft_printf("%x %x %X %X\n", LONG_MIN, LONG_MAX, LONG_MIN, LONG_MAX);
	return (0);
}
