/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:20 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/24 20:07:48 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"
#include <limits.h>

int	stack_sorted(t_stack_node *node)
{
	if (!node)
		return (-1);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_stack_len(t_stack_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*temp;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
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

void	set_index_and_median(t_stack_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	median = get_stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
		i++;
	}
}

t_stack_node	*init_stack_a(char **input)
{
	t_stack_node	*stack_a;
	long			nbr;

	stack_a = NULL;
	while (*input)
	{
		nbr = ft_atol(*input);
		if (nbr < INT_MIN || nbr > INT_MAX)
		{
			error_message();
			return (NULL);
		}
		if (append_node(&stack_a, (int)nbr) == -1)
		{
			free_stack(stack_a);
			error_message();
			return (NULL);
		}
		input++;
	}
	return (stack_a);
}
