/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:44:14 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else
		{
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
				write(1, "0x", 2);
				ft_putnbr_hex(va_arg(ap, long long), 1);
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == 'd')
			{
				ft_putnbr_dec(va_arg(ap, long long));
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == 'i')
			{
				ft_putnbr_int(va_arg(ap, int));
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == 'u')
			{
				ft_putnbr_uint(va_arg(ap, unsigned int));
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == 'x')
			{
				ft_putnbr_hex(va_arg(ap, long long), 1);
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == 'X')
			{
				ft_putnbr_hex(va_arg(ap, long long), 0);
				idx++;
			}
			else if (str[idx + 1] && str[idx + 1] == '%')
			{
				ft_putchar("%");
				idx++;
			}
		}
		idx++;
	}
	va_end(ap);
	return (ft_strlen(str));
}
