/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:52:06 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 13:07:11 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int stack_size)
{
	int	bits;
	int	max_num;

	if (stack_size <= 1)
		return (0);
	max_num = stack_size - 1;
	bits = 0;
	while (max_num > 0)
	{
		max_num = max_num >> 1;
		bits++;
	}
	return (bits);
}

static int	get_bit(int num, int bit_position)
{
	return ((num >> bit_position) & 1);
}

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit_position)
{
	int	size;
	int	i;
	int	current_index;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		current_index = stack_a->top->index;
		if (get_bit(current_index, bit_position) == 0)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
		i++;
	}
}

static void	pa_all(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
		pa(stack_a, stack_b, 1);
}

void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit_position;

	max_bits = get_max_bits(stack_a->size);
	bit_position = 0;
	while (bit_position < max_bits)
	{
		process_bit(stack_a, stack_b, bit_position);
		pa_all(stack_a, stack_b);
		bit_position++;
	}
}
