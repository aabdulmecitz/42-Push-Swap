/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozkaya <aozkaya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:47:51 by aozkaya           #+#    #+#             */
/*   Updated: 2025/01/24 20:04:45 by aozkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include "../../lib/libft/libft.h"

void	exit_with_error()
{
	ft_putstr_fd("Error", 2);
	exit(-1);
}

void	error_message()
{
	ft_putstr_fd("Error", 2);
}
