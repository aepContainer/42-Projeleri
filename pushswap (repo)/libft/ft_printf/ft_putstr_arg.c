/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:29:41 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 17:00:00 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "unistd.h"

void	ft_putstr_arg(char *str, int *printed)
{
	if (!str)
	{
		write(1, "(null)", 6);
		*printed += 6;
		return ;
	}
	while (*str)
	{
		write(1, str, 1);
		(*printed)++;
		str++;
	}
}
