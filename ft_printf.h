/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:24:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/28 20:42:47 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *s);
void	ft_putchar(char *c);
void	ft_putstr(char *c);

void	ft_putnbr_hex(long long nb, int isLower);
void	ft_putnbr_dec(long long nb);
void	ft_putnbr_int(int nb);
void	ft_putnbr_uint(unsigned int nb);

#endif