/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:05 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/17 15:37:10 by hmochida         ###   ########.fr       */
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
	int		fd[2];
	int		status;
	int		*error_msg[2];
	char	**args;
	char	**env_ptr;
} t_data;

/* MAGIC NUMBERS */
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2


/* EXIT STATUS */

# define CANT_RUN 126
# define UTIL_NOT_FOUND 127

/* ERRORS */

# define FILE_NOT_FOUND 1
# define NO_PERMISSION 2
