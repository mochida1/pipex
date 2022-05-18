/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:19 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 14:06:37 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**cat_cmd_to_all_paths(char *cmd_arg, char **all_paths)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	char	*temp;

	i = 0;
	j = 0;
	k = 0;
	while (all_paths[i])
	{
		temp = malloc (sizeof (char) * (ft_strlen(cmd_arg) + 2 + ft_strlen(all_paths[i])));
		while (all_paths[i][j])
		{
			temp[j] = all_paths[i][j];
			j++;
		}
		temp[j++] = '/';
		while (cmd_arg[k])
			temp[j++] = cmd_arg[k++];
		temp[j] = '\0';
		j = 0;
		k = 0;
		free(all_paths[i]);
		all_paths[i++] = temp;
	}
	return(all_paths);
}

static int get_path_index_from_envp (char *cmd_arg, char **envp)
{
	int i;
	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P')
			if (envp[i][1] == 'A')
				if (envp[i][2] == 'T')
					if (envp[i][3] == 'H')
						if (envp[i][4] == '=')
							break;
		i++;
	}
	if (envp[i])
		return(i);
	else
		return(-1);
}

char	*get_path(char *cmd_arg, char **envp)
{
	/* aqui vêm os access() */
	if (*cmd_arg) //deletar
		write(1, "do nothing", 0); //deletar
	else if (envp) //deletar
		write(1, "do nothing", 0); //deletar

	return ("/bin/cat");
}
