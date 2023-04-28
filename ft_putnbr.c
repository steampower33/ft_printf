/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:42:20 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:43:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(long long nb, int isLower)
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
			if (isLower)
				num = 'a' + nb - 10;
			else
				num = 'A' + nb - 10;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr_hex(nb / 16, isLower);
			ft_putnbr_hex(nb % 16, isLower);
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

void	ft_putnbr_uint(unsigned int nb)
{
	char	num;

	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
		ft_putnbr_int(nb);
	}
	if (nb >= 0)
	{
		if (0 <= nb && nb <= 9)
		{
			num = '0' + nb;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr_uint(nb / 10);
			ft_putnbr_uint(nb % 10);
		}
	}
}
