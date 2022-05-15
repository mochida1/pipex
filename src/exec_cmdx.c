/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 22:20:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void exec_cmd1(char **args1, char *envp[])
{
	char *path = "/bin/ls";

	if (access(path, F_OK))
	{
		//data->error_msg[0] = FILE_NOT_FOUND;
		exit (UTIL_NOT_FOUND);
	}
	else if (access(path, X_OK))
	{
		//data->error_msg[0] = NO_PERMISSION;
		exit (CANT_RUN);
	}
	if (execve(path, args1, envp))
		printf("deu bosta no execve\n"); //remover depois
}
