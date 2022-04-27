/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:56:29 by hel-hich          #+#    #+#             */
/*   Updated: 2022/02/17 00:20:26 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar (str[i], len);
}

void	ft_check(char str, va_list arg, int *len)
{
	if (str == 'c')
		ft_putchar(va_arg(arg, int), len);
	else if (str == 's')
		ft_putstr(va_arg(arg, char *), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(arg, int), len);
	else if (str == 'u')
		ft_put_u(va_arg(arg, unsigned int), len);
	else if (str == 'p')
	{
		ft_putstr("0x", len);
		ft_put_p(va_arg(arg, unsigned long), len);
	}
	else if (str == 'x' || str == 'X')
		ft_put_x(va_arg(arg, unsigned int), len, str);
	else if (str == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_check(str[++i], arg, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	return (len);
}
