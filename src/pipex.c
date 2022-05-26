/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 23:27:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	int		exit_status;

	check_argc(argc);
	data = malloc (sizeof(t_data));
	if (!data)
		exit(1);
	init_data(data, argv, envp);
	data->child_pid[0] = create_child();
	if (!data->child_pid[0])
		exec_cmd1(data);
	waitpid(data->child_pid[0], &data->pid_status, 0);
	close(data->fd[0]);
	close(data->pipe_fd[1]);
	data->child_pid[1] = create_child();
	if (!data->child_pid[1])
		exec_cmd2(data);
	waitpid(data->child_pid[1], &data->pid_status, 0);
	close(data->fd[1]);
	close(data->pipe_fd[0]);
	exit_status = (((data->pid_status) & 0xff00) >> 8);
	free(data);
	return (exit_status);
}
