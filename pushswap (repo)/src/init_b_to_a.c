/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:00 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:00 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_nodes_b(t_node *a, t_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_targets_b(a, b);
}

void	set_targets_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_a;
	t_node	*target_node;
	long	closest_bigger_nbr;

	while (stack_b)
	{
		closest_bigger_nbr = LONG_MAX;
		node_a = stack_a;
		while (node_a)
		{
			if (node_a->nbr > stack_b->nbr
				&& node_a->nbr < closest_bigger_nbr)
			{
				closest_bigger_nbr = node_a->nbr;
				target_node = node_a;
			}
			node_a = node_a->next;
		}
		if (closest_bigger_nbr == LONG_MAX)
			stack_b->target = find_lowest_node(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
