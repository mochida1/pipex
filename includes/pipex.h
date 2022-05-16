/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/15 16:35:54 by hmochida         ###   ########.fr       */
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
void	exec_cmd1(char **args1, char *envp[]);
void	init_data(t_data *data, char *argv[], char *envp[]);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		check_argc (int argc);
char	**ft_split(char *s, char c);
