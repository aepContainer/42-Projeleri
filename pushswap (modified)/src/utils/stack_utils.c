/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:12 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:12 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_sorted(t_node *node)
{
	if (!node)
		return (-1);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_stack_len(t_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*temp;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		temp = find_last_node(*stack);
		temp->next = node;
		node->prev = temp;
	}
	return (0);
}

void	set_index_and_median(t_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = get_stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->is_above_median = 1;
		else
			node->is_above_median = 0;
		node = node->next;
		i++;
	}
}

t_node	*init_stack_a(char **input)
{
	t_node	*rtrn;
	long	nbr;

	rtrn = NULL;
	while (*input)
	{
		nbr = ft_atol(*input);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (exit_with_error(), NULL);
		if (append_node(&rtrn, (int) nbr) == -1)
			return (free_stack(rtrn), exit_with_error(), NULL);
		input++;
	}
	return (rtrn);
}
