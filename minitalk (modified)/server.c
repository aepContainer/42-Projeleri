/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:24:57 by apalaz            #+#    #+#             */
/*   Updated: 2024/03/22 18:05:36 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_collector(int signal)
{
	static short	bit;
	static char		c;

	if (signal == SIGUSR1)
		c |= 1 << bit;
	else if (signal == SIGUSR2)
		c |= 0 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	ser_pid;

	(void)(argv);
	if (argc != 1)
		ft_printf("Wrong Argument Number!\n");
	else
	{
		ser_pid = getpid();
		ft_printf("PID : %d\n", ser_pid);
		signal(SIGUSR1, &sig_collector);
		signal(SIGUSR2, &sig_collector);
		while (1)
			pause();
	}
	return (0);
}
