/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:03 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/14 19:48:05 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stddef.h>

t_stack_node	*find_last_node(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack_node	*find_biggest_node(t_stack_node *node)
{
	t_stack_node	*biggest_node;
	long			biggest_value;

	if (!node)
		return (NULL);
	biggest_value = LONG_MIN;
	while (node)
	{
		if (node->nbr > biggest_value)
		{
			biggest_value = node->nbr;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

t_stack_node	*find_lowest_node(t_stack_node *node)
{
	t_stack_node	*lowest_node;
	long			lowest_value;

	if (!node)
		return (NULL);
	lowest_value = LONG_MAX;
	while (node)
	{
		if (node->nbr < lowest_value)
		{
			lowest_value = node->nbr;
			lowest_node = node;
		}
		node = node->next;
	}
	return (lowest_node);
}
