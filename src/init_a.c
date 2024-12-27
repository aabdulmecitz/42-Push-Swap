/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:07:31 by aozkaya           #+#    #+#             */
/*   Updated: 2024/12/28 02:21:01 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_num(char *str)
{
    int i;
    
    i = 0;
    if (!str)
        return 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (ft_isdigit(str[i]))
        i++;
    if (i == ft_strlen(str))
        return 1;
    return 0;
}

t_stack init_a(int argc, char *argv[])
{
    t_stack *res;
    char    **tmp;
    int     i;
    int     arg;
    
    arg = 1;
    res = NULL;
    while (arg < argc)
    {
        i = 0;
        tmp = ft_split(argv[arg], ' ');
        while (tmp[i])
        {
            s_add_back(&res, s_new(ft_atoi(tmp[i])));
            free(tmp[i]);
        }
        free(i);
        arg++;
    }
}
