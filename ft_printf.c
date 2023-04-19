/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/19 17:52:05 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	numlist;
	int	i;

	va_start(numlist, numargs);
	i = 10
	while (i < 0)
	{
		printf("%d 번째 가변인자 : %d \n", i + 1, (va_arg(numlist, int)));
		i++;
	}
	//사용이 끝난 가변인자 목록 포인터의 소멸
	va_end(numlist);
}
