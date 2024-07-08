/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:20 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:20 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	free_input(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
}

void	free_stack(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
