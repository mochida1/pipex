/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:50:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_data(t_data *data, char *argv[], char *envp[])
{
	data->error_msg[0] = 0;
	data->error_msg[1] = 0;
	data->args = argv;
	data->env_ptr = envp;
	data->fd[0] = open(argv[1], O_RDONLY);
	if (data->fd[0] < 0)
		data->error_msg[0] = GENERAL_ERROR;
	data->fd[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	create_pipe(data->pipe_fd);
}
