/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:25:03 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/18 23:43:38 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

char	**get_command(char **args, int index)
{
	char **ret;
	/*
	ADICIONAR PARSING AQUI!!
	*/
	ret = ft_split(args[index], ' ');

	return (ret);
}
