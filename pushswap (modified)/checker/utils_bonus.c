/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:55 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:55 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_stack_sorted(t_node **stack_a)
{
	if (stack_sorted(*stack_a) == 1)
		return (ft_putstr_fd("OK\n", 1), 1);
	else
		return (ft_putstr_fd("KO\n", 1), -1);
}

void	process_the_input(char *input, t_node **stack_a,
		t_node **stack_b)
{
	if (!ft_strncmp(input, "pa", 2))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(input, "pb", 2))
		pb(stack_b, stack_a);
	else if (!ft_strncmp(input, "sa", 2))
		sa(stack_a);
	else if (!ft_strncmp(input, "sb", 2))
		sb(stack_b);
	else if (!ft_strncmp(input, "ss", 2))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(input, "rra", 3))
		rra(stack_a);
	else if (!ft_strncmp(input, "rrb", 3))
		rrb(stack_b);
	else if (!ft_strncmp(input, "rrr", 3))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(input, "ra", 2))
		ra(stack_a);
	else if (!ft_strncmp(input, "rb", 2))
		rb(stack_b);
	else if (!ft_strncmp(input, "rr", 2))
		rr(stack_a, stack_b);
	else
		exit_with_error();
}

void	sort_by_input(t_node **stack_a)
{
	t_node	*stack_b;
	char	*line;

	stack_b = NULL;
	line = NULL;
	if (!*stack_a)
		return ;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (check_line(line) == -1)
			return (free(line));
		process_the_input(line, stack_a, &stack_b);
		free(line);
	}
	if (is_b_empty(&stack_b) == -1)
	{
		free_stack(*stack_a);
		free_stack(stack_b);
		exit(0);
	}
}

int	check_line(char *line)
{
	if (line[0] == 'p' && (line[1] == 'a' || line[1] == 'b') && line[2] == '\n'
		&& !line[3])
		return (1);
	else if (line[0] == 's' && (line[1] == 'a' || line[1] == 'b'
			|| line[1] == 's') && line[2] == '\n' && !line[3])
		return (1);
	else if (line[0] == 'r' && (line[1] == 'a' || line[1] == 'b'
			|| line[1] == 'r') && line[2] == '\n' && !line[3])
		return (1);
	else if (line[0] == 'r' && line[1] == 'r' && (line[2] == 'a'
			|| line[2] == 'b' || line[2] == 'r') && line[3] == '\n' && !line[4])
		return (1);
	else
		return (exit_with_error(), -1);
}

int	is_b_empty(t_node **stack_b)
{
	if (*stack_b)
		return (ft_putstr_fd("KO\n", 1), -1);
	return (0);
}
