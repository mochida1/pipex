/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmdx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:30 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 19:16:13 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void exec_cmd1(char **args1, char *envp[])
{
    char    *bin = "/bin/ls";
	int z = 0;
	while (envp[z])
	{
		printf("%s\n", envp[z]);
		z++;
	}

	if (execve(bin, args1, envp))
		printf("deu bosta no execve\n");
}
