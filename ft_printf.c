/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 19:49:08 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar(char *c)
{
	write(1, c, 1);
}

void	ft_putstr(char *c)
{
	size_t	idx;

	idx = 0;
	while (idx < ft_strlen(c))
	{
		ft_putchar(&c[idx]);
		idx++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	char	tmp;

	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
		{
			tmp = str[idx];
			ft_putchar(&tmp);
		}
		if (str[idx + 1] && str[idx + 1] == 'c')
		{
			tmp = va_arg(ap, int);
			ft_putchar(&tmp);
			idx++;
		}
		else if (str[idx + 1] && str[idx + 1] == 's')
		{
			ft_putstr(va_arg(ap, char *));
			idx++;
		}
		else if (str[idx + 1] && str[idx + 1] == 'p')
		{
			
			idx++;
		}
		else if (str[idx + 1] && str[idx + 1] == 'd')
		{
			tmp = '0' + va_arg(ap, int);
			ft_putchar(&tmp);
			idx++;
		}
		idx++;
	}
	va_end(ap);
	return (ft_strlen(str));
}
