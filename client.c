/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:38:32 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/09/09 15:54:44 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *n)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (n[i] == 32 || (n[i] >= 9 && n[i] <= 13))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(n[i]) == 1)
	{
		res = (n[i] - 48) + (res * 10);
		i++;
	}
	res = res * neg;
	return (res);
}

void	signal_sender(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (0x01 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal_sender(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Error!\n");
		ft_printf("Please try ./client (pid) (Message)\n");
		return (1);
	}
}
