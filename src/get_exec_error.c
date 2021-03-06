/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:26:14 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 16:36:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_exec_error(char *path, t_data *data, int process)
{
	if (!path)
		data->error_msg[process] = UTIL_NOT_FOUND;
	else if (access(path, X_OK))
		data->error_msg[process] = CANT_RUN;
	return (data->error_msg[process]);
}
