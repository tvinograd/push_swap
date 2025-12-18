/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:06:31 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 13:02:20 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack)
{
	int		*array;
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (NULL);
	array = (int *)malloc(sizeof(int) * stack->size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array [j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sorted_copy(int *array, int size)
{
	int	*sorted;
	int	i;

	sorted = (int *)malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	sort_array(sorted, size);
	return (sorted);
}

static int	find_index(int *sorted_array, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_indices(t_stack *stack)
{
	int		*array;
	int		*sorted;
	t_node	*current;

	if (!stack || stack->size == 0)
		return ;
	array = stack_to_array(stack);
	if (!array)
		return ;
	sorted = create_sorted_copy(array, stack->size);
	if (!sorted)
		return (free(array));
	current = stack->top;
	while (current)
	{
		current->index = find_index(sorted, stack->size, current->value);
		current = current->next;
	}
	free(array);
	free(sorted);
}
