/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/17 15:44:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	exec_cmd1(t_data *data)
{
	char **cmd_args;
	char *path;

	cmd_args = get_command(data->args, 2); //0_pipex 1_infile 2_cmd1 3_cmd2 4_outfile
	path = get_path(cmd_args[0], data->env_ptr); // "/bin/ls"

	close(data->pipe_fd[0]);
	dup2(STDIN_FD, data->fd[0]);
	dups(data->pipe_fd[1], STDOUT_FD);

	get_exec_error(path); //aqui deveria testar o path para achar o que o CMD necessita, usando access() para testar todos os elementos de "PATH" em envp e concatenando-os com os nome do comando.
	if (execve(path, cmd_args, envp))
		ft_putstr_fd("deu bosta no execve\n", 2);
}
