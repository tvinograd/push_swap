/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:20:02 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 20:40:25 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	ra_fast(t_stack *stack_a, int position)
{
	if (position <= stack_a->size / 2)
	{
		while (position > 0)
		{
			ra(stack_a, 1);
			position--;
		}
	}
	else
	{
		while (position < stack_a->size)
		{
			rra(stack_a, 1);
			position++;
		}
	}
}

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

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
		return (sort_two(stack_a));
	if (stack_a->size == 3)
		return (sort_three(stack_a));
	if (stack_a->size == 4)
		return (sort_four(stack_a, stack_b));
	if (stack_a->size == 5)
		return (sort_five(stack_a, stack_b));
	if (stack_a->size == 6)
		return (sort_six(stack_a, stack_b));
	sort_radix(stack_a, stack_b);
}
