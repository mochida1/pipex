/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:33:49 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/16 14:42:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int main (int argc, char *argv[])
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
}
