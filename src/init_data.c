/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 15:12:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	init_data(t_data *data, char *argv[])
{
	data->fd[0] = open(argv[1], O_RDONLY);
	if (data->fd[0] < 0)
		{
			free(data);
			ft_putstr_fd("INputFILE not found. :(");
			exit(1);
		}
	data->fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	create_pipe(data->pipe_fd);
}
