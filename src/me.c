/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 14:50:13 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

/* teste defuncionamento basico do pipe */
/* int main (int argc, char *argv[])
{
	int pipefd[2];
	char str[7];
	pipe(pipefd);

	if (!fork())
	{
		dup2(pipefd[1], 1);
		write (1, "HELLO\n", 6);
		close (pipefd[1]);
		return (0);
	}

	str[6] = '\0';
	read(pipefd[0], str, 6);
	printf ("%s", str);
} */

/* teste split */
/* int main (void)
{
	char *input = "cmd1 cu'string foda'";
	char **output = ft_split(input, ' ');
	int i = 0;
	while (output[i])
	{
		printf ("%s\n", output[i]);
		i++;
	}
	return (0);
} */

/* teste de funcionalidade do access */
/* int main (void)
{
	char *path = "teste";

	if (access(path, F_OK))
	{
		write (2, "F_OK\n", 5);
		exit (UTIL_NOT_FOUND);
	}
	else if (access(path, X_OK))
	{
		write (2, "X_OK\n", 5);
		exit (CANT_RUN);
	}
	else write (1, "ok\n", 3);
	return (0);
} */

char	*access_all_paths(char **all_paths)
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

static char **cat_cmd_to_all_paths(char *cmd_arg, char **all_paths)
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

static int get_path_index_from_envp (char **envp)
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

int main (int argc, char *argv[], char *envp[])
{
	/* test block, aqui para usar as variáveis*/
	printf("argc: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);
	/* end testblock */

	char **all_paths;
	int i;
	char *path;
	char *cmd_arg = "sudo";

	i = get_path_index_from_envp (envp);
	if (1 < 0)
			perror("deu bosta pegando o indice do path");

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
		// return (path);
		printf (">>%s<<", path);
	}


}

