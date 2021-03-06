/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:40:02 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/25 19:59:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../includes/defines.h"

int		create_pipe(int pipe_fd[2]);
pid_t	create_child(void);
void	exec_cmd1(t_data *data);
void	exec_cmd2(t_data *data);
void	init_data(t_data *data, char *argv[], char *envp[]);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
int		check_argc(int argc);
char	**ft_split(char *s, char c);
char	**get_command(char **args, int index);
char	*get_path(char *cmd_arg, char **envp);
int		get_exec_error(char *path, t_data *data, int process);
void	free_some_pointers(char **cmd_args, char *path);
char	*ft_strdup(const char *s1);
char	*make_splitting_easier(char *args);
char	**unmake_splitting_easier(char **ret);
void	print_error(int *error_msg, int process);
char	**trim_all_quote_pairs(char **ret);

#endif
