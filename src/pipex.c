/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 15:38:18 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (int argc, char *argv[])
{
	t_data *data;
	data = malloc (sizeof(t_data));

	int i = 0;
	while (i < argc)
	{
		printf("ARG[%d]: >>%s<<\n", i, argv[i]);
		i++;
	}

	create_pipe(data->pipe_fd);
	data->child_pid[0] = create_child();
	if (!data->child_pid[0])
	{
		/*child1 vai abrir
	/* 	código para o child1 */
		printf ("data->child_pid[0] = %d ;\n", data->child_pid[0]);
		printf ("this is child 1\n");
		exit(UTIL_NOT_FOUND);
	}

	waitpid(data->child_pid[0], &data->status, 0); // wait for 1st child shit to be complete.

	data->child_pid[1] = create_child();
	if (!data->child_pid[1])
	{
	/* 	código para o child1 */
		printf ("data->child_pid[1] = %d ;\n", data->child_pid[1]);
		printf ("this is child 2\n");
		exit(UTIL_NOT_FOUND);
	}
	waitpid(data->child_pid[1], &data->status, 0); // wait for 2nd child shit to be complete.

	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]); // certifies all FD's are closed before finishing the program.
	return (0);
}
