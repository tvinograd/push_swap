/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvinogra <tvinogra@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:37:59 by tvinogra          #+#    #+#             */
/*   Updated: 2025/12/18 12:58:55 by tvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	convert_digits(const char *str, int *i, int sign, int *error)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (*error = 1, 0);
		(*i)++;
	}
	return (result);
}

static int	validate_trailing(const char *str, int i, int *error)
{
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (*error = 1, 0);
		i++;
	}
	return (1);
}

int	ft_atoi_ps(const char *str, int *error)
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
	result = convert_digits(str, &i, sign, error);
	if (*error)
		return (0);
	if (!validate_trailing(str, i, error))
		return (0);
	return ((int)(result * sign));
}
