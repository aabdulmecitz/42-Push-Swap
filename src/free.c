/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:12:51 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 18:18:24 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_inputs(char **input)
{
    int i;

    while (input[i])
    {
        free(input[i]);
        i++;
    }
    if (input)
        free(input);    
}

void    free_stack(t_stack *node)
{
    t_stack *tmp;

    while (node)
    {
        tmp = tmp->next;
        free(node);
        node = tmp;    
    }
}