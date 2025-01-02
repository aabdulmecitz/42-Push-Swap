/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:58:34 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 19:11:22 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **first_node)
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

void	sa(t_stack **stack, bool disable_print)
{
    swap(stack);
    if (!disable_print)
        ft_printf("sa");
    
}

void	sb(t_stack **stack, bool disable_print)
{
    swap(stack);
    if (!disable_print)
        ft_printf("sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool disable_print)
{
    swap(stack_a);
    swap(stack_b);
    if (!disable_print)
        ft_printf("ss");
}
