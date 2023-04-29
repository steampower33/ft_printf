/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/29 17:28:29 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	size_t	result;

	if (!str)
		return (0);
	idx = 0;
	result = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] != '%')
			ft_putchar(str[idx], &result);
		else if (str[idx] == '%')
		{
			if (str[idx + 1] && str[idx + 1] == 'c')
				ft_putchar((char)va_arg(ap, int), &result);
			else if (str[idx + 1] && str[idx + 1] == 's')
				ft_putstr(va_arg(ap, char *), &result);
			else if (str[idx + 1] && str[idx + 1] == 'p')
			{
				ft_putstr("0x", &result);
				ft_putnbr_hex(va_arg(ap, unsigned long long), 1, &result);
			}
			else if (str[idx + 1] && str[idx + 1] == 'd')
				ft_putnbr_dec(va_arg(ap, int), &result);
			else if (str[idx + 1] && str[idx + 1] == 'i')
				ft_putnbr_int(va_arg(ap, int), &result);
			else if (str[idx + 1] && str[idx + 1] == 'u')
				ft_putnbr_uint(va_arg(ap, unsigned int), &result);
			else if (str[idx + 1] && str[idx + 1] == 'x')
				ft_putnbr_hex(va_arg(ap, unsigned int), 1, &result);
			else if (str[idx + 1] && str[idx + 1] == 'X')
				ft_putnbr_hex(va_arg(ap, unsigned int), 0, &result);
			else if (str[idx + 1] && str[idx + 1] == '%')
				ft_putchar('%', &result);
			idx++;
		}
		idx++;
	}
	va_end(ap);
	return (result);
}
