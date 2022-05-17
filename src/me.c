/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 17:55:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

// int main (int argc, char *argv[])
// {
// 	int pipefd[2];
// 	char str[7];
// 	pipe(pipefd);

// 	if (!fork())
// 	{
// 		dup2(pipefd[1], 1);
// 		write (1, "HELLO\n", 6);
// 		close (pipefd[1]);
// 		return (0);
// 	}

// 	str[6] = '\0';
// 	read(pipefd[0], str, 6);
// 	printf ("%s", str);
// }

// int main (void)
// {
// 	char *input = "cmd1 cu'string foda'";
// 	char **output = ft_split(input, ' ');
// 	int i = 0;
// 	while (output[i])
// 	{
// 		printf ("%s\n", output[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int main (void)
// {
// 	char *path = "teste";

// 	if (access(path, F_OK))
// 	{
// 		write (2, "F_OK\n", 5);
// 		exit (UTIL_NOT_FOUND);
// 	}
// 	else if (access(path, X_OK))
// 	{
// 		write (2, "X_OK\n", 5);
// 		exit (CANT_RUN);
// 	}
// 	else write (1, "ok\n", 3);
// 	return (0);
// }
