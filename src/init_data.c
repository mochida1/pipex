/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:58:55 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 22:22:14 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	init_data(t_data *data, char *argv[], char *envp[])
{

	printf("usando argv. %s\n", argv[0]);
	data->envp = envp;
	//data->args = get_args(argv);
	data->fd[0] = open("infile", O_RDONLY);
	data->fd[1] = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
}
