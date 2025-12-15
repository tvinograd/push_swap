/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:52:18 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/15 23:02:36 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_ps(const char *str, int *error)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (*error = 1, 0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (*error = 1, 0);
		i++;
	}
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (*error = 1, 0);
		i++;
	}
	return ((int)(result * sign));
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

static int	parse_argument(t_stack *stack, char *arg)
{
	char	**numbers;
	int		value;
	int		error;
	int		i;
	t_node	*new_node;

	if (ft_strchr(arg, ' '))
	{
		numbers = ft_split(arg, ' ');
		if (!numbers)
			return (0);
		i = 0;
		while (numbers[i])
		{
			error = 0;
			value = ft_atoi_ps(numbers[i], &error);
			if (error || is_duplicate(stack, value))
				return (free_split(numbers), 0);
			new_node = create_node(value);
			if (!new_node)
				return (free_split(numbers), 0);
			add_node(stack, new_node);
			i++;
		}
		free_split(numbers);
	}
	else
	{
		error = 0;
		value = ft_atoi_ps(arg, &error);
		if (error || is_duplicate(stack, value))
			return (0);
		new_node = create_node(value);
		if (!new_node)
			return (0);
		add_node(stack, new_node);
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
