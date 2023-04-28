/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:57:36 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:06:31 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*a;

	a = malloc(sizeof(int));
	printf("%c %s %p %d\n", 'a', "asdf", a, 42);
	ft_printf("%c %s %p %d", 'a', "asdf", a, 42);
	return (0);
}
