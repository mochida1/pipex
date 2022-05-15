/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 23:55:51 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (int argc, char *argv[], char *envp[])
{
	t_data *data;

	check_argc(argc);
	data = malloc (sizeof(t_data));
	if (!data)
		exit(1);
	init_data(data, argv, envp);

	char *args1[3] = {"ls", "-la", NULL}; //DELETAR execve("/bin/ls", {"ls", "-la", NULL}, envp)
	//char *args2[3] = {"grep", "file", NULL};

/*
	int i = 0;
	while (i < argc)
	{
		printf("ARG[%d]: >>%s<<\n", i, argv[i]);
		i++;
	}
*/

	create_pipe(data->pipe_fd);
	dup2(data->fd[0], data->pipe_fd[1]);
	data->child_pid[0] = create_child();
	if (!data->child_pid[0])
	{
	/* 	código para o child1 */
		exec_cmd1(args1, envp);
		exit(UTIL_NOT_FOUND); //if command is not found, gtfo of the forked process.
	}
	waitpid(data->child_pid[0], &data->status, 0); // wait for 1st child shit to be complete.

	data->child_pid[1] = create_child();
	if (!data->child_pid[1])
	{
	/* 	código para o child2 */
		exit(UTIL_NOT_FOUND); //if command is not found, gtfo of the forked process.
	}
	waitpid(data->child_pid[1], &data->status, 0); // wait for 2nd child shit to be complete.

	close(data->fd[0]);
	close(data->fd[1]);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]); // certifies all FD's are closed before finishing the program.
	return (0);
}
