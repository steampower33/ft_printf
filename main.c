/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:57:36 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:49:55 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*a;
	int		res;

	a = malloc(sizeof(int));
	res = printf("%c %s %p %d %i %u %x %X %%\n", 'a', "asdf", a, 21000, -42, 
			-2147483647, 2147483647, 2147483647);
	printf("printf 결과 => %d\n", res);
	res = ft_printf("%c %s %p %d %i %u %x %X %%", 'a', "asdf", a, 21000, -42,
			-2147483647, 2147483647, 2147483647);
	printf("\nft_printf 결과 => %d\n", res);
	return (0);
}
