/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:51 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/27 17:53:29 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	error_message(void)
{
	ft_putstr_fd("Error\n", 2);
}
