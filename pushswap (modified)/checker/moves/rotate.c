/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:34 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:34 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_node **first_node)
{
	t_node	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = find_last_node(*first_node);
	last_node->next = *first_node;
	*first_node = (*first_node)->next;
	(*first_node)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}