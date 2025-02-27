/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:15 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/14 19:47:17 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool disable_print)
{
	push(a, b);
	if (!disable_print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **b, t_stack_node **a, bool disable_print)
{
	push(b, a);
	if (!disable_print)
		ft_putstr_fd("pb\n", 1);
}
