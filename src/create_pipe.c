/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:45:20 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:28:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//Creates a pipe. On success, returns 0, on fail, exits with EXIT_FAILURE.
int	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	return (0);
}
