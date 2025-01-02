/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:13:31 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 21:12:07 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rrot(t_stack **first_node)
{
    t_stack	*last_node;
    if (!(*first_node) || !(*first_node)->next)
        return;
    last_node = get_last_node(*first_node);
    last_node->next = *first_node;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    *first_node = last_node;
    last_node->next->prev = last_node;
}

void	rra(t_stack **stack, bool disable_print)
{
    rrot(stack);
    if (!disable_print)
        ft_printf("rra");
}

void	rrb(t_stack **stack, bool disable_print)
{
    rrot(stack);
    if (!disable_print)
        ft_printf("rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool disable_print)
{
    rrot(stack_a);
    rrot(stack_b);
    if (!disable_print)
        ft_printf("rrr");
}