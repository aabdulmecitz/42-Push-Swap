/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 03:01:11 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/28 03:08:51 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*temp;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		temp = find_last_node(*stack);
		temp->next = node;
		node->prev = temp;
	}
	return (0);
}

t_stack	*init_stack_a(char **input)
{
	t_stack	*stack_a;
	long			nbr;

	stack_a = NULL;
	while (*input)
	{
		nbr = ft_atol(*input);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			error_message("The input exceeds the bounds of an integer.");
			return (NULL);
		}
		if (append_node(&stack_a, (int)nbr) == -1)
		{
			free_stack(stack_a);
			error_message("the node could not be created.");
			return (NULL);
		}
		input++;
	}
	return (stack_a);
}