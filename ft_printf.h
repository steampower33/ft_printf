/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:24:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/05/15 22:04:02 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_conversions(const char *str, va_list ap, int *result,
			size_t *idx);

size_t	ft_strlen(const char *s);
void	ft_putchar(char c, int *result);
void	ft_putstr(char *c, int *result);

void	ft_putnbr_hex(unsigned long long nb, int *result, char conversion);
void	ft_putnbr_int(int nb, int *result);
void	ft_putnbr_uint(unsigned int nb, int *result);

#endif