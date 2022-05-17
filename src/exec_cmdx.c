/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/17 19:44:40 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	free_some_pointers(char **cmd_args, char *path)
{
	int i;

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
	char **cmd_args;
	char *path;

	cmd_args = get_command(data->args, 2); //0_pipex 1_infile 2_cmd1 3_cmd2 4_outfile //precisa de parsing interno.
	path = get_path(cmd_args[0], data->env_ptr); // "/bin/ls"

	close(data->pipe_fd[0]);
	dup2(data->fd[0], STDIN_FD);
	dup2(data->pipe_fd[1], STDOUT_FD);

	get_exec_error(path, data, 0); //aqui deveria testar o path para achar o que o CMD necessita, usando access() para testar todos os elementos de "PATH" em envp e concatenando-os com os nome do comando.

	execve(path, cmd_args, data->env_ptr);
	ft_putstr_fd("deu bosta no execve\n", 2);
	free_some_pointers(cmd_args, path);
	exit(127);
}

void	exec_cmd2(t_data *data)
{
	char **cmd_args;
	char *path = "/usr/bin/tr";
	close(data->pipe_fd[1]);

	cmd_args = get_command(data->args, 3);
	//path = get_path(cmd_args[0], data->env_ptr);


	dup2(data->pipe_fd[0], STDIN_FD);
	dup2(data->fd[1], STDOUT_FD);

	get_exec_error(path, data, 1);
	execve(path, cmd_args, data->env_ptr);
	ft_putstr_fd("deu bosta no execve2\n", 2);
	free_some_pointers(cmd_args, path);
	exit(127);
}
