/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:20:02 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 11:43:03 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

static void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->index > stack_a->top->next->index)
		sa(stack_a, 1);
}

static void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->index;
	second = stack_a->top->next->index;
	third = stack_a->top->next->next->index;
	if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		return (sort_two(stack_a));
	if (stack_a->size == 3)
		return (sort_three(stack_a));
	radix(stack_a, stack_b);
}
