/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:24:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/29 17:27:48 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *s);
void	ft_putchar(char c, size_t	*result);
size_t	ft_putstr(char *c, size_t *result);

void	ft_putnbr_hex(unsigned long long nb, int isLower, size_t *result);
void	ft_putnbr_dec(long long nb, size_t *result);
void	ft_putnbr_int(int nb, size_t *result);
void	ft_putnbr_uint(unsigned int nb, size_t *result);

#endif