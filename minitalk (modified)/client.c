/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:25:01 by apalaz            #+#    #+#             */
/*   Updated: 2024/03/22 18:08:05 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_stoi(char *str)
{
	int	rtrn;
	int	i;

	rtrn = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		rtrn = 10 * rtrn + str[i] - 48;
	}
	return (rtrn);
}

static void	sig_distributor(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	ser_pid;
	int	i;

	if (argc != 3)
		ft_printf("Wrong Argument Number!\n");
	else
	{
		ser_pid = ft_stoi(argv[1]);
		if (!ser_pid)
		{
			ft_printf("PID Must Be A Number!\n");
			return (0);
		}
		i = -1;
		while (argv[2][++i])
			sig_distributor(ser_pid, argv[2][i]);
		sig_distributor(ser_pid, '\n');
		sig_distributor(ser_pid, '\0');
	}
	return (0);
}
