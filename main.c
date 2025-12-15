/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:26:46 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/16 00:29:28 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	if (stack_a->size <= 1)
		return (free(stack_a), 0);
	stack_b = create_stack();
	if (!stack_b)
		return (free_stack(stack_a), 1);
	assign_index(stack_a);
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return(0);
}

