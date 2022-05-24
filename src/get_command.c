/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:25:03 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/24 13:18:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

char	**get_command(char **args, int index)
{
	char **ret;
	
	//make_splitting_easier(args[index]);
	ret = ft_split(args[index], ' ');
	return (ret);
}
