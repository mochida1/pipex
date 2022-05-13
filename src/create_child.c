/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:02:06 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/12 18:26:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

//creates a child from fork. Returns child PID. If fork fails, exits with EXIT_FAILURE
pid_t	create_child(void)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("child");
		exit(EXIT_FAILURE);
	}
	return (child_pid);
}
