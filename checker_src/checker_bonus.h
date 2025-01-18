/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:16:10 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/18 19:16:12 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../inc/push_swap.h"
# include <stdio.h>

t_stack_node	*ft_lstdup(t_stack_node *stack);
int				is_stack_sorted(t_stack_node **stack_a);
int				check_line(char *line);
void			sort_by_input(t_stack_node **stack_a);
void			process_the_input(char *input, t_stack_node **stack_a,
					t_stack_node **stack_b);
int				is_b_empty(t_stack_node **stack_b);

#endif