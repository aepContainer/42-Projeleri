/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:31 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:31 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_node **first_node)
{
	if (!(*first_node) || !(*first_node)->next)
		return ;
	*first_node = (*first_node)->next;
	(*first_node)->prev->prev = *first_node;
	(*first_node)->prev->next = (*first_node)->next;
	if ((*first_node)->next)
		(*first_node)->next->prev = (*first_node)->prev;
	(*first_node)->next = (*first_node)->prev;
	(*first_node)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
}

void	sb(t_node **b)
{
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
