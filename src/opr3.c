/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:01:43 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 21:05:05 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void rot(t_stack **first_node)
{
    t_stack *last_node;

    if (!(*first_node) || !(*first_node)->next)
        return;
    last_node = get_last_node(*first_node);
    last_node->next = *first_node;
    *first_node = (*first_node)->next;
    (*first_node)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void	ra(t_stack **stack, bool disable_print)
{
    rot(stack);
    if (!disable_print)
        ft_printf("ra");
}

void	rb(t_stack **stack, bool disable_print)
{
    rot(stack);
    if (!disable_print)
        ft_printf("rb");    
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool disable_print)
{
    rot(stack_a);
    rot(stack_b);
    if (!disable_print)
        ft_printf("rr");    
}

