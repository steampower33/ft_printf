/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:42:20 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/29 17:28:37 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long long nb, int isLower, size_t *result)
{
	char	num;

	if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			ft_putchar(num, result);
		}
		else if (10 <= nb && nb <= 15)
		{
			if (isLower)
				num = 'a' + nb - 10;
			else
				num = 'A' + nb - 10;
			ft_putchar(num, result);
		}
		else
		{
			ft_putnbr_hex(nb / 16, isLower, result);
			ft_putnbr_hex(nb % 16, isLower, result);
		}
	}
}

void	ft_putnbr_dec(long long nb, size_t *result)
{
	char	num;

	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', result);
		ft_putnbr_dec(nb, result);
	}
	else if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			ft_putchar(num, result);
		}
		else
		{
			ft_putnbr_dec(nb / 10, result);
			ft_putnbr_dec(nb % 10, result);
		}
	}
}

void	ft_putnbr_int(int nb, size_t *result)
{
	char	num;

	if (nb == -2147483648)
		ft_putstr("-2147483648", result);
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', result);
		ft_putnbr_int(nb, result);
	}
	else if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			ft_putchar(num, result);
		}
		else
		{
			ft_putnbr_int(nb / 10, result);
			ft_putnbr_int(nb % 10, result);
		}
	}
}

void	ft_putnbr_uint(unsigned int nb, size_t *result)
{
	char	num;

	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', result);
		ft_putnbr_uint(nb, result);
	}
	if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			ft_putchar(num, result);
		}
		else
		{
			ft_putnbr_uint(nb / 10, result);
			ft_putnbr_uint(nb % 10, result);
		}
	}
}
