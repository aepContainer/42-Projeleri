/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:08 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:08 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

t_node	*init_stack_a(char **input)
{
	t_node	*rtrn;
	long	nbr;

	if (!input)
		return (NULL);
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

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	char_ptr_len(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}
