/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 14:53:48 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	init_data(t_data *data, char *argv[], char *envp[])
{
	data->fd[0] = open("infile", O_RDONLY);
	data->fd[1] = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	create_pipe(data->pipe_fd);
}
