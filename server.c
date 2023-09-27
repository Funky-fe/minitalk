/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:08:22 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/09/09 14:53:23 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	i;
	static int	bits;

	if (sig == SIGUSR1)
		i |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error \n");
		ft_printf("Please use only ./server.");
		return (1);
	}
	pid = getpid();
	ft_printf("Server pid is %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	ft_printf("\n");
	return (0);
}
