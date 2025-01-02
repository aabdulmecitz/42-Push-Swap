/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:00:42 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 20:48:41 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static put(t_stack **dst, t_stack **src)
{
    t_stack *tmp;
    if (!(*src))
        return;
    tmp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    tmp->prev = NULL;
    if (!*dst)
    {
        *dst = tmp;
        tmp->next = NULL;
    }
    else
    {
        tmp->next = *dst;
        tmp->next->prev = tmp;
        *dst = tmp;
    }
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool disable_print)
{
    put(stack_a, stack_b);
    if (!disable_print)
        ft_printf("pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b, bool disable_print)
{
    put(stack_b, stack_a);
    if (!disable_print)
        ft_printf("pb");

}


