/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:50:01 by hel-hich          #+#    #+#             */
/*   Updated: 2022/02/16 23:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_put_p(unsigned long nb, int *len);
void	ft_put_x(unsigned int nb, int *len, char str);
void	ft_putnbr(int nb, int *len);
void	ft_put_u(unsigned int nb, int *len);

void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_check(char str, va_list arg, int *len);

#endif