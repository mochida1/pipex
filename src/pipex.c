/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:10 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 14:55:26 by hmochida         ###   ########.fr       */
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
	init_data(data, argv);

	data->child_pid[0] = create_child();
	if (!data->child_pid[0])
	{
	/* 	código para o child1 */
	}
	waitpid(data->child_pid[0], &data->status, 0); // wait for 1st child shit to be complete.

	data->child_pid[1] = create_child();
	if (!data->child_pid[1])
	{
	/* 	código para o child2 */
	}
	waitpid(data->child_pid[1], &data->status, 0); // wait for 2nd child shit to be complete.
	return (0);
}
