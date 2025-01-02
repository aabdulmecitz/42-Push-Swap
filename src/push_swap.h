/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:42:29 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 20:57:54 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"

typedef struct s_stack
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	t_stack	*target_node;
	t_stack	*next;
	t_stack	*prev;
}	t_stack;

void	sa(t_stack **stack,  bool disable_print);
void	sb(t_stack **stack,  bool disable_print);
void	ra(t_stack **stack,  bool disable_print);
void	rb(t_stack **stack,  bool disable_print);
void	rra(t_stack **stack,  bool disable_print);
void	rrb(t_stack **stack,  bool disable_print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool disable_print);
void	pa(t_stack **stack_a, t_stack **stack_b, bool disable_print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool disable_print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool disable_print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool disable_print);

t_stack	init_a(int argc, char *argv[]);
t_stack	*get_last_node(t_stack *node);
t_stack	*init_stack_a(char **input);
char    **create_input(int argc, char **argv);
long	ft_atol(const char *str);
void    err(char *msg);
void    free_stack(t_stack *node);
void    free_inputs(char **input);
void	exit_with_error(char *message);
int		str_arr_size(char **input);
int		stack_len(t_stack **stack);

#endif