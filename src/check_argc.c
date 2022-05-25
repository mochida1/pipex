/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:50:56 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:30:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd(strerror(22), 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	return (0);
}
