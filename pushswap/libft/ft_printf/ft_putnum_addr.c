/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:11:20 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:59:39 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "unistd.h"

void	ft_putnum_addr(t_ul ul, int *printed)
{
	write(1, "0x", 2);
	(*printed) += 2;
	ft_putnum_hex_ul_arg(ul, printed);
}
