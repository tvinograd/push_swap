/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:26:49 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 20:38:16 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->index > stack_a->top->next->index)
		sa(stack_a, 1);
}

void	sort_three(t_stack *stack_a)
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

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

void	sort_six(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	min_pos = find_min(stack_a);
	ra_fast(stack_a, min_pos);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
