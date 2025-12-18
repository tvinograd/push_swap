/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:02:16 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 14:24:18 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// ft_atoi for push_swap
int		ft_atoi_ps(const char *str, int *error);

// Stack
t_node	*create_node(int value);
t_stack	*create_stack(void);
void	free_stack(t_stack *stack);
void	add_node(t_stack *stack, t_node *new_node);

// Parse
t_stack	*parse_arguments(int argc, char **argv);

// Index
void	assign_indices(t_stack *stack);

// Operations
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b, int print);
void	pb(t_stack *stack_a, t_stack *stack_b, int print);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Sort
void	radix(t_stack *stack_a, t_stack *stack_b);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
