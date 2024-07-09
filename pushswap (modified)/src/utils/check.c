/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:28 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:28 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

char	all_space(char **strs)
{
	char	*str;
	char	state;

	if (!*strs || !**strs)
		return (free(*strs), free(strs), 1);
	state = 0;
	str = *strs;
	while (*str)
	{
		if (*str == 32 || (*str <= 9 && *str >= 13))
			state = 1;
		else
		{
			state = 0;
			break;
		}
	}
	if (state)
		return (free(*strs), free(strs), state);
	return (state);
}

int	check_syntax(char *str)
{
	if (!str || !*str)
		return (0);
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (-1);
	if ((*(str + 1) == '+' || *(str + 1) == '-')
		&& !(*(str + 1) >= '0' && *(str + 1) <= '9'))
		return (-1);
	if (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		return (-1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		str++;
	}
	return (1);
}

void	check_duplicate(t_node **stack_a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (!stack_a)
		return ;
	tmp1 = *stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
			{
				free_stack(*stack_a);
				exit_with_error();
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

char	**parse_input(int argc, char **argv)
{
	char	**rtrn;
	int		i;

	rtrn = NULL;
	if (argc == 1)
		rtrn = ft_split(*argv, ' ');
	else
	{
		rtrn = (char **) malloc(sizeof(char *) * (argc + 1));
		rtrn[argc] = NULL;
	}
	if (argc > 1)
	{
		i = 0;
		while (argc-- && *argv)
		{
			rtrn[i] = (char *) malloc(ft_strlen(*argv) + 1);
			if (!rtrn[i])
				return (rtrn);
			ft_strlcpy(rtrn[i], *argv, (int) ft_strlen(*argv) + 1);
			argv++;
			i++;
		}
	}
	return (rtrn);
}

char	**create_input(int argc, char **argv)
{
	char	**rtrn;
	int		i;

	argv++;
	argc--;
	rtrn = NULL;
	rtrn = parse_input(argc, argv);
	if (!rtrn)
		exit_with_error();
	if (all_space(rtrn))
		exit_with_error();
	if (argc == 1)
		argc = char_ptr_len(rtrn);
	i = 0;
	while (argc)
	{
		if (check_syntax(rtrn[i]) == -1)
			exit_with_error();
		i++;
		argc--;
	}
	return (rtrn);
}
