/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdulmecitz <aabdulmecitz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:29:23 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/23 18:41:03 by aabdulmecit      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_args(int argc, char **argv)
{
    int i;
    i = 1;
    while (i < argc)
    {
        check_arg(argv[i]);
        i++;
    }
    
}

void check_arg(char *arg)
{
    int     i;
    int     j;
    char    **splited;

    i = 0;
    splited = ft_split(arg, ' ');
    while (splited[i])
    {
        j = 0;
        if (!ft_isdigit(splited[i][0]) || !ft_isdigit(splited[i][ft_strlen(splited[i])] - 1))
            err("All of arguments must be start with digit and end with digit");
        while (splited[i][j])
        {
            if (!ft_isdigit(splited[i][j]))
                err("Arguments include just digit.");
            j++;
        }
        i++;
    }
}

void   check_arg_fl (char **splited)
{
    int i;

    i = 0;
    
}