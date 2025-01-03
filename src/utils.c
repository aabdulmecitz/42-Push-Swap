/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:21:38 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/02 20:55:53 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **parse_input(int argc, char **argv)
{
    char **res;
    int i;

    res = NULL;
    if (argc == 1)
        res = ft_split(*argv, ' ');
    else
    {
        res = calloc(sizeof(char *), argc + 1);
        res[argc] = NULL;
    }
    if (argc > 1)
    {
        i = 0;
        while (argc-- && *argv)
        {
            res[i] = (char *)calloc((ft_strlen(*argv) + 1), sizeof(char));
            if (!res[i])
                return(res);
            ft_strlcpy(res[i], *argv, (int)ft_strlen(*argv) + 1);
            argv++;
            i++;
        }
    }
    return (res);
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

char    **create_input(int argc, char **argv)
{
    char	**input;
	int		i;

	argv++;
	argc--;
	input = NULL;
	input = parse_input(argc, argv);
	if (!input)
		exit_with_error("error while creating input!\n");
	if (argc == 1)
		argc = str_arr_size(input);
	i = 0;
	while (argc)
	{
		if (check_syntax(input[i]) == -1)
			exit_with_error("bad input: error in check_syntax() func.\n");
		i++;
		argc--;
	}
	return (input);
}

void	check_dup(t_stack **stack)
{
	t_stack *tmp1;
	t_stack *tmp2;

	if (!stack)
		return;
	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2 && tmp2->nbr != 0)
		{
			if (tmp1->nbr == tmp2->nbr)
			{
				free_stack(*stack);
				exit_with_error("error: duplicate number in stack!\n");;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	stack_len(t_stack **stack)
{
	t_stack *tmp;
	int		i;

	i = 0;
	if (!stack)
		return;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*get_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return node;
}

