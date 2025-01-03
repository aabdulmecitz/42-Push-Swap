/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:39:02 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 18:31:00 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char const *argv[])
{
    t_stack *stack_a;
    char    **input;
    
    input = NULL;
    if (argc == 1)
        return(-1);
    input = create_input(argc, argv);
    stack_a = init_stack_a(input);
    if (input)
        free_inputs(input);
    if (stack_a)
        check_dup(&stack_a);
    
    // here for sort algorithm
    
    if (stack_a)
        free(stack_a);
    return 0;
}
