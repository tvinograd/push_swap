/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:52:18 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 12:51:41 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	process_number(t_stack *stack, char *num_str)
{
	int		value;
	int		error;
	t_node	*new_node;

	error = 0;
	value = ft_atoi_ps(num_str, &error);
	if (error || is_duplicate(stack, value))
		return (0);
	new_node = create_node(value);
	if (!new_node)
		return (0);
	add_node(stack, new_node);
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	parse_argument(t_stack *stack, char *arg)
{
	char	**numbers;
	int		i;

	if (ft_strchr(arg, ' '))
	{
		numbers = ft_split(arg, ' ');
		if (!numbers)
			return (0);
		i = 0;
		while (numbers[i])
		{
			if (!process_number(stack, numbers[i]))
				return (free_split(numbers), 0);
			i++;
		}
		free_split(numbers);
	}
	else
	{
		if (!process_number(stack, arg))
			return (0);
	}
	return (1);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc < 2)
		return (NULL);
	stack = create_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!parse_argument(stack, argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
