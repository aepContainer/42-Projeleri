/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalaz <apalaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:33:00 by apalaz            #+#    #+#             */
/*   Updated: 2024/05/23 16:33:00 by apalaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "limits.h"
# include "stdlib.h"

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
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	sort_stack(t_node **stack_a);
void	sort_three(t_node **stack_a);
void	sort_algorithm(t_node **stack_a);

long	ft_atol(const char *str);
char	**parse_input(int argc, char **argv);
char	**create_input(int argc, char **argv);
int		char_ptr_len(char **input);

int		get_stack_len(t_node *node);
int		stack_sorted(t_node *node);
t_node	*init_stack_a(char **argv);
int		append_node(t_node **stack, int nbr);
void	set_index_and_median(t_node *node);
t_node	*get_cheapest_node(t_node *node_a, t_node *node_b);

t_node	*find_last_node(t_node *node);
t_node	*find_biggest_node(t_node *node);
t_node	*find_lowest_node(t_node *node);

void	get_node_to_top_a(t_node **stack_a, t_node *top_node);
void	get_node_to_top_b(t_node **stack_b, t_node *top_node);
void	lowest_node_on_top(t_node **stack_a);

void	exit_with_error(void);

void	check_duplicate(t_node **stack_a);
int		check_syntax(char *str);

void	free_input(char **input);
void	free_stack(t_node *node);

void	init_nodes_a(t_node *a, t_node *b);
void	init_nodes_b(t_node *a, t_node *b);

void	move_a_to_b(t_node **stack_a, t_node **stack_b);
void	move_b_to_a(t_node **stack_a, t_node **stack_b);

void	set_targets_a(t_node *stack_a, t_node *stack_b);
void	set_targets_b(t_node *stack_a, t_node *stack_b);

#endif
