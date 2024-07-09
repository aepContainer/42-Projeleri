/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:36 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:36 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_node **first_node)
{
	t_node	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = find_last_node(*first_node);
	last_node->prev->next = NULL;
	last_node->next = *first_node;
	last_node->prev = NULL;
	*first_node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a)
{
	rev_rotate(a);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
