/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:31:50 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:31:50 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	**input;

	input = NULL;
	if (argc == 1)
		return (-1);
	input = create_input(argc, argv);
	stack_a = init_stack_a(input);
	if (input)
		free_input(input);
	if (stack_a)
		check_duplicate(&stack_a);
	if (stack_a && stack_sorted(stack_a) <= 0)
		sort_stack(&stack_a);
	free_stack(stack_a);
	return (0);
}
