/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:50:56 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/14 00:05:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	check_argc (int argc)
{
	if (argc != 5) //se pipex vier sem arguementos, fecha a porra toda.
	{
		ft_putstr_fd(strerror(22), 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	return (0);
}
