/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:41:30 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/29 17:28:33 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar(char c, size_t	*result)
{
	write(1, &c, 1);
	*result += 1;
}

size_t	ft_putstr(char *c, size_t *result)
{
	size_t	idx;

	if (!c)
		c = "(null)";
	idx = 0;
	while (idx < ft_strlen(c))
		ft_putchar(c[idx++], result);
	return (idx);
}
