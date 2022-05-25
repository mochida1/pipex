/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 16:22:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_some_pointers(char **cmd_args, char *path)
{
	int	i;

	i = 0;
	while (cmd_args[i])
	{
		free(cmd_args[i]);
		i++;
	}
	free (cmd_args);
	free (path);
}

void	exec_cmd1(t_data *data)
{
	char	**cmd_args;
	char	*path;
	int		exit_status;

	cmd_args = get_command(data->args, 2);
	path = get_path(cmd_args[0], data->env_ptr);
	close(data->pipe_fd[0]);
	dup2(data->fd[0], STDIN_FD);
	dup2(data->pipe_fd[1], STDOUT_FD);
	if (!get_exec_error(path, data, 0))
		execve(path, cmd_args, data->env_ptr);
	print_error(data->error_msg, 0);
	exit_status = data->error_msg[0];
	free_some_pointers(cmd_args, path);
	free(data);
	exit(exit_status);
}

void	exec_cmd2(t_data *data)
{
	char	**cmd_args;
	char	*path;
	int		exit_status;

	close(data->pipe_fd[1]);
	cmd_args = get_command(data->args, 3);
	path = get_path(cmd_args[0], data->env_ptr);
	dup2(data->pipe_fd[0], STDIN_FD);
	dup2(data->fd[1], STDOUT_FD);
	if (!get_exec_error(path, data, 1))
		execve(path, cmd_args, data->env_ptr);
	print_error(data->error_msg, 1);
	exit_status = data->error_msg[1];
	free_some_pointers(cmd_args, path);
	free(data);
	exit(exit_status);
}
