/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:09:19 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/17 16:43:33 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

char	*get_path(char *cmd_arg, char **envp)
{
	/* aqui vêm os access() */
	if (*cmd_arg) //deletar
		write(1, "do nothing", 0); //deletar
	else if (envp) //deletar
		write(1, "do nothing", 0); //deletar

	return ("/bin/cat");
}
