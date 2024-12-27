/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:21:38 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/28 02:47:44 by aozkaya          ###   ########.fr       */
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

int	str_arr_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
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