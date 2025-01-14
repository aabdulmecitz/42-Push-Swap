/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:08 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/14 19:48:10 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	if (input)
		free(input);
}

void	free_stack(t_stack_node *node)
{
	t_stack_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
