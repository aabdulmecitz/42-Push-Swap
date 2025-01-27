/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:48:39 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/27 15:22:21 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../lib/libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	char			**input;

	input = NULL;
	if (argc == 1)
		return (-1);
	input = create_input(argc, argv);
	stack_a = init_stack_a(input);
	if (input)
		free_input(input);
	if (stack_a)
		check_duplicate(&stack_a);
	if (stack_a && stack_sorted(stack_a) <= 0)
		sort_stack(&stack_a);
	if (stack_a)
		free_stack(stack_a);
	return (0);
}

// Easiest way to run
// ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | ./checker_linux $ARG
// ARG=($(shuf -i 1-2000000 -n 100)); ./push_swap $ARG | ./checker $ARG
