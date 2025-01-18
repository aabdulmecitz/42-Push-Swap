/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:25 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/18 19:21:33 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	str_arr_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}
