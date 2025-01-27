/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:46 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/27 17:58:24 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

int	check_input(char **input)
{
	int	zero_check;

	zero_check = 0;
	while (*input)
	{
		if (check_syntax(*input) == -1)
			return (-1);
		if (*input[0] == '0')
			zero_check++;
		input++;
	}
	if (zero_check >= 2)
		return (-1);
	return (0);
}

int	check_syntax(char *str)
{
	if (!str || !*str)
		return (0);
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (-1);
	if (*(str + 1) == '+' && *(str + 1) == '-' && !(*(str + 1) >= '0' && *(str
				+ 1) <= '9'))
		return (-1);
	if (*str == '0' && (*(str + 1) >= '0' && *(str + 1) <= '9'))
		return (-1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		str++;
	}
	return (1);
}

void	check_duplicate(t_stack_node **stack_a)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	if (!stack_a)
		return ;
	tmp1 = *stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2 && tmp2->nbr != 0)
		{
			if (tmp1->nbr == tmp2->nbr)
			{
				free_stack(*stack_a);
				exit_with_error();
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

char	**parse_input(int argc, char **argv)
{
	char	**result;
	int		i;

	result = NULL;
	if (argc == 1)
		result = ft_split(*argv, ' ');
	else
	{
		result = (char **)calloc(sizeof(char *), argc + 1);
		result[argc] = NULL;
	}
	if (argc > 1)
	{
		i = 0;
		while (argc-- && *argv)
		{
			result[i] = (char *)calloc(ft_strlen(*argv) + 1, sizeof(char));
			if (!result[i])
				return (result);
			ft_strlcpy(result[i], *argv, (int)ft_strlen(*argv) + 1);
			argv++;
			i++;
		}
	}
	return (result);
}

char	**create_input(int argc, char **argv)
{
	char	**input;
	int		i;

	argv++;
	argc--;
	input = NULL;
	input = parse_input(argc, argv);
	if (!input)
		exit_with_error();
	if (argc == 1)
		argc = str_arr_size(input);
	i = 0;
	while (argc)
	{
		if (check_syntax(input[i]) == -1)
			exit_with_error();
		i++;
		argc--;
	}
	return (input);
}
