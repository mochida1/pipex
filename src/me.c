/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 12:34:57 by hmochida         ###   ########.fr       */
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

int main (int argc, char *argv[], char *envp[])
{
	char **all_paths;
	int i = 0;

	printf("argc: %d\n", argc);
	printf("argv[0]: %s\n", argv[0]);

	while (envp[i])
	{
		if (envp[i][0] == 'P')
			if (envp[i][1] == 'A')
				if (envp[i][2] == 'T')
					if (envp[i][3] == 'H')
						if (envp[i][4] == '=')
							break;
		// printf ("%s\n", envp[i]);
		i++;
	}
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		printf("%s\n", all_paths[i]);
		i++;
	}
	return (0);
}

