/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:02:16 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/14 01:03:11 by tvinogra         ###   ########.fr       */
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

// Stack utils
t_node	*create_node(int value);
t_stack	*create_stack(void);
//void	free_node(t_node *node);
void	free_stack(t_stack *stack);
void	add_node(t_stack *stack, t_node *new_node);

// Parsing
//int		ft_atoi_ps(const char *str, int *error);
//void	free_split(char **split);
//int		ft_isduplicate(t_stack *stack, int value);
//int		parse_argument(t_stack *stack, char *arg);
t_stack	*parse_arguments(int argc, char **argv);

// Indexing
//int		*stack_to_array(t_stack *stack);
//void	sort_array(int *array, int size);
//int		find_index(int *sorted_array, int size, int value);
void	assign_indices(t_stack *stack);
int		get_max_bits(int stack_size);

#endif
