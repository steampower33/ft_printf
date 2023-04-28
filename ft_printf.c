/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:16:40 by seunlee2         ###   ########.fr       */
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
		ft_putchar(&c[idx++]);
}

void	ft_putnbr_hex(long long nb)
{
	char	num;

	if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			write(1, &num, 1);
		}
		else if (10 <= nb && nb <= 15)
		{
			num = 'a' + nb - 10;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr_hex(nb / 16);
			ft_putnbr_hex(nb % 16);
		}
	}
}

void	ft_putnbr_dec(long long nb)
{
	char	num;

	if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr_dec(nb / 10);
			ft_putnbr_dec(nb % 10);
		}
	}
}

void	ft_putnbr_int(int nb)
{
	char	num;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr_int(nb);
	}
	else if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr_int(nb / 10);
			ft_putnbr_int(nb % 10);
		}
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
			write(1, "0x", 2);
			ft_putnbr_hex(va_arg(ap, long long));
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
		idx++;
	}
	va_end(ap);
	return (ft_strlen(str));
}
