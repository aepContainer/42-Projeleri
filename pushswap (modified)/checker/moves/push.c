/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:39 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:39 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
}
