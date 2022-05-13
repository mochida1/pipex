/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/13 16:13:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
contains data used in pipex's main function
'int status' shows waitpid status of last called instance.
*/
typedef struct s_data
{
	pid_t	child_pid[2];
	int		pipe_fd[2];
	int		status;
} t_data;

# define FILE_NOT_FOUND 126
# define UTIL_NOT_FOUND 127
