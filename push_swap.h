/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:02:16 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/13 20:53:49 by tvinogra         ###   ########.fr       */
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

t_node	*create_node(int value);
t_stack	*create_stack(void);
void	free_node(t_node *node);
void	free_stack(t_stack *stack);
void	add_node(t_stack *stack, t_node *new_node);

int		ft_atoi_ps(const char *str, int *error);
void	free_split(char **split);
int		ft_isduplicate(t_stack *stack, int value);
int		parse_argument(t_stack *stack, char *arg);
t_stack	*parse_arguments(int argc, char **argv);

#endif
