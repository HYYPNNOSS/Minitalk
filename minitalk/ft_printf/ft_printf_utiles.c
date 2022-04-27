/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:49:24 by hel-hich          #+#    #+#             */
/*   Updated: 2022/02/16 19:55:35 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define HEXA "0123456789abcdef"
#define HEXO "0123456789ABCDEF"

void	ft_putnbr(int nb, int *len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar((n % 10 + '0'), len);
}

void	ft_put_u(unsigned int nb, int *len)
{
	long	n;

	n = nb;
	if (n > 9)
		ft_put_u(n / 10, len);
	ft_putchar((n % 10 + '0'), len);
}

void	ft_put_p(unsigned long nb, int *len)
{
	if (nb >= 16)
		ft_put_p(nb / 16, len);
	ft_putchar(HEXA[nb % 16], len);
}

void	ft_put_x(unsigned int nb, int *len, char str)
{
	if (nb >= 16)
		ft_put_x(nb / 16, len, str);
	if (str == 'x')
		ft_putchar(HEXA[nb % 16], len);
	else
		ft_putchar(HEXO[nb % 16], len);
}
