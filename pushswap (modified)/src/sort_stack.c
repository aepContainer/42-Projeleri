/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:31:55 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:31:55 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack(t_node **stack_a)
{
	if (get_stack_len(*stack_a) == 2)
		sa(stack_a);
	else if (get_stack_len(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_algorithm(stack_a);
}

void	sort_algorithm(t_node **stack_a)
{
	t_node	*stack_b;
	int		len_a;

	stack_b = NULL;
	len_a = get_stack_len(*stack_a);
	if (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
		pb(&stack_b, stack_a);
	if (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
		pb(&stack_b, stack_a);
	while (len_a-- > 3 && stack_sorted(*stack_a) <= 0)
	{
		init_nodes_a(*stack_a, stack_b);
		move_a_to_b(stack_a, &stack_b);
	}
	sort_three(stack_a);
	while (stack_b)
	{
		init_nodes_b(*stack_a, stack_b);
		move_b_to_a(stack_a, &stack_b);
	}
	set_index_and_median(*stack_a);
	lowest_node_on_top(stack_a);
}

void	sort_three(t_node **stack_a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest_node(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a);
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a, *stack_b);
	t_node	*temp;
	int i = 0;
	temp = *stack_a;
	while (temp)
	{
		ft_printf("a[%d] : %d\ta[%d].target : %d \t", i, temp->nbr, i, temp->target->nbr);
		ft_printf("a[%d].is_above_median : %d\ta[%d].cost : %d\n", i, temp->is_above_median, i, temp->cost);
		temp = temp->next;
		i++;
	}
	ft_printf("\n");
	temp = *stack_b;
	i = 0;
	while (temp)
	{
		ft_printf("b[%d] : %d\tb[%d].index : %d\tb[%d].is_above_median : %d\n", i, temp->nbr, i, temp->index, i,  temp->is_above_median);
		temp = temp->next;
		i++;
	}
	if (cheapest_node->is_above_median
		&& cheapest_node->target->is_above_median)
		while (*stack_b != cheapest_node->target
			&& *stack_a != cheapest_node)
			rr(stack_a, stack_b);
	else if (!(cheapest_node->is_above_median)
		&& !(cheapest_node->target->is_above_median))
		while (*stack_b != cheapest_node->target
			&& *stack_a != cheapest_node)
			rrr(stack_a, stack_b);
	get_node_to_top_a(stack_a, cheapest_node);
	get_node_to_top_b(stack_b, cheapest_node->target);
	pb(stack_b, stack_a);
}

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	get_node_to_top_a(stack_a, (*stack_b)->target);
	pa(stack_a, stack_b);
}
