/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/12 18:12:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (int argc, char *argv[])
{
	pid_t	child_pid[2];
	int		pipe_fd[2];
	int		status; //shows waitpid status of last called instance.

	create_pipe(pipe_fd);
	child_pid[0] = create_child();
	/*
	código para o child1
	*/
	waitpid(child_pid[0], &status, 0) // wait for 1st child shit to be complete.

	child_pid[1] = create_child();
	/*
	código para o child2
	*/
	waitpid(child_pid[1], &status, 0) // wait for 2nd child shit to be complete.

	close(pipe_fd[0]);
	close(pipe_fd[1]); // certifies all FD's are closed before finishing the program.
	return (0);
}
