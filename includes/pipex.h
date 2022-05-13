/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/12 18:21:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h> // pipe(), exceve(), dup(), dup2(), access(), fork(), unlink()
# include <fcntl.h> // open(), close(),
# include <stdlib.h> //malloc(), free(), exit(),
# include <stdio.h> // perror()
# include <string.h> // strerror()
# include <sys/wait.h> //wait(), waitpid(),


# include "../includes/defines.h"

int		create_pipe(int pipe_fd[2]);
pid_t	create_child(void);
