/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:37 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/14 19:47:40 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

static void	swap(t_stack_node **first_node)
{
	if (!(*first_node) || !(*first_node)->next)
		return ;
	*first_node = (*first_node)->next;
	(*first_node)->prev->prev = *first_node;
	(*first_node)->prev->next = (*first_node)->next;
	if ((*first_node)->next)
		(*first_node)->next->prev = (*first_node)->prev;
	(*first_node)->next = (*first_node)->prev;
	(*first_node)->prev = NULL;
}

void	sa(t_stack_node **a, bool disable_print)
{
	swap(a);
	if (!disable_print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, bool disable_print)
{
	swap(b);
	if (!disable_print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool disable_print)
{
	swap(a);
	swap(b);
	if (!disable_print)
		ft_putstr_fd("ss\n", 1);
}
