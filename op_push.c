/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:14:37 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/15 11:15:44 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*node_to_push;

	if (!stack_b || !stack_b->top)
		return ;
	node_to_push = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	node_to_push->next = stack_a->top;
	stack_a->top = node_to_push;
	stack_a->size++;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*node_to_push;

	if (!stack_a || !stack_a->top)
		return ;
	node_to_push = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->size--;
	node_to_push->next = stack_b->top;
	stack_b->top = node_to_push;
	stack_b->size++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}
