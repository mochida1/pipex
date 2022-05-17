/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:26:14 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 20:41:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	exec_error(char *path, t_data *data, int process)
{
	if (access(path, F_OK))
		data->error_msg[process] = FILE_NOT_FOUND;
	else if (access(path, X_OK))
		data->error_msg[process] = NO_PERMISSION;
}
