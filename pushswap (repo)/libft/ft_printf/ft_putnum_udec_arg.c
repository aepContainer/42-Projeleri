/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_udec_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:31:38 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:59:57 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "unistd.h"

void	ft_putnum_udec_arg(t_ui ui, int *printed)
{
	char	c;

	if (ui > 9)
	{
		ft_putnum_udec_arg(ui / 10, printed);
		ft_putnum_udec_arg(ui % 10, printed);
		return ;
	}
	c = ui + 48;
	write(1, &c, 1);
	(*printed)++;
}
