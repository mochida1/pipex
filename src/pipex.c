/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:52:03 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	check_argc(argc);
	data = malloc (sizeof(t_data));
	if (!data)
		exit(1);
	init_data(data, argv, envp);
	data->child_pid[0] = create_child();
	if (!data->child_pid[0])
		exec_cmd1(data);
	waitpid(data->child_pid[0], &data->status, 0);
	close(data->fd[0]);
	close(data->pipe_fd[1]);
	data->child_pid[1] = create_child();
	if (!data->child_pid[1])
		exec_cmd2(data);
	waitpid(data->child_pid[1], &data->status, 0);
	close(data->fd[1]);
	close(data->pipe_fd[0]);
	return (0);
}
