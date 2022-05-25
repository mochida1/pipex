/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 15:18:22 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
/*
contains data used in pipex's main function
'int status' shows waitpid status of last called instance.
*/
typedef struct s_data
{
	pid_t	child_pid[2];
	int		pipe_fd[2];
	int		fd[2];
	int		status;
	int		error_msg[2];
	char	**args;
	char	**env_ptr;
} t_data;

/* MAGIC NUMBERS */

# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2


/* EXIT STATUS */

# define GENERAL_ERROR 1
# define BAD_BASH 2
# define CANT_RUN 126
# define UTIL_NOT_FOUND 127

#endif
