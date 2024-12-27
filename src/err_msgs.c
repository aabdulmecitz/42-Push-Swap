/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:31:14 by aabdulmecit       #+#    #+#             */
/*   Updated: 2024/12/28 02:49:06 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    err(char *msg)
{
    ft_printf(RED "\n%s\n" RESET, msg);
}

void	exit_with_error(char *message)
{
	err("Error\n");
	ft_putstr_fd(message, 2);
	exit(-1);
}