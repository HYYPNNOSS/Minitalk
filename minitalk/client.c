/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:11:22 by hel-hich          #+#    #+#             */
/*   Updated: 2022/04/01 04:05:19 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	send_signals(char *message, int pid)
{
	int	i;
	int	shift;

	shift = -1;
	i = 0;
	while (message[i])
	{
		shift = -1;
		while (++shift <= 7)
		{
			if (message[i] & (0x80 >> shift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			usleep(500);
		}
	i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		write(1, "FAILURE", 7);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_signals(argv[2], pid);
	return (0);
}
