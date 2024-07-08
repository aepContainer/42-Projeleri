/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:47 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:32:47 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include "limits.h"
# include "unistd.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				nbr;
	int				index;
	int				cost;
	char			is_above_median;
}				t_node;

void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

int		is_stack_sorted(t_node **stack_a);
int		check_line(char *line);
void	sort_by_input(t_node **stack_a);
void	process_the_input(char *input, t_node **stack_a, t_node **stack_b);
int		is_b_empty(t_node **stack_b);

long	ft_atol(const char *str);
int		char_ptr_len(char **input);
int		stack_sorted(t_node *node);
int		append_node(t_node **stack, int nbr);
t_node	*init_stack_a(char **input);
t_node	*find_last_node(t_node *node);
void	exit_with_error(void);
void	free_input(char **input);
void	free_stack(t_node *node);
int		check_syntax(char *str);
void	check_duplicate(t_node **stack_a);
char	**parse_input(int argc, char **argv);
char	**create_input(int argc, char **argv);

#endif
