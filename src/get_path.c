/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:19 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 14:50:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*access_all_paths(char **all_paths)
{
	int		i;

	i = 0;
	while (all_paths[i])
	{
		if (!access(all_paths[i], F_OK))
		{
			if (!access(all_paths[i], X_OK))
				return (ft_strdup(all_paths[i]));
		}
		i++;
	}
	return (NULL);
}

static char	**cat_cmd_to_all_paths(char *cmd_arg, char **all_paths)
{
	int		i[3];
	char	*temp;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (all_paths[i[0]])
	{
		temp = malloc (sizeof (char) * (ft_strlen(cmd_arg)
					+ 2 + ft_strlen(all_paths[i[0]])));
		while (all_paths[i[0]][i[1]])
		{
			temp[i[1]] = all_paths[i[0]][i[1]];
			i[1]++;
		}
		temp[i[1]++] = '/';
		while (cmd_arg[i[2]])
			temp[i[1]++] = cmd_arg[i[2]++];
		temp[i[1]] = '\0';
		i[1] = 0;
		i[2] = 0;
		free(all_paths[i[0]]);
		all_paths[i[0]++] = temp;
	}
	return (all_paths);
}

static int	get_path_index_from_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P')
			if (envp[i][1] == 'A')
				if (envp[i][2] == 'T')
					if (envp[i][3] == 'H')
						if (envp[i][4] == '=')
							break ;
		i++;
	}
	if (envp[i])
		return (i);
	else
		return (-1);
}

char	*get_path(char *cmd_arg, char **envp)
{
	char	**all_paths;
	int		i;
	char	*path;

	i = get_path_index_from_envp (envp);
	if (1 < 0)
		perror("Error getting pah index from ENVP");
	all_paths = ft_split(envp[i] + 5, ':');
	all_paths = cat_cmd_to_all_paths(cmd_arg, all_paths);
	path = access_all_paths(all_paths);
	if (path)
	{
		i = 0;
		while (all_paths[i])
		{
			free(all_paths[i]);
			i++;
		}
		free(all_paths);
		return (path);
	}
	return (NULL);
}
