/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:42:29 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/28 03:10:41 by aozkaya          ###   ########.fr       */
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
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack;

void	sa(t_stack **stack, int msg);
void	sb(t_stack **stack, int msg);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack, int msg);
void	rb(t_stack **stack, int msg);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack, int msg);
void	rrb(t_stack **stack, int msg);
void	rrr(t_stack **stack_a, t_stack **stack_b);

t_stack init_a(int argc, char *argv[]);
void    err(char *msg);
void	exit_with_error(char *message);
int	str_arr_size(char **input);
long	ft_atol(const char *str);
t_stack	*init_stack_a(char **input);



#endif