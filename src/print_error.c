/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:37:43 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:29:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(int *error_msg, int process)
{
	if (error_msg[process] == GENERAL_ERROR)
		ft_putstr_fd("Something generically bad happened :(\n", 2);
	else if (error_msg[process] == BAD_BASH)
		ft_putstr_fd("Something generically bad happened :(\n", 2);
	else if (error_msg[process] == CANT_RUN)
		ft_putstr_fd("WHY U NO HAVE PARMESAN? >:(\n", 2);
	else if (error_msg[process] == UTIL_NOT_FOUND)
		ft_putstr_fd("Lost my glasses, can't find it\n", 2);
	else
		ft_putstr_fd("Something really wrong happened.\n", 2);
}
